// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: vector3D.hpp
// Author: crdrisko
// Date: 04/07/2020-11:08:41
// Description: A vector representing a quantity with x, y, and z components

#ifndef COMMON_UTILITIES_VECTOR3D_HPP
#define COMMON_UTILITIES_VECTOR3D_HPP

#include <array>
#include <cstddef>
#include <type_traits>
#include <utility>

#include "utilities.hpp"

namespace CppUtils::Math
{
    template<typename T, typename = std::enable_if_t<std::is_default_constructible_v<T>>>
    class Vector3D : private Operators::CompletelyComparable<Vector3D<T>>
    {
    public:
        // Member types
        using value_type      = T;
        using size_type       = std::size_t;
        using difference_type = std::ptrdiff_t;
        using reference       = T&;
        using const_reference = const T&;
        using pointer         = T*;
        using const_pointer   = const T*;
        using iterator        = T*;
        using const_iterator  = const T*;

        // With this member type, we are now both a container and container adapter
        using container_type = std::array<T, 3>;

    private:
        std::array<T, 3> data {};

    public:
        // Constructors
        constexpr Vector3D() noexcept = default;
        constexpr Vector3D(T X, T Y, T Z) noexcept : data {{X, Y, Z}} {}
        constexpr explicit Vector3D(const container_type& Data) noexcept : data {Data} {}

        // Comparison operators - reuse the definitions from the internal array
        constexpr friend bool operator==(const Vector3D<T>& lhs, const Vector3D<T>& rhs) { return lhs.data == rhs.data; }
        constexpr friend bool operator<(const Vector3D<T>& lhs, const Vector3D<T>& rhs) { return lhs.data < rhs.data; }

        // Element access - reuse the definitions from the internal array
        constexpr reference at(size_type pos) { return data.at(pos); }               // Could throw: array::at
        constexpr const_reference at(size_type pos) const { return data.at(pos); }   // Could throw: array::at

        constexpr reference operator[](size_type pos) noexcept { return data[pos]; }
        constexpr const_reference operator[](size_type pos) const noexcept { return data[pos]; }

        constexpr reference x() noexcept { return data[0]; }
        constexpr const_reference x() const noexcept { return data[0]; }

        constexpr reference y() noexcept { return data[1]; }
        constexpr const_reference y() const noexcept { return data[1]; }

        constexpr reference z() noexcept { return data[2]; }
        constexpr const_reference z() const noexcept { return data[2]; }

        // Iterators - reuse the definitions from the internal array
        constexpr iterator begin() noexcept { return data.begin(); }
        constexpr const_iterator begin() const noexcept { return data.begin(); }
        constexpr const_iterator cbegin() const noexcept { return data.cbegin(); }

        constexpr iterator end() noexcept { return data.end(); }
        constexpr const_iterator end() const noexcept { return data.end(); }
        constexpr const_iterator cend() const noexcept { return data.cend(); }

        // Capacity - these are fixed due to our definition of the internal array
        constexpr bool empty() const noexcept { return false; }
        constexpr size_type size() const noexcept { return 3; }
        constexpr size_type max_size() const noexcept { return 3; }

        // Operations - reuse the definitions from the internal array
        constexpr void fill(const_reference value) { data.fill(value); }
        constexpr void swap(Vector3D<T>& other) { data.swap(other.data); }
    };

    // Specific getters for use in the tuple-like API, allows for the structured binding of a Vector3D
    template<std::size_t Index, typename T>
    decltype(auto) get(Vector3D<T>& vec)
    {
        static_assert(Index < 3, "Index must be within 0 and 2, inclusive.");

        if constexpr (Index == 0)
            return vec.x();
        else if constexpr (Index == 1)
            return vec.y();
        else
            return vec.z();
    }

    template<std::size_t Index, typename T>
    decltype(auto) get(const Vector3D<T>& vec)
    {
        static_assert(Index < 3, "Index must be within 0 and 2, inclusive.");

        if constexpr (Index == 0)
            return vec.x();
        else if constexpr (Index == 1)
            return vec.y();
        else
            return vec.z();
    }

    template<std::size_t Index, typename T>
    decltype(auto) get(Vector3D<T>&& vec)
    {
        static_assert(Index < 3, "Index must be within 0 and 2, inclusive.");

        if constexpr (Index == 0)
            return std::move(vec.x());
        else if constexpr (Index == 1)
            return std::move(vec.y());
        else
            return std::move(vec.z());
    }
}   // namespace CppUtils::Math


// Specializations of the remaining requirements for access to the tuple-like API
template<typename T>
struct std::tuple_size<CppUtils::Math::Vector3D<T>>
{
    static constexpr int value = 3;
};

template<std::size_t Index, typename T>
struct std::tuple_element<Index, CppUtils::Math::Vector3D<T>>
{
    using type = T;
};

#endif
