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

#include <cppunitx/framework>
#include <locale>
#include <stdexcept>
#include <cstdio>
#include "module.h"

using std::string;
using std::exception;
using std::runtime_error;
using std::locale;
using std::shared_ptr;
using std::fprintf;
using namespace cppunitx;

const int SKIP = 77;
const int ERROR = 99;

// Class 'TestDriver' implementation.

shared_ptr<TestDriver> TestDriver::getInstance()
{
    static shared_ptr<TestDriver> instance {new TestDriver()};
    return instance;
}

int TestDriver::main(const int argc, char **const argv)
{
    locale::global(locale(""));

    try {
        auto driver = getInstance();
        for (int i = 1; i != argc; i += 1) {
            driver->run(argv[i]);
        }
    }
    catch (const exception &e) {
        fprintf(stderr, "Caught exception: %s\n", e.what());
        return SKIP;
    }
    return 0;
}

TestDriver::TestDriver()
{
}

TestDriver::~TestDriver()
{
}

void TestDriver::run(const char *const suiteName)
{
    using GetRegistryFunction = TestRegistry *();

    std::unique_ptr<module> suite {new module(suiteName)};
    if (not(*suite)) {
        throw runtime_error(string(suiteName) + ": Module not loadable");
    }

    auto getRegistry = reinterpret_cast<GetRegistryFunction *>(
        suite->sym("cppunitx_registry"));
    if (getRegistry == nullptr) {
        throw runtime_error(string(suiteName) + ": Not test suite module");
    }

    _currentContext.reset(new TestContext()); // TODO: This must be per-fixture.
    auto registry = getRegistry();
    registry->forEachRegistrant(
        [this](const TestRegistry::Registrant *const registrant) {
            registrant->runTests();
        });
}
