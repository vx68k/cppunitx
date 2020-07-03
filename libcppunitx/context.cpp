// context.cpp
// Copyright (C) 2018-2020 Kaz Nishimura
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

#include <bits/cppunitx/context.h>

using namespace cppunitx;

// Class 'TestContext' implementation.

TestContext::TestContext()
{
}

TestContext::~TestContext()
{
}

void TestContext::addTest(const Test *const test)
{
    _tests.insert(test);
}

void TestContext::removeTest(const Test *const test)
{
    _tests.erase(test);
}

void TestContext::addBeforeTest(const BeforeTest *const beforeTest)
{
    _beforeTests.insert(beforeTest);
}

void TestContext::removeBeforeTest(const BeforeTest *const beforeTest)
{
    _beforeTests.erase(beforeTest);
}

void TestContext::addAfterTest(const AfterTest *const afterTest)
{
    _afterTests.insert(afterTest);
}

void TestContext::removeAfterTest(const AfterTest *const afterTest)
{
    _afterTests.erase(afterTest);
}
