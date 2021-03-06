// <bits/cppunitx/exception.h>
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

#ifndef _CPPUNITX_EXCEPTION_H
#define _CPPUNITX_EXCEPTION_H 1

#include <stdexcept>
#include <string>
#include <bits/cppunitx.h>

namespace cppunitx
{
    class _CPPUNITX_PUBLIC AssertionFailedException: public std::runtime_error
    {
    public:

        // Constructors.

        explicit AssertionFailedException(const char *message);

        explicit AssertionFailedException(const std::string &message);

        AssertionFailedException(const AssertionFailedException &);


        // Destructor.

        /// Destructs an `AssertionError` object.
        ///
        /// This destructor is defined out of line so that this class can be
        /// provided by a shared library.
        ~AssertionFailedException() noexcept override;


        // Assignment operators.

        AssertionFailedException &operator =(const AssertionFailedException &);
    };
}

#endif
