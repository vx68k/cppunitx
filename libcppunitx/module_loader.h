// module_loader.h
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

#ifndef MODULE_LOADER_H
#define MODULE_LOADER_H 1

#include <utility>


/**
 * Simple wrapper class for the dynamic loading functions.
 */
class module
{
public:

    using native_handle_type = void *;

private:

    native_handle_type _native_handle = nullptr;

protected:

    static native_handle_type open(const char *name);

public:

    // Constructors.

    module() noexcept = default;

    explicit module(native_handle_type native_handle)
    :
        _native_handle {native_handle}
    {
        // Nothing to do.
    }

    module(const module &) = delete;

    module(module &&other) noexcept
    {
        other.swap(*this);
    }


    // Destructor.

    ~module()
    {
        close();
    }


    // Assignment operators.

    void operator =(const module &) = delete;

    module &operator =(module &&other) noexcept
    {
        other.swap(*this);
        return *this;
    }


    // Conversions.

    explicit operator bool() const noexcept
    {
        return _native_handle != nullptr;
    }


    void swap(module &other) noexcept
    {
        using std::swap;
        swap(_native_handle, other._native_handle);
    }

    void close();

    void *sym(const char *symbol);
};


/**
 * Module class for Libtool libraries.
 */
class ltmodule: public module
{
protected:

    static native_handle_type open(const char *name);

public:

    // Constructors.

    ltmodule() noexcept = default;

    explicit ltmodule(const char *const name)
    :
        module(open(name))
    {
        // Nothing to do.
    }

    ltmodule(const ltmodule &) = delete;

    ltmodule(ltmodule &&other) noexcept = default;


    // Destructor.

    ~ltmodule() = default;


    // Assignment operators.

    void operator =(const ltmodule &) = delete;

    ltmodule &operator =(ltmodule &&other) noexcept = default;
};

#endif
