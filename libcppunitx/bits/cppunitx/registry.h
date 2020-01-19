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
#include <unordered_set>
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

    // Regitry for tests.
    class _CPPUNITX_PUBLIC TestRegistry
    {
    public:
        template<class Suite = void>
        static std::shared_ptr<TestRegistry> getInstance()
        {
            static auto instance = std::make_shared<TestRegistry>();
            return instance;
        }

    private:
        std::unordered_set<const TestRegistrantBase *> registrants;

    public:
        TestRegistry();

        // To suppress implicit definitions.
        TestRegistry(const TestRegistry &) = delete;
        TestRegistry &operator =(const TestRegistry &) = delete;

    public:
        virtual ~TestRegistry();

    public:
        /// Adds a registrant to this registry.
        void addRegistrant(const TestRegistrantBase *registrant);

        /// Removes a registrant from this registry.
        void removeRegistrant(const TestRegistrantBase *registrant);
    };

    template<class Fixture, class Suite>
    class _CPPUNITX_PUBLIC TestRegistrant : public TestRegistrantBase
    {
        using inherited = TestRegistrantBase;

    protected:
        static std::shared_ptr<TestRegistry> getRegistry()
        {
            return TestRegistry::getInstance<Suite>();
        }

    public:
        explicit TestRegistrant(const std::string &name)
            : inherited(name)
        {
            auto registry = getRegistry();
            registry->addRegistrant(this);
        }

    public:
        ~TestRegistrant()
        {
            auto registry = getRegistry();
            registry->removeRegistrant(this);
        }
    };
}

#endif
