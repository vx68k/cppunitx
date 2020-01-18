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

#include <bits/cppunitx.h>
#include <memory>
#include <string>

namespace cppunitx
{
    class _CPPUNITX_PUBLIC TestRegistrantBase
    {
    private:
        const std::string _name;

    protected:
        explicit TestRegistrantBase(const std::string &name);

        // To suppress implicit definitions.
        TestRegistrantBase(const TestRegistrantBase &) = delete;
        TestRegistrantBase &operator =(const TestRegistrantBase &) = delete;

    public:
        virtual ~TestRegistrantBase() = 0;

    public:
        const std::string &getName() const
        {
            return _name;
        }
    };

    template<class Fixture>
    class _CPPUNITX_PUBLIC TestRegistrant : public TestRegistrantBase
    {
        using inherited = TestRegistrantBase;

    public:
        explicit TestRegistrant(const std::string &name)
            : inherited(name)
        {
        }
    };

    // Regitry for tests.
    class _CPPUNITX_PUBLIC TestRegistry
    {
    public:
        TestRegistry();

        // To suppress implicit definitions.
        TestRegistry(const TestRegistry &) = delete;
        TestRegistry &operator =(const TestRegistry &) = delete;

    public:
        virtual ~TestRegistry() = 0;
    };

    template<class T>
    class _CPPUNITX_PUBLIC TestRegistryImpl : public TestRegistry
    {
    public:
        static std::shared_ptr<TestRegistryImpl> getInstance()
        {
            static auto instance = std::make_shared<TestRegistryImpl>();
            return instance;
        }
    };
}

#if defined SUITE

class SUITE;
extern template class cppunitx::TestRegistryImpl<SUITE>;

#endif /* defined SUITE */

#endif
