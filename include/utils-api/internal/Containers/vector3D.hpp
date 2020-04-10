// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: vector3D.hpp - Version 1.0.0
// Author: crdrisko
// Date: 04/07/2020-11:08:41
// Description: A vector representing a physical quantity with x, y, and z components

#ifndef UTILITIES_API_VECTOR3D_HPP
#define UTILITIES_API_VECTOR3D_HPP

#include <array>
#include <utility>

#include "../../errors.hpp"
#include "../../math.hpp"

namespace Utilities_API::Containers
{
    template <typename T>
    class Vector3D
    {
    private:
        std::array<T, 3> data {};

    public:
        constexpr Vector3D() = default;
        constexpr explicit Vector3D(const std::array<T, 3>& Data) : data{Data} {}
        constexpr Vector3D(const T& X, const T& Y, const T& Z) : Vector3D{ {X, Y, Z} } {}

        // Could throw an exception based on the value of index
        constexpr const T& operator[](unsigned int index) const
        {
            if ( !Math::withinRange<0, 2>(index) )
                throw Errors::InvalidInputException{"Utilities-API",
                    "Vector3D index must be within 0 and 2."};

            return data[index];
        }

        constexpr T& operator[](unsigned int index)
        {
            return const_cast<T&>( std::as_const(*this)[index] );
        }

        constexpr T x() const { return data[0]; }
        constexpr T& x() { return data[0]; }

        constexpr T y() const { return data[1]; }
        constexpr T& y() { return data[1]; }

        constexpr T z() const { return data[2]; }
        constexpr T& z() { return data[2]; }
    };
}

#endif
