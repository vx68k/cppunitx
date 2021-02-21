// <bits/cppunitx/test.h>
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

// This header defines classes to specify test cases, before- and after-test
// procedures in a test fixture.

#ifndef _CPPUNITX_TEST_H
#define _CPPUNITX_TEST_H 1

#include <bits/cppunitx.h>
#include <functional>
#include <utility>
#include <string>

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

        // Constructors.

        Test(const std::string &name, const std::function<void ()> &function);

        Test(std::string &&name, const std::function<void ()> &function);

        // To suppress implicit definitions.
        Test(const Test &) = delete;


        // Destructor.

        ~Test();


        // Assignment operators.

        void operator =(const Test &) = delete;


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


    /// Object to specify a before-test (or set-up) procedure.
    /// Before-test procedures will run once before each test case.
    ///
    /// This class is equivalent to the '@Before' annotation of JUnit 4.
    class _CPPUNITX_PUBLIC BeforeTest
    {
    private:

        const std::function<void ()> _function;

    public:

        // Constructors.

        explicit BeforeTest(const std::function<void ()> &function);

        // Deleted: this class is not copy-constructible.
        BeforeTest(const BeforeTest &) = delete;


        // Destructor.

        ~BeforeTest();


        // Assignment operators.

        // Deleted: this class is not copy-assignable.
        void operator =(const BeforeTest &) = delete;


        /// Runs this before-test procedure.
        void run() const
        {
            _function();
        }

    private:

        void enable();

        void disable();
    };


    /// Object to specify an after-test (or tear-down) procedure.
    /// After-test procedures will run once after each test case.
    ///
    /// This class is equivalent to the '@After' annotation of JUnit 4.
    class _CPPUNITX_PUBLIC AfterTest
    {
    private:

        const std::function<void ()> _function;

    public:

        // Constructors.

        explicit AfterTest(const std::function<void ()> &function);

        // Deleted: this class is not copy-constructible.
        AfterTest(const AfterTest &) = delete;


        // Destructor.

        ~AfterTest();


        // Assignment operators.

        // Deleted: this class is not copy-assignable.
        void operator =(const AfterTest &) = delete;


        /// Runs this after-test procedure.
        void run() const
        {
            _function();
        }

    private:

        void enable();

        void disable();
    };
}

#endif
