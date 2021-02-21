// registry.cpp
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

#if HAVE_CONFIG_H
#include <config.h>
#endif

#include <bits/cppunitx/registry.h>

#include <algorithm>

using std::for_each;
using namespace cppunitx;


TestRegistry::Registrant::~Registrant()
{
    // Nothing to do.
}


// Class 'TestRegistry' implementation.

TestRegistry::TestRegistry()
{
}

TestRegistry::~TestRegistry()
{
}

void TestRegistry::addRegistrant(
    const Registrant *const registrant)
{
    _registrants.insert(registrant);
}

void TestRegistry::removeRegistrant(
    const Registrant *const registrant)
{
    _registrants.erase(registrant);
}

void TestRegistry::forEachRegistrant(
    const std::function<void (const Registrant *)> &f
) const
{
    for_each(_registrants.begin(), _registrants.end(), f);
}
