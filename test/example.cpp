// example.cpp
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
#include <memory>

using namespace cppunitx;

class Example
{
};

class ExampleTest
{
private:
    std::unique_ptr<Example> example;

private:
    BeforeTest setUp {
        [this]() {
            example.reset(new Example());
        }
    };

    AfterTest tearDown {
        [this]() {
            example.reset();
        }
    };

    Test test1 {"test1", [this]() {
        // TODO: Add assertions here.
    }};
};
TestSuite<ExampleTest> example {"example"};
