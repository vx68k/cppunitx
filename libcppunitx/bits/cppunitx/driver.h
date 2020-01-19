// <bits/cppunitx/driver.h>
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

#ifndef _CPPUNITX_DRIVER_H
#define _CPPUNITX_DRIVER_H 1

#include <bits/cppunitx.h>

namespace cppunitx
{
    extern int main(int argc, char *argv[]);

    /// Test driver.
    class _CPPUNITX_PUBLIC TestDriver
    {
    public:
        static int main(int argc, char **argv);
    };
}

#endif