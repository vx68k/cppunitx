// driver.cpp
// Copyright (C) 2018-2021 Kaz Nishimura
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

#include <bits/cppunitx/driver.h>

#include <cppunitx/framework>
#include <locale>
#include <stdexcept>
#include <cstdio>
#include "module_loader.h"

using std::fprintf;
using std::make_shared;
using std::runtime_error;
using std::shared_ptr;
using namespace cppunitx;

const int SKIP = 77;
const int ERROR = 99;


// Implementation of class 'TestDriver'

shared_ptr<TestDriver> TestDriver::_instance =
    // The constructors of class 'TestDriver' are protected.
    shared_ptr<TestDriver>(new TestDriver());

TestDriver::TestDriver()
{
    // Nothing to do.
}

TestDriver::~TestDriver()
{
    // Nothing to do.
}

int TestDriver::run(const char *const suiteName)
{
    using GetRegistryFunction = TestRegistry *();

    std::unique_ptr<ltmodule> suite {new ltmodule(suiteName)};
    if (!*suite) {
        fprintf(stderr, "%s: failed to load\n", suiteName);
        return ERROR;
    }

    auto &&getRegistry = reinterpret_cast<GetRegistryFunction *>(
        suite->sym("cppunitx_registry"));
    if (getRegistry == nullptr) {
        fprintf(stderr, "%s: registry not found\n", suiteName);
        return ERROR;
    }

    getRegistry()->forEach(
        [this](const TestRegistry::Registrant *const r)
        {
            _currentContext = make_shared<TestContext>();
            r->runTests();
        });

    return 0;
}
