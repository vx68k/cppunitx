// test.cpp
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

#define _CPPUNITX_FRAMEWORK_IMPLEMENTATION 1
#include <bits/cppunitx/test.h>

#include <cppunitx/driver>

using std::string;
using std::function;
using namespace cppunitx;

// Class 'Test' implementation.

Test::Test(const string &name, const function<void ()> &function)
    : _name {name}, _function {function}
{
    enable();
}

Test::Test(const string &name, function<void ()> &&function)
    : _name {name}, _function {function}
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

// Class 'Before' implementation.

Before::Before(const function<void ()> &function)
    : _function {function}
{
    enable();
}

Before::Before(function<void ()> &&function)
    : _function {function}
{
    enable();
}

Before::~Before()
{
    disable();
}

void Before::enable()
{
    auto context = TestDriver::getInstance()->getCurrentContext();
    context->addBefore(this);
}

void Before::disable()
{
    auto context = TestDriver::getInstance()->getCurrentContext();
    context->removeBefore(this);
}

// Class 'After' implementation.

After::After(const function<void ()> &function)
    : _function {function}
{
    enable();
}

After::After(function<void ()> &&function)
    : _function {function}
{
    enable();
}

After::~After()
{
    disable();
}

void After::enable()
{
    auto context = TestDriver::getInstance()->getCurrentContext();
    context->addAfter(this);
}

void After::disable()
{
    auto context = TestDriver::getInstance()->getCurrentContext();
    context->removeAfter(this);
}
