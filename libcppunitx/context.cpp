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
#include <bits/cppunitx/exception.h>
#include <algorithm>
#include <functional>
#include <utility>
#include <stdexcept>

using std::for_each;
using std::function;
using std::move;
using namespace cppunitx;

namespace
{
    class defered
    {
    private:

        function<void ()> _function;

    public:

        explicit defered(function<void ()> &&function)
        :
            _function {move(function)}
        {
            // Nothing to do.
        }

        defered(const defered &) = delete;

        ~defered()
        {
            if (_function != nullptr) {
                _function();
            }
        }

        void operator =(const defered &) = delete;
    };
}

// Class 'TestContext' implementation.

TestContext::TestContext()
{
    // Nothing to do.
}

TestContext::~TestContext()
{
    // Nothing to do.
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

void TestContext::runTests() const
{
    for_each(_tests.begin(), _tests.end(), [&](const Test *test) {
        runBeforeTests();
        defered afterTests {
            [this]() {
                runAfterTests();
            }};

        try {
            test->run();
        }
        catch (const AssertionFailedException &e)
        {
            // TODO: Handle failures.
        }
    });
}

void TestContext::runBeforeTests() const
{
    for_each(_beforeTests.begin(), _beforeTests.end(),
        [](const BeforeTest *bt) {
            bt->run();
        });
}

void TestContext::runAfterTests() const
{
    for_each(_afterTests.begin(), _afterTests.end(),
        [](const AfterTest *at) {
            at->run();
        });
}
