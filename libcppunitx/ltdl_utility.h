// ltdl_utility.h
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

#ifndef LTDL_UTILITY_H
#define LTDL_UTILITY_H 1

#include <stdexcept>
#include <cstring>
#include <ltdl.h>

namespace ltdl
{
    /// Helper object for 'lt_dlinit' and 'lt_dlexit'.
    struct libltdl
    {
        libltdl()
        {
            int result = lt_dlinit();
            if (result != 0) {
                throw std::runtime_error(lt_dlerror());
            }
        }

        ~libltdl()
        {
            int result = lt_dlexit();
            if (result != 0) {
                // Destructors cannot throw exceptions.
                std::fprintf(stderr, "'%s\n", lt_dlerror());
            }
        }
    };

    struct library_path
    {
        libltdl lib;
        const char *old_path;

        explicit library_path(const char *const path)
            : old_path {lt_dlgetsearchpath()}
        {
            if (old_path != nullptr) {
                auto copy = new char [std::strlen(old_path) + 1];
                std::strcpy(copy, old_path);
                old_path = copy;
            }
            lt_dlsetsearchpath(path);
        }

        ~library_path()
        {
            lt_dlsetsearchpath(old_path);
            delete [] old_path;
        }
    };

    /// Helper object for 'lt_dlopen' and 'lt_dlclose'.
    struct module
    {
        libltdl lib;
        lt_dlhandle handle;

        explicit module(const char *const name)
            : handle {lt_dlopen(name)}
        {
            if (handle == 0) {
                throw std::runtime_error(
                    std::string(name) + ": " + lt_dlerror());
            }
        }

        ~module()
        {
            int result = lt_dlclose(handle);
            if (result != 0) {
                // Destructors cannot throw exceptions.
                std::fprintf(stderr, "%s\n", lt_dlerror());
            }
        }
    };
}

#endif
