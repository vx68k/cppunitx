// <bits/cppunitx/module.h>
// Copyright (C) 2018-2020 Kaz Nishimura
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

#ifndef _CPPUNITX_MODULE_H
#define _CPPUNITX_MODULE_H 1

#if !defined SUITE
#error "The required macro 'SUITE' not defined"
#endif

#include <cppunitx/framework>
#include <bits/cppunitx.h>

#define _CPPUNITX_LT_NAME(M, F) __CPPUNITX_LT_NAME(M, F)
#define __CPPUNITX_LT_NAME(M, F) M ## _LTX_ ## F

#define cppunitx_registry _CPPUNITX_LT_NAME(SUITE, cppunitx_registry)

extern "C" cppunitx::TestRegistry *cppunitx_registry();

#if MODULE_MAIN

class SUITE;

_CPPUNITX_PUBLIC cppunitx::TestRegistry *cppunitx_registry()
{
    return cppunitx::TestRegistry::getInstance<class SUITE>().get();
}

#endif /* MODULE_MAIN */

#endif
