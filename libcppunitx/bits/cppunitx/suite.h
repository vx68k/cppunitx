// <bits/cppunitx/suite.h>
// Copyright (C) 2020-2021 Kaz Nishimura
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

#ifndef _CPPUNITX_SUITE_H
#define _CPPUNITX_SUITE_H 1

#include <bits/cppunitx/registry.h>
#include <bits/cppunitx/driver.h>
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
    /// Test suite.
    template<class Fixture>
    class TestSuite: public TestRegistry::Registrant
    {
    protected:

        static std::shared_ptr<TestRegistry> getRegistry()
        {
            return TestRegistry::getInstance<_CPPUNITX_TEST_MODULE>();
        }

    public:

        // Constructors.

        /// Constructs this object.
        explicit TestSuite(const std::string &name)
        :
            Registrant(name)
        {
            getRegistry()->addRegistrant(this);
        }

        /// Constructs this object.
        explicit TestSuite(std::string &&name)
        :
            Registrant(name)
        {
            getRegistry()->addRegistrant(this);
        }


        // Destructor.

        ~TestSuite()
        {
            getRegistry()->removeRegistrant(this);
        }


        void runTests() const override
        {
            std::unique_ptr<Fixture> fixture {new Fixture()};

            auto &&driver = TestDriver::getInstance();
            driver->getCurrentContext()->runTests();
        }
    };
}

#endif
