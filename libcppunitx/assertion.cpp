// assertion.cpp
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

#define _CPPUNITX_ASSERT_IMPLEMENTATION 1
#include <bits/cppunitx/assert.h>

#include <cppunitx/exception>

using namespace cppunitx;

void assertion::fail(const char *message)
{
    std::string description = "Assertion failed";
    if (message != nullptr) {
        description.append(": ");
        description.append(message);
    }
    throw AssertionFailedException(description);
}

void assertion::assertNull(const volatile void *ptr, const char *message)
{
    if (ptr != nullptr) {
        fail("Pointer is not null");
    }
}

void assertion::assertNotNull(const volatile void *ptr, const char *message)
{
    if (ptr == nullptr) {
        fail("Pointer is null");
    }
}
