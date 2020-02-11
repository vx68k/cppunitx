// <bits/cppunitx/test.h>
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

#ifndef _CPPUNITX_TEST_H
#define _CPPUNITX_TEST_H 1

#include <set>
#include <functional>
#include <string>
#include <bits/cppunitx.h>

namespace cppunitx
{
    /// Object to specify a test case.
    ///
    /// This class is equivalent to the '@Test' annotation of JUnit.
    class _CPPUNITX_PUBLIC Test
    {
    private:
        const std::string _name;
        const std::function<void ()> _function;

    public:
        /// Constructs this object.
        template<class Function>
        Test(const char *name, Function function)
            : _name {name}, _function {std::forward<Function>(function)}
        {
            enable();
        }

        /// Constructs this object.
        template<class Function>
        Test(const std::string &name, Function function)
            : _name {name}, _function {std::forward<Function>(function)}
        {
            enable();
        }

        // To suppress implicit definitions.
        Test(const Test &) = delete;
        Test &operator =(const Test &) = delete;

    public:
        ~Test()
        {
            disable();
        }

    public:
        const std::string &getName() const
        {
            return _name;
        }

        /// Runs this test case.
        void run() const
        {
            _function();
        }

    private:
        void enable();

        void disable();
    };

    /// Object to specify a before-test procedure.
    ///
    /// This class is equivalent to the '@Before' annotation of JUnit.
    class _CPPUNITX_PUBLIC BeforeTest
    {
    private:
        const std::function<void ()> _function;

    public:
        template<class Function>
        explicit BeforeTest(Function function)
            : _function {std::forward<Function>(function)}
        {
            enable();
        }

        // To suppress implicit definitions.
        BeforeTest(const BeforeTest &) = delete;
        void operator =(const BeforeTest &) = delete;

    public:
        ~BeforeTest()
        {
            disable();
        }

    public:
        /// Runs this before-test procedure.
        void run() const
        {
            _function();
        }

    private:
        void enable();

        void disable();
    };

    /// Object to specify an after-test procedure.
    ///
    /// This class is equivalent to the '@After' annotation of JUnit.
    class _CPPUNITX_PUBLIC AfterTest
    {
    private:
        const std::function<void ()> _function;

    public:
        template<class Function>
        explicit AfterTest(Function function)
            : _function {std::forward<Function>(function)}
        {
            enable();
        }

        // To suppress implicit definitions.
        AfterTest(const AfterTest &) = delete;
        void operator =(const AfterTest &) = delete;

    public:
        ~AfterTest()
        {
            disable();
        }

    public:
        /// Runs this after-test procedure.
        void run() const
        {
            _function();
        }

    private:
        void enable();

        void disable();
    };

    /// Test context.
    class _CPPUNITX_PUBLIC TestContext
    {
    private:
        std::set<const Test *> _tests;

        std::set<const BeforeTest *> _beforeTests;

        std::set<const AfterTest *> _afterTests;

    public:
        TestContext();

    public:
        virtual ~TestContext();

    public:
        /// Adds a test case to this context.
        virtual void addTest(const Test *test);

        /// Removes a test case from this context.
        virtual void removeTest(const Test *test);

        /// Adds a before-test procedure to this context.
        virtual void addBeforeTest(const BeforeTest *before);

        /// Removes a before-test procedure from this context.
        virtual void removeBeforeTest(const BeforeTest *before);

        /// Adds an after-test procedure to this context.
        virtual void addAfterTest(const AfterTest *after);

        /// Removes an after-test procedure from this context.
        virtual void removeAfterTest(const AfterTest *after);
    };
}

#endif
