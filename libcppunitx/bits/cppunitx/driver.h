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

#include <bits/cppunitx/context.h>
#include <memory>

namespace cppunitx
{
    /// Test driver.
    class _CPPUNITX_PUBLIC TestDriver
    {
    public:
        static std::shared_ptr<TestDriver> getInstance();

        static int run(int argc, char *const *argv);

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
