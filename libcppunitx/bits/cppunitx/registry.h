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
#include <functional>
#include <memory>
#include <string>

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

            // Constructors.

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

        public:

            // Destructor.

            /// Does nothing on destruction of this object.
            virtual ~Registrant()
            {
            }


            // Assignment operators.

            // Deleted: this class is not copy-assignable.
            void operator =(const Registrant &) = delete;


            /// Returns the name of this object.
            const std::string &getName() const noexcept
            {
                return _name;
            }

            /// Runs tests.
            virtual void runTests() const = 0;
        };

    private:

        std::unordered_set<const Registrant *> _registrants;

    public:

        /// Returns the test registry for a test module.
        template<class Module>
        static std::shared_ptr<TestRegistry> getInstance()
        {
            static auto instance = std::make_shared<TestRegistry>();
            return instance;
        }


        // Constructors.

        TestRegistry();

        // To suppress implicit definitions.
        TestRegistry(const TestRegistry &) = delete;


        // Destructor.

        virtual ~TestRegistry();


        // Assignment operators.

        void operator =(const TestRegistry &) = delete;


        /// Adds a registrant to this registry.
        void addRegistrant(const Registrant *registrant);

        /// Removes a registrant from this registry.
        void removeRegistrant(const Registrant *registrant);

        /// Invokes a function for each registrant.
        void forEachRegistrant(
            const std::function<void (const Registrant *)> &f
        ) const;
    };
}

#endif
