// registry.cpp
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

#if HAVE_CONFIG_H
#include <config.h>
#endif

#include <bits/cppunitx/registry.h>

#include <algorithm>
#include <utility>

using std::for_each;
using std::move;
using namespace cppunitx;


// Implementations of class 'TestRegistry::Registrant'

TestRegistry::Registrant::Registrant(const std::string &name)
:
    _name {name}
{
    // Nothing to do.
}

TestRegistry::Registrant::Registrant(std::string &&name)
:
    _name {move(name)}
{
    // Nothing to do.
}

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

void TestRegistry::forEach(
    const std::function<void (const Registrant *)> &f
) const
{
    for_each(_registrants.begin(), _registrants.end(), f);
}
