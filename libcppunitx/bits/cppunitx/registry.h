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

#if defined SUITE
// This makes the suite name available as a type name.
class SUITE;
#define _CPPUNITX_DEFAULT_SUITE ::SUITE
#endif

#ifndef _CPPUNITX_DEFAULT_SUITE
#define _CPPUNITX_DEFAULT_SUITE void
#endif

namespace cppunitx
{
    class _CPPUNITX_PUBLIC AbstractTestRegistrant
    {
    private:
        std::string name;

    public:
        explicit AbstractTestRegistrant(const std::string &name);

        explicit AbstractTestRegistrant(std::string &&name) noexcept;

        // To suppress implicit definitions.
        AbstractTestRegistrant(const AbstractTestRegistrant &) = delete;
        void operator =(const AbstractTestRegistrant &) = delete;

    public:
        virtual ~AbstractTestRegistrant() = 0;

    public:
        const std::string &getName() const noexcept
        {
            return name;
        }

        /// Runs tests.
        virtual void runTests() const = 0;
    };

    // Regitry for tests.
    class _CPPUNITX_PUBLIC TestRegistry
    {
    public:
        template<class Suite = _CPPUNITX_DEFAULT_SUITE>
        static std::shared_ptr<TestRegistry> getInstance()
        {
            static auto instance = std::make_shared<TestRegistry>();
            return instance;
        }

    private:
        std::unordered_set<const AbstractTestRegistrant *> registrants;

    public:
        TestRegistry();

        // To suppress implicit definitions.
        TestRegistry(const TestRegistry &) = delete;
        void operator =(const TestRegistry &) = delete;

    public:
        virtual ~TestRegistry();

    public:
        /// Adds a registrant to this registry.
        void addRegistrant(const AbstractTestRegistrant *registrant);

        /// Removes a registrant from this registry.
        void removeRegistrant(const AbstractTestRegistrant *registrant);

        /// Runs tests for each registrant.
        void runTests() const;
    };

    /// Registrant for task registries.
    template<class Fixture, class Suite = _CPPUNITX_DEFAULT_SUITE>
    class _CPPUNITX_PUBLIC TestRegistrant : public AbstractTestRegistrant
    {
        using inherited = AbstractTestRegistrant;

    protected:
        static std::shared_ptr<TestRegistry> getRegistry()
        {
            return TestRegistry::getInstance<Suite>();
        }

    public:
        explicit TestRegistrant(const std::string &name)
            : inherited {name}
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

    public:
        void runTests() const override
        {
            std::unique_ptr<Fixture> fixture {new Fixture()};
            // TODO: Run tests here.
        }
    };
}

#endif
