// <bits/cppunitx/driver.h>
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

#ifndef _CPPUNITX_DRIVER_H
#define _CPPUNITX_DRIVER_H 1

#include <cppunitx/framework>
#include <set>
#include <memory>
#include <bits/cppunitx.h>

namespace cppunitx
{
    /// Test context.
    class _CPPUNITX_PUBLIC TestContext
    {
    private:
        std::set<const Test *> _tests;

        std::set<const Before *> _befores;

        std::set<const After *> _afters;

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
        virtual void addBefore(const Before *before);

        /// Removes a before-test procedure from this context.
        virtual void removeBefore(const Before *before);

        /// Adds an after-test procedure to this context.
        virtual void addAfter(const After *after);

        /// Removes an after-test procedure from this context.
        virtual void removeAfter(const After *after);
    };

    /// Test driver.
    class _CPPUNITX_PUBLIC TestDriver
    {
    public:
        static std::shared_ptr<TestDriver> getInstance();

        static int main(int argc, char **argv);

    private:
        std::shared_ptr<TestContext> _currentContext;

    protected:
        TestDriver();

        TestDriver(const TestDriver &) = delete;
        TestDriver &operator =(const TestDriver &) = delete;

    public:
        virtual ~TestDriver();

    public:
        /// Returns the current test context.
        std::shared_ptr<TestContext> getCurrentContext() const
        {
            return _currentContext;
        }

        virtual void run(const char *suiteName);
    };
}

#endif
