// driver.cpp
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

#define _CPPUNITX_DRIVER_IMPLEMENTATION 1
#include <bits/cppunitx/driver.h>

#include <cstdlib>

using std::shared_ptr;
using namespace cppunitx;

// Class 'TestDriver' implementation.

shared_ptr<TestDriver> TestDriver::getInstance()
{
    static shared_ptr<TestDriver> instance(new TestDriver());
    return instance;
}

int TestDriver::main(const int argc, char **const argv)
{
    auto driver = getInstance();
    return EXIT_FAILURE; // TODO: Implement this function.
}

TestDriver::TestDriver()
{
}

TestDriver::~TestDriver()
{
}
