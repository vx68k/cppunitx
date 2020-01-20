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

#ifndef _CPPUNITX_TEST_H
#define _CPPUNITX_TEST_H 1

#include <bits/cppunitx.h>
#include <functional>
#include <string>

namespace cppunitx
{
    /// Object to specify a test case.
    class _CPPUNITX_PUBLIC Test
    {
    private:
        const std::string _name;
        const std::function<void ()> _function;

    public:
        Test(const std::string &name, std::function<void ()> &&function);

        // To suppress implicit definitions.
        Test(const Test &) = delete;
        Test &operator =(const Test &) = delete;

    public:
        ~Test();

    public:
        const std::string &getName() const
        {
            return _name;
        }
    };

    /// Object to specify a before-test procedure.
    class _CPPUNITX_PUBLIC Before
    {
    private:
        const std::function<void ()> _function;

    public:
        Before(std::function<void ()> &&function);

        // To suppress implicit definitions.
        Before(const Before &) = delete;
        Before &operator =(const Before &) = delete;

    public:
        ~Before();
    };

    /// Object to specify an after-test procedure.
    class _CPPUNITX_PUBLIC After
    {
    private:
        const std::function<void ()> _function;

    public:
        After(std::function<void ()> &&function);

        // To suppress implicit definitions.
        After(const After &) = delete;
        After &operator =(const After &) = delete;

    public:
        ~After();
    };
}

#endif
