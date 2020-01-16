// <bits/cppunitx/registry.h>
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

#ifndef _CPPUNITX_REGISTRY_H
#define _CPPUNITX_REGISTRY_H 1

#include <functional>
#include <string>

namespace cppunitx
{
    class Test
    {
    public:
        Test(const std::string &name, std::function<void ()> &&method);

        // To suppress implicit definitions.
        Test(const Test &) = delete;
        Test &operator =(const Test &) = delete;
    };

    class TestRegistrantBase
    {
    public:
        explicit TestRegistrantBase(const std::string &)
        {
        }

    public:
        virtual ~TestRegistrantBase() {};
    };

    template<class Fixture>
    class TestRegistrant : public TestRegistrantBase
    {
        using inherited = TestRegistrantBase;

    public:
        explicit TestRegistrant(const std::string &name)
            : inherited(name)
        {
        }
    };

    // Regitry for tests.
    class TestRegistry
    {
    public:
        TestRegistry() = default;

        // To suppress implicit definitions.
        TestRegistry(const TestRegistry &) = delete;
        TestRegistry &operator =(const TestRegistry &) = delete;
    };
}

#endif
