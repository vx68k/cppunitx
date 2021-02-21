// module_loader.cpp
// Copyright (C) 2020-2021 Kaz Nishimura
//
// This program is free software: you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by the Free
// Software Foundation, either version 3 of the License, or (at your option)
// any later version.
//
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
// FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
// more details.
//
// You should have received a copy of the GNU General Public License along with
// this program.  If not, see <http://www.gnu.org/licenses/>.
//
// SPDX-License-Identifier: GPL-3.0-or-later

#if HAVE_CONFIG_H
#include <config.h>
#endif

#include "module_loader.h"

#if HAVE_DLFCN_H
#include <dlfcn.h>
#endif

#include <fstream>
#include <regex>
#include <string>
#include <cstring>

namespace
{
    class ltlibrary_loader
    {
    private:

        static const std::regex DLNAME;

        static const std::regex INSTALLED;

        std::string _dlname;

        std::string _installed;

    public:

        const std::string &dlname() const
        {
            return _dlname;
        }

        void load(const char *const name)
        {
            auto &&length = std::strlen(name);
            if (length >= 3 && std::strcmp(name + length - 3, ".la") == 0) {
                std::ifstream input {name};
                load(input);

                if (!_dlname.empty()) {
                    std::string pathname = name;

                    auto &&sep = pathname.rfind('/');
                    if (sep == std::string::npos) {
                        pathname.assign("./");
                    }
                    else {
                        pathname.resize(sep + 1);
                    }
                    if (_installed == "no") {
                        pathname.append(LT_OBJDIR);
                    }
                    pathname.append(_dlname);

                    _dlname = std::move(pathname);
                }
            }
        }

    protected:

        void load(std::istream &input)
        {
            if (input) {
                std::string line;
                while (std::getline(input, line)) {
                    std::smatch match;
                    if (std::regex_match(line, match, DLNAME)) {
                        _dlname = match.str(1);
                    }
                    else if (std::regex_match(line, match, INSTALLED)) {
                        _installed = match.str(1);
                    }
                }
            }
        }
    };

    const std::regex ltlibrary_loader::DLNAME {"^dlname='(.*)'"};

    const std::regex ltlibrary_loader::INSTALLED {"^installed=([^ ]*)"};
}


auto module::open(const char *const name) -> native_handle_type
{
#if HAVE_DLFCN_H
    return dlopen(name, RTLD_LAZY);
#else
    return nullptr;
#endif
}

void module::close()
{
#if HAVE_DLFCN_H
    using std::swap;
    native_handle_type handle = nullptr;
    swap(_native_handle, handle);
    if (handle != nullptr) {
        dlclose(handle);
    }
#endif
}

void *module::sym(const char *symbol)
{
#if HAVE_DLFCN_H
    return dlsym(_native_handle, symbol);
#else
    return nullptr;
#endif
}


auto ltmodule::open(const char *const name) -> native_handle_type
{
    ltlibrary_loader loader {};
    loader.load(name);

    auto &&dlname = loader.dlname();
    if (!dlname.empty()) {
        return module::open(dlname.c_str());
    }
    return module::open(name);
}
