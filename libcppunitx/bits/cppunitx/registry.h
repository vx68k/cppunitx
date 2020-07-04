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

#include <bits/cppunitx/driver.h>
#include <unordered_set>
#include <functional>
#include <memory>
#include <string>

#if defined MODULE
// This makes the module name available as a type name.
class MODULE;
#define _CPPUNITX_TEST_MODULE typename ::MODULE
#endif

#ifndef _CPPUNITX_TEST_MODULE
#define _CPPUNITX_TEST_MODULE void
#endif

namespace cppunitx
{
    /// Test regitry.
    class _CPPUNITX_PUBLIC TestRegistry
    {
    public:
        /// Base class for test registrants.
        class _CPPUNITX_PUBLIC Registrant
        {
        private:
            std::string _name;

        protected:
            /// Constructs this object with a null-terminated string value.
            explicit Registrant(const char *const name)
                : _name {name}
            {
            }

            /// Constructs this object with a 'std::string' value.
            explicit Registrant(const std::string &name)
                : _name {name}
            {
            }

            /// Constructs this object with a 'std::string' value.
            explicit Registrant(std::string &&name)
                : _name {name}
            {
            }

            // Deleted: this class is not copy-constructible.
            Registrant(const Registrant &) = delete;

            // Deleted: this class is not copy-assignable.
            void operator =(const Registrant &) = delete;

        public:
            /// Does nothing on destruction of this object.
            virtual ~Registrant()
            {
            }

        public:
            /// Returns the name of this object.
            const std::string &getName() const noexcept
            {
                return _name;
            }

            /// Runs tests.
            virtual void runTests() const = 0;
        };

    public:
        /// Returns the test registry for a test module.
        template<class Module>
        static std::shared_ptr<TestRegistry> getInstance()
        {
            static auto instance = std::make_shared<TestRegistry>();
            return instance;
        }

    private:
        std::unordered_set<const Registrant *> _registrants;

    public:
        TestRegistry();

        // To suppress implicit definitions.
        TestRegistry(const TestRegistry &) = delete;
        void operator =(const TestRegistry &) = delete;

    public:
        virtual ~TestRegistry();

    public:
        /// Adds a registrant to this registry.
        void addRegistrant(const Registrant *registrant);

        /// Removes a registrant from this registry.
        void removeRegistrant(const Registrant *registrant);

        /// Invokes a function for each registrant.
        void forEachRegistrant(
            const std::function<void (const Registrant *)> &f
        ) const;
    };


    /// Registrant for task registries.
    template<class Fixture>
    class _CPPUNITX_PUBLIC TestSuite: public TestRegistry::Registrant
    {
        using inherited = TestRegistry::Registrant;

    protected:
        static std::shared_ptr<TestRegistry> getRegistry()
        {
            return TestRegistry::getInstance<_CPPUNITX_TEST_MODULE>();
        }

    public:
        /// Constructs this object.
        explicit TestSuite(const char *name)
            : inherited(name)
        {
            getRegistry()->addRegistrant(this);
        }

        /// Constructs this object.
        explicit TestSuite(const std::string &name)
            : inherited(name)
        {
            getRegistry()->addRegistrant(this);
        }

        /// Constructs this object.
        explicit TestSuite(std::string &&name)
            : inherited(name)
        {
            getRegistry()->addRegistrant(this);
        }

    public:
        ~TestSuite()
        {
            getRegistry()->removeRegistrant(this);
        }

    public:
        void runTests() const override
        {
            std::unique_ptr<Fixture> fixture {new Fixture()};

            auto &&driver = TestDriver::getInstance();
            driver->getCurrentContext()->runTests();
        }
    };
}

#endif
