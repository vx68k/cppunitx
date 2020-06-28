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
#include <memory>
#include <cstring>
#include <ltdl.h>

namespace ltdl
{
    /// Helper object for 'lt_dlinit' and 'lt_dlexit'.
    class libltdl
    {
    private:
        struct init
        {
            init()
            {
                LTDL_SET_PRELOADED_SYMBOLS();
            }
        };

    public:
        /// Initializes the libltdl.
        libltdl()
        {
            static init once {};

            int result = lt_dlinit();
            if (result != 0) {
                throw std::runtime_error(lt_dlerror());
            }
        }

        libltdl(const libltdl &) = delete;

        void operator =(const libltdl &) = delete;

    public:
        ~libltdl()
        {
            int result = lt_dlexit();
            if (result != 0) {
                // This shall not happen.
                std::terminate();
            }
        }
    };

    /// Helper object for 'lt_dlsetsearchpath'.
    class library_path
    {
    private:
        libltdl _lib {};
        std::unique_ptr<char []> _original_path;

    public:
        explicit library_path(const char *const path)
        {
            auto current_path = lt_dlgetsearchpath();
            if (current_path != nullptr) {
                auto n = std::strlen(current_path) + 1;
                _original_path.reset(new char [n]);
                std::memcpy(_original_path.get(), current_path, n);
            }
            int result = lt_dlsetsearchpath(path);
            if (result != 0) {
                throw std::runtime_error(lt_dlerror());
            }
        }

        library_path(const library_path &) = delete;

        void operator =(const library_path &) = delete;

    public:
        ~library_path()
        {
            int result = lt_dlsetsearchpath(_original_path.get());
            if (result != 0) {
                // This shall not happen.
                std::terminate();
            }
        }
    };

    /// Helper object for 'lt_dlopen' and 'lt_dlclose'.
    class module
    {
    private:
        libltdl _lib {};
        lt_dlhandle _handle {};

    public:
        static std::unique_ptr<module> open(const char *const name)
        {
            return std::unique_ptr<module>(new module(name));
        }

    public:
        explicit module(const char *const name)
            : _handle {lt_dlopen(name)}
        {
            if (_handle == 0) {
                throw std::runtime_error(
                    std::string(name) + ": " + lt_dlerror());
            }
        }

        module(const module &) = delete;

        void operator =(const module &) = delete;

    public:
        ~module()
        {
            int result = lt_dlclose(_handle);
            if (result != 0) {
                // This shall not happen.
                std::terminate();
            }
        }

    public:
        lt_dlhandle handle() const noexcept
        {
            return _handle;
        }

        operator lt_dlhandle() const noexcept
        {
            return handle();
        }
    };
}

#endif
