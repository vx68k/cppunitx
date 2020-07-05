// test_example.cpp
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

#define MODULE test_example

#define MODULE_MAIN 1
#include <cppunitx/module>

#include <cppunitx/framework>
#include <cppunitx/assertion>
#include <iostream>
#include <memory>

using std::clog;
using std::endl;
using namespace cppunitx;
using namespace cppunitx::assertion;

class Example
{
private:
    int _sum = 0;

public:
    int getSum() const
    {
        return _sum;
    }

public:
    Example &add(int x)
    {
        _sum += x;
        return *this;
    }
};

class ExampleTest
{
private:
    std::unique_ptr<Example> example;

private:
    BeforeTest setUp {[&]() {
        clog << "setUp!\n";
        example.reset(new Example());
    }};

    AfterTest tearDown {[&]() {
        clog << "tearDown!\n";
        example.reset();
    }};

    Test test1 {"test1", [&]() {
        clog << "test1!\n";
        assertEqual(0, example->getSum());
    }};

    Test test2 {"test2", [&]() {
        clog << "test2!\n";
        example->add(1).add(1);
        assertEqual(2, example->getSum());
    }};
};
TestSuite<ExampleTest> example {"example"};
