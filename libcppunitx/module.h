// module.h
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

#ifndef MODULE_H
#define MODULE_H 1

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

public:
    module() noexcept = default;

    module(const module &) = delete;

    module(module &&other) noexcept
    {
        swap(other);
    }

    explicit module(const char *name)
    {
        open(name);
    }

public:
    void operator =(const module &) = delete;

    module &operator =(module &&other) noexcept
    {
        swap(other);
        return *this;
    }

public:
    ~module()
    {
        close();
    }

public:
    explicit operator bool() const noexcept
    {
        return _native_handle != nullptr;
    }

public:
    void swap(module &other) noexcept
    {
        std::swap(_native_handle, other._native_handle);
    }

public:
    void open(const char *name);

public:
    void close();

public:
    void *sym(const char *symbol);
};

#endif
