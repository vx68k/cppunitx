// <bits/cppunitx/exception.h>
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

#ifndef _CPPUNITX_EXCEPTION_H
#define _CPPUNITX_EXCEPTION_H 1

#include <stdexcept>
#include <string>
#include <bits/cppunitx.h>

namespace cppunitx
{
    class _CPPUNITX_PUBLIC AssertionError : public std::runtime_error
    {
        using inherited = runtime_error;

    public:
        explicit AssertionError(const char *message)
            : inherited {message}
        {
        }

        explicit AssertionError(const std::string &message)
            : inherited {message}
        {
        }
    };
}

#endif
