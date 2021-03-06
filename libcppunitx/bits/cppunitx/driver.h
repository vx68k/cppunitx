// <bits/cppunitx/driver.h>
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

#ifndef _CPPUNITX_DRIVER_H
#define _CPPUNITX_DRIVER_H 1

#include <bits/cppunitx/context.h>
#include <memory>

namespace cppunitx
{
    /// Test driver.
    class _CPPUNITX_PUBLIC TestDriver
    {
    private:

        static std::shared_ptr<TestDriver> _instance;

        std::shared_ptr<TestContext> _currentContext;

    public:

        static std::shared_ptr<TestDriver> getInstance()
        {
            return _instance;
        }

    protected:

        // Constructors.

        TestDriver();

        TestDriver(const TestDriver &) = delete;

    public:

        // Destructor.

        virtual ~TestDriver();

        // Assignment operators.

        void operator =(const TestDriver &) = delete;


        /// Returns the current test context.
        std::shared_ptr<TestContext> getCurrentContext() const
        {
            return _currentContext;
        }

        virtual int run(const char *suiteName);
    };
}

#endif
