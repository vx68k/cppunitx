// <bits/cppunitx/context.h>
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

// This header defines classes to specify test cases, before- and after-test
// procedures in a test fixture.

#ifndef _CPPUNITX_CONTEXT_H
#define _CPPUNITX_CONTEXT_H 1

#include <bits/cppunitx/test.h>
#include <set>

namespace cppunitx
{
    /// Test context.
    class _CPPUNITX_PUBLIC TestContext
    {
    private:

        std::set<const Test *> _tests;

        std::set<const BeforeTest *> _beforeTests;

        std::set<const AfterTest *> _afterTests;

    public:

        // Constructors.

        TestContext();

        TestContext(const TestContext &other) = delete;


        // Destructor.

        virtual ~TestContext();


        // Assignment operators.

        void operator =(const TestContext &other) = delete;


        /// Adds a test case to this context.
        virtual void addTest(const Test *test);

        /// Removes a test case from this context.
        virtual void removeTest(const Test *test);

        /// Adds a before-test procedure to this context.
        virtual void addBeforeTest(const BeforeTest *beforeTest);

        /// Removes a before-test procedure from this context.
        virtual void removeBeforeTest(const BeforeTest *beforeTest);

        /// Adds an after-test procedure to this context.
        virtual void addAfterTest(const AfterTest *afterTest);

        /// Removes an after-test procedure from this context.
        virtual void removeAfterTest(const AfterTest *afterTest);

        virtual void runTests() const;
    };
}

#endif
