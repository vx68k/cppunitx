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
    activate();
}

Test::Test(const string &name, function<void ()> &&function)
:
    _name {name},
    _function {move(function)}
{
    activate();
}

Test::Test(string &&name, const function<void ()> &function)
:
    _name {move(name)},
    _function {function}
{
    activate();
}

Test::Test(string &&name, function<void ()> &&function)
:
    _name {move(name)},
    _function {move(function)}
{
    activate();
}

Test::~Test()
{
    deactivate();
}

void Test::activate() const
{
    auto context = TestDriver::getInstance()->getCurrentContext();
    context->addTest(this);
}

void Test::deactivate() const
{
    auto context = TestDriver::getInstance()->getCurrentContext();
    context->removeTest(this);
}


// Implementation of class 'BeforeTest'.

BeforeTest::BeforeTest(const function<void ()> &function)
:
    _function {function}
{
    activate();
}

BeforeTest::BeforeTest(function<void ()> &&function)
:
    _function {move(function)}
{
    activate();
}

BeforeTest::BeforeTest(BeforeTest &&other)
:
    _function {move(other._function)}
{
    activate();
}

BeforeTest::~BeforeTest()
{
    deactivate();
}

BeforeTest &BeforeTest::operator =(BeforeTest &&other)
{
    _function = move(other._function);
    return *this;
}

void BeforeTest::swap(BeforeTest &other)
{
    _function.swap(other._function);
}

void BeforeTest::activate() const
{
    auto context = TestDriver::getInstance()->getCurrentContext();
    context->addBeforeTest(this);
}

void BeforeTest::deactivate() const
{
    auto context = TestDriver::getInstance()->getCurrentContext();
    context->removeBeforeTest(this);
}


// Implementation of class 'AfterTest'.

AfterTest::AfterTest(const function<void ()> &function)
:
    _function {function}
{
    activate();
}

AfterTest::AfterTest(function<void ()> &&function)
:
    _function {move(function)}
{
    activate();
}

AfterTest::AfterTest(AfterTest &&other)
:
    _function {move(other._function)}
{
    activate();
}

AfterTest::~AfterTest()
{
    deactivate();
}

AfterTest &AfterTest::operator =(AfterTest &&other)
{
    _function = move(other._function);
    return *this;
}

void AfterTest::swap(AfterTest &other)
{
    _function.swap(other._function);
}

void AfterTest::activate() const
{
    auto context = TestDriver::getInstance()->getCurrentContext();
    context->addAfterTest(this);
}

void AfterTest::deactivate() const
{
    auto context = TestDriver::getInstance()->getCurrentContext();
    context->removeAfterTest(this);
}
