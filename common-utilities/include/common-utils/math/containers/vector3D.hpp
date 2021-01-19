// Copyright (c) 2020-2021 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: vector3D.hpp
// Author: crdrisko
// Date: 04/07/2020-11:08:41
// Description: A vector representing a quantity with x, y, and z components

#ifndef DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_MATH_CONTAINERS_VECTOR3D_HPP
#define DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_MATH_CONTAINERS_VECTOR3D_HPP

#include <array>
#include <cstddef>
#include <type_traits>
#include <utility>

#include "common-utils/utilities/operators/comparisonOperators.hpp"

namespace CppUtils::Math
{
    /*!
     * A container adapter class for a mathematical/physical vector with three dimensions: x, y, z. For the most
     *  part, the functionality is delegated to the internal \c std::array<> and the type is defined using the 
     *  tuple-like API so it can be used with structured bindings.
     * 
     * \tparam T - The type of the value we are storing in the \c Vector3D, must be default constructible
     * 
     * \todo Add arithmetic operators (possibly using expression templates)
     * \note The reverse iterators were not added to the interface because I didn't see a need for them
     *       at the time. If they are needed, they should be simple to add back in.
     */
    template<typename T, typename = std::enable_if_t<std::is_default_constructible_v<T>>>
    class Vector3D : private Operators::CompletelyComparable<Vector3D<T>>
    {
    public:
        //! Member types
        using value_type      = T;
        using size_type       = std::size_t;
        using difference_type = std::ptrdiff_t;
        using reference       = typename std::array<T, 3>::reference;
        using const_reference = typename std::array<T, 3>::const_reference;
        using pointer         = typename std::array<T, 3>::pointer;
        using const_pointer   = typename std::array<T, 3>::const_pointer;
        using iterator        = typename std::array<T, 3>::iterator;
        using const_iterator  = typename std::array<T, 3>::const_iterator;

        //! With this member type, we are now both a container and container adapter
        using container_type = std::array<T, 3>;

    private:
        std::array<T, 3> data {};

    public:
        //! Constructors
        constexpr Vector3D() noexcept = default;
        constexpr Vector3D(T x_, T y_, T z_) noexcept : data {{x_, y_, z_}} {}
        constexpr explicit Vector3D(const container_type& data_) noexcept : data {data_} {}

        //! Comparison operators - reuse the definitions from the internal array
        constexpr friend bool operator==(const Vector3D<T>& lhs_, const Vector3D<T>& rhs_) { return lhs_.data == rhs_.data; }
        constexpr friend bool operator<(const Vector3D<T>& lhs_, const Vector3D<T>& rhs_) { return lhs_.data < rhs_.data; }

        //! Element access - reuse the definitions from the internal array
        constexpr reference at(size_type pos_) { return data.at(pos_); }               //! Could throw: array::at
        constexpr const_reference at(size_type pos_) const { return data.at(pos_); }   //! Could throw: array::at

        constexpr reference operator[](size_type pos_) noexcept { return data[pos_]; }
        constexpr const_reference operator[](size_type pos_) const noexcept { return data[pos_]; }

        //! Iterators - reuse the definitions from the internal array
        constexpr iterator begin() noexcept { return data.begin(); }
        constexpr const_iterator begin() const noexcept { return data.begin(); }
        constexpr const_iterator cbegin() const noexcept { return data.cbegin(); }

        constexpr iterator end() noexcept { return data.end(); }
        constexpr const_iterator end() const noexcept { return data.end(); }
        constexpr const_iterator cend() const noexcept { return data.cend(); }

        //! Capacity - these are fixed due to our definition of the internal array
        constexpr bool empty() const noexcept { return false; }
        constexpr size_type size() const noexcept { return 3; }
        constexpr size_type max_size() const noexcept { return 3; }

        //! Operations - reuse the definitions from the internal array
        constexpr void fill(const_reference value_) { data.fill(value_); }
        constexpr void swap(Vector3D<T>& other_) { data.swap(other_.data); }
    };

    /*!
     * Specific getters for use in the tuple-like API, allows for the structured binding of a \c Vector3D
     */
    template<std::size_t Index, typename T>
    decltype(auto) get(Vector3D<T>& vec)
    {
        static_assert(Index < 3, "Index must be within 0 and 2, inclusive.");

        if constexpr (Index == 0)
            return vec[0];
        else if constexpr (Index == 1)
            return vec[1];
        else
            return vec[2];
    }

    /*!
     * \overload
     */
    template<std::size_t Index, typename T>
    decltype(auto) get(const Vector3D<T>& vec)
    {
        static_assert(Index < 3, "Index must be within 0 and 2, inclusive.");

        if constexpr (Index == 0)
            return vec[0];
        else if constexpr (Index == 1)
            return vec[1];
        else
            return vec[2];
    }

    /*!
     * \overload
     */
    template<std::size_t Index, typename T>
    decltype(auto) get(Vector3D<T>&& vec)
    {
        static_assert(Index < 3, "Index must be within 0 and 2, inclusive.");

        if constexpr (Index == 0)
            return std::move(vec[0]);
        else if constexpr (Index == 1)
            return std::move(vec[1]);
        else
            return std::move(vec[2]);
    }
}   // namespace CppUtils::Math


//! Specializations of the remaining requirements for access to the tuple-like API
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
