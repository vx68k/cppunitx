// module.cpp
// Copyright (C) 2020 Kaz Nishimura
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

#include "module.h"

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

    private:
        std::string _dlname;

    public:
        void load(const char *const name)
        {
            auto &&length = std::strlen(name);
            if (length >= 3 && std::strcmp(name + length - 3, ".la") == 0) {
                std::ifstream input {name};
                if (input) {
                    std::string line;
                    while (std::getline(input, line)) {
                        std::smatch match;
                        if (std::regex_match(line, match, DLNAME)) {
                            _dlname = match.str(1);
                        }
                    }
                }
            }
        }

    public:
        const std::string &dlname() const
        {
            return _dlname;
        }
    };

    const std::regex ltlibrary_loader::DLNAME {"^dlname='(.*)'"};
}

void module::open(const char *const name)
{
    close();

    ltlibrary_loader la;
    la.load(name);

    std::string dlname = la.dlname();
    if (dlname.empty()) {
        dlname.assign(name);
    }
    _native_handle = dlopen(dlname.c_str(), RTLD_LAZY);
}

void module::close()
{
    native_handle_type handle = nullptr;
    std::swap(_native_handle, handle);
    if (handle != nullptr) {
        dlclose(handle);
    }
}

void *module::sym(const char *symbol)
{
    return dlsym(_native_handle, symbol);
}
