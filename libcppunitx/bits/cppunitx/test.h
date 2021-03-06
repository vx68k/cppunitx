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

        std::string _name;

        std::function<void ()> _function;

    public:

        // Constructors.

        Test(const std::string &name, const std::function<void ()> &function);

        Test(const std::string &name, std::function<void ()> &&function);

        Test(std::string &&name, const std::function<void ()> &function);

        Test(std::string &&name, std::function<void ()> &&function);

        // To suppress implicit definitions.
        Test(const Test &) = delete;

        Test(Test &&other);


        // Destructor.

        ~Test();


        // Assignment operators.

        void operator =(const Test &) = delete;

        Test &operator =(Test &&other) noexcept;


        /**
         * Swaps the values of this object and another.
         *
         * @param other another `Test` object
         */
        void swap(Test &other) noexcept
        {
            _name.swap(other._name);
            _function.swap(other._function);
        }

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

        void activate() const;

        void deactivate() const;
    };

    /**
     * Swaps the values of two `Test` objects.
     *
     * @param one a `Test` object
     * @param other another `Test` object
     */
    inline void swap(Test &one, Test &other) noexcept
    {
        one.swap(other);
    }


    /// Object to specify a before-test (or set-up) procedure.
    /// Before-test procedures will run once before each test case.
    ///
    /// This class is equivalent to the '@Before' annotation of JUnit 4.
    class _CPPUNITX_PUBLIC BeforeTest
    {
    private:

        std::function<void ()> _function;

    public:

        // Constructors.

        explicit BeforeTest(const std::function<void ()> &function);

        explicit BeforeTest(std::function<void ()> &&function);

        BeforeTest(const BeforeTest &other) = delete;

        BeforeTest(BeforeTest &&other);


        // Destructor.

        ~BeforeTest();


        // Assignment operators.

        void operator =(const BeforeTest &other) = delete;

        BeforeTest &operator =(BeforeTest &&other) noexcept;


        void swap(BeforeTest &other) noexcept
        {
            _function.swap(other._function);
        }

        /// Runs this before-test procedure.
        void run() const
        {
            _function();
        }

    private:

        void activate() const;

        void deactivate() const;
    };

    /**
     * Swaps the values of two `BeforeTest` objects.
     *
     * @param one a `BeforeTest` object
     * @param other another `BeforeTest` object
     */
    inline void swap(BeforeTest &one, BeforeTest &other) noexcept
    {
        one.swap(other);
    }


    /// Object to specify an after-test (or tear-down) procedure.
    /// After-test procedures will run once after each test case.
    ///
    /// This class is equivalent to the '@After' annotation of JUnit 4.
    class _CPPUNITX_PUBLIC AfterTest
    {
    private:

        std::function<void ()> _function;

    public:

        // Constructors.

        explicit AfterTest(const std::function<void ()> &function);

        explicit AfterTest(std::function<void ()> &&function);

        AfterTest(const AfterTest &other) = delete;

        AfterTest(AfterTest &&other);


        // Destructor.

        ~AfterTest();


        // Assignment operators.

        void operator =(const AfterTest &other) = delete;

        AfterTest &operator =(AfterTest &&other) noexcept;


        void swap(AfterTest &other) noexcept
        {
            _function.swap(other._function);
        }

        /// Runs this after-test procedure.
        void run() const
        {
            _function();
        }

    private:

        void activate() const;

        void deactivate() const;
    };

    /**
     * Swaps the values of two `AfterTest` objects.
     *
     * @param one an `AfterTest` object
     * @param other another `AfterTest` object
     */
    inline void swap(AfterTest &one, AfterTest &other) noexcept
    {
        one.swap(other);
    }
}

#endif
