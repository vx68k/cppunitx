// cppunitx/bits/module.h
// Copyright (C) 2018 Kaz Nishimura
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

#ifndef _CPPUNITX_BITS_MODULE_H
#define _CPPUNITX_BITS_MODULE_H 1

namespace cppunitx
{
    /// Module loader.
    ///
    /// Any object of this class is not copyable.
    class module_loader final
    {
    public:
        module_loader(const module_loader &) = delete;
        void operator=(const module_loader &) = delete;

        virtual ~module_loader();
    public:
        module_loader &load(const char *name);
    };
}

#ifdef MODULE_NAME

#define _CPPUNITX_DLNAME_(M, F) M ## _LTX_ ## F
#define _CPPUNITX_DLNAME(M, F) _CPPUNITX_DLNAME_(M, F)

#define init _CPPUNITX_DLNAME(MODULE_NAME, init)

extern "C" void init()
{
}

#endif /* defined MODULE_NAME */

#endif
