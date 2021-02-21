// test.cpp
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

#define _CPPUNITX_FRAMEWORK_IMPLEMENTATION 1
#include <bits/cppunitx/test.h>

#include <cppunitx/driver>

using std::function;
using std::move;
using std::string;
using namespace cppunitx;


// Implementation of class 'Test'.

Test::Test(const string &name, const function<void ()> &function)
:
    _name {name},
    _function {function}
{
    enable();
}

Test::Test(string &&name, const function<void ()> &function)
:
    _name {move(name)},
    _function {function}
{
    enable();
}

Test::~Test()
{
    disable();
}

void Test::enable()
{
    auto context = TestDriver::getInstance()->getCurrentContext();
    context->addTest(this);
}

void Test::disable()
{
    auto context = TestDriver::getInstance()->getCurrentContext();
    context->removeTest(this);
}


// Implementation of class 'BeforeTest'.

BeforeTest::BeforeTest(const function<void ()> &function)
:
    _function {function}
{
    enable();
}

BeforeTest::~BeforeTest()
{
    disable();
}

void BeforeTest::enable()
{
    auto context = TestDriver::getInstance()->getCurrentContext();
    context->addBeforeTest(this);
}

void BeforeTest::disable()
{
    auto context = TestDriver::getInstance()->getCurrentContext();
    context->removeBeforeTest(this);
}


// Implementation of class 'AfterTest'.

AfterTest::AfterTest(const function<void ()> &function)
:
    _function {function}
{
    enable();
}

AfterTest::~AfterTest()
{
    disable();
}

void AfterTest::enable()
{
    auto context = TestDriver::getInstance()->getCurrentContext();
    context->addAfterTest(this);
}

void AfterTest::disable()
{
    auto context = TestDriver::getInstance()->getCurrentContext();
    context->removeAfterTest(this);
}
