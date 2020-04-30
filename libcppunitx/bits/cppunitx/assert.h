// <bits/cppunitx/assert.h>
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

#ifndef _CPPUNITX_ASSERT_H
#define _CPPUNITX_ASSERT_H 1

#include <bits/cppunitx.h>

#include <memory>
#include <cstdint>

namespace cppunitx
{
    namespace assertion
    {
        _CPPUNITX_PUBLIC void assertNull(const volatile void *ptr,
            const char *message = nullptr);

        template<class T>
        inline void assertNull(const std::unique_ptr<T> &ptr,
            const char *message = nullptr)
        {
            assertNull(ptr.get(), message);
        }

        template<class T>
        inline void assertNull(const std::shared_ptr<T> &ptr,
            const char *message = nullptr)
        {
            assertNull(ptr.get(), message);
        }

        _CPPUNITX_PUBLIC void assertNotNull(const volatile void *ptr,
            const char *message = nullptr);

        template<class T>
        inline void assertNotNull(const std::unique_ptr<T> &ptr,
            const char *message = nullptr)
        {
            assertNotNull(ptr.get(), message);
        }

        template<class T>
        inline void assertNotNull(const std::shared_ptr<T> &ptr,
            const char *message = nullptr)
        {
            assertNotNull(ptr.get(), message);
        }

        _CPPUNITX_PUBLIC void assertEquals(std::intmax_t expected,
            std::intmax_t actual, const char *message);

        _CPPUNITX_PUBLIC void assertEquals(std::uintmax_t expected,
            std::uintmax_t actual, const char *message);
    }
}

#endif
