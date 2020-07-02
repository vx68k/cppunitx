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

#define MODULE test_assertion

#define MODULE_MAIN 1
#include <cppunitx/module>

#include <cppunitx/framework>
#include <cppunitx/assertion>

using namespace cppunitx;
using namespace cppunitx::assertion;

class AssertionTest
{
private:
    BeforeTest setUp {
        [this]() {
        }
    };

    AfterTest tearDown {
        [this]() {
        }
    };

    Test testAssertNull {"test 'assertNull'", [this]() {
            assertNull(0);
            // TODO: Add more assertions here.
        }};

    Test testAssertNotNull {"test 'assertNotNull'", [this]() {
            assertNotNull(this);
            // TODO: Add more assertions here.
        }};
};
TestRegistrant<AssertionTest> test {"assertion"};
