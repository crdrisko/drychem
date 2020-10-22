// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: physicalQuantity.hpp
// Author: crdrisko
// Date: 03/03/2020-18:45:26
// Description: Defines the PhysicalQuantity class template with SI base units

#ifndef CPP_UNITS_PHYSICALQUANTITY_HPP
#define CPP_UNITS_PHYSICALQUANTITY_HPP

#include <iostream>
#include <string>
#include <string_view>

#include <common-utils/utilities.hpp>

#include "types/dimensionality.hpp"
// #include "conversions/conversions.hpp"

using CppUtils::Operators::CompletelyComparable;

namespace CppUnits
{
    template<typename BaseDimensionality>
    class PhysicalQuantity : private CompletelyComparable<PhysicalQuantity<BaseDimensionality>>
    {
    private:
        long double magnitude {0.0l};

    public:
        using DimensionalityType = typename BaseDimensionality::Type;

        constexpr PhysicalQuantity() noexcept = default;
        constexpr explicit PhysicalQuantity(long double Magnitude) noexcept : magnitude {Magnitude} {}

        constexpr explicit PhysicalQuantity(std::string_view Magnitude)
        {
            magnitude = std::stold(std::string {Magnitude});   // This particular conversion could throw
        }

        constexpr long double getMagnitude() const noexcept { return magnitude; }
        constexpr void setMagnitude(long double Magnitude) noexcept { magnitude = Magnitude; }

        // Comparison Operators
        constexpr friend bool operator==(const PhysicalQuantity<BaseDimensionality>& lhs,
            const PhysicalQuantity<BaseDimensionality>& rhs) noexcept
        {
            return lhs.magnitude == rhs.magnitude;
        }

        constexpr friend bool operator<(const PhysicalQuantity<BaseDimensionality>& lhs,
            const PhysicalQuantity<BaseDimensionality>& rhs) noexcept
        {
            return lhs.magnitude < rhs.magnitude;
        }

        // Arithmetic Operators
        constexpr auto operator+=(const PhysicalQuantity<BaseDimensionality>& rhs) noexcept
        {
            magnitude += rhs.magnitude;
            return *this;
        }

        constexpr auto operator+(const PhysicalQuantity<BaseDimensionality>& rhs) const noexcept
        {
            return PhysicalQuantity<BaseDimensionality>(*this) += rhs;
        }

        constexpr auto operator-=(const PhysicalQuantity<BaseDimensionality>& rhs) noexcept
        {
            magnitude -= rhs.magnitude;
            return *this;
        }

        constexpr auto operator-(const PhysicalQuantity<BaseDimensionality>& rhs) const noexcept
        {
            return PhysicalQuantity<BaseDimensionality>(*this) -= rhs;
        }

        constexpr auto operator-() noexcept
        {
            magnitude *= -1.0;
            return *this;
        }

        /* Physical quantities and dimensionless quantities can only be multiplied or divided by each other,
            adding or subtracting is an error due to a dimensionality mismatch */
        constexpr auto operator*(long double rhs) const noexcept
        {
            return (*this) * PhysicalQuantity<Dimensionality<>>(rhs);
        }

        constexpr auto operator*=(long double rhs) noexcept
        {
            magnitude *= rhs;
            return *this;
        }

        constexpr auto operator*=(const PhysicalQuantity<Dimensionality<>>& rhs) noexcept
        {
            magnitude *= rhs.getMagnitude();
            return *this;
        }

        constexpr auto operator/(long double rhs) const noexcept
        {
            return (*this) / PhysicalQuantity<Dimensionality<>>(rhs);
        }

        constexpr auto operator/=(long double rhs) noexcept
        {
            magnitude /= rhs;
            return *this;
        }

        constexpr auto operator/=(const PhysicalQuantity<Dimensionality<>>& rhs) noexcept
        {
            magnitude /= rhs.getMagnitude();
            return *this;
        }

        // Output Stream Operators
        constexpr friend std::ostream& operator<<(std::ostream& stream, const PhysicalQuantity<BaseDimensionality>& rhs)
        {
            stream << rhs.magnitude;
            return stream;
        }

        // // Unit Conversions
        // constexpr auto convertQuantity(const std::string& initialUnits, const std::string& finalUnits) const
        // {
        //     const Conversions::Conversion conversion {};

        //     return PhysicalQuantity<BaseDimensionality>( conversion.convertQuantity(this->magnitude, initialUnits,
        //         finalUnits) );
        // }
    };

    template<int L1, int M1, int T1, int I1, int Th1, int N1, int J1,
             int L2, int M2, int T2, int I2, int Th2, int N2, int J2>
    constexpr auto operator*(const PhysicalQuantity<Dimensionality<L1, M1, T1, I1, Th1, N1, J1>>& lhs,
        const PhysicalQuantity<Dimensionality<L2, M2, T2, I2, Th2, N2, J2>>& rhs) noexcept
    {
        return PhysicalQuantity<Dimensionality<L1 + L2, M1 + M2, T1 + T2, I1 + I2, Th1 + Th2, N1 + N2, J1 + J2>>(
            lhs.getMagnitude() * rhs.getMagnitude());
    }

    template<int L, int M, int T, int I, int Th, int N, int J>
    constexpr auto operator*(long double lhs, const PhysicalQuantity<Dimensionality<L, M, T, I, Th, N, J>>& rhs) noexcept
    {
        return PhysicalQuantity<Dimensionality<>>(lhs) * rhs;
    }

    template<int L1, int M1, int T1, int I1, int Th1, int N1, int J1,
             int L2, int M2, int T2, int I2, int Th2, int N2, int J2>
    constexpr auto operator/(const PhysicalQuantity<Dimensionality<L1, M1, T1, I1, Th1, N1, J1>>& lhs,
        const PhysicalQuantity<Dimensionality<L2, M2, T2, I2, Th2, N2, J2>>& rhs) noexcept
    {
        return PhysicalQuantity<Dimensionality<L1 - L2, M1 - M2, T1 - T2, I1 - I2, Th1 - Th2, N1 - N2, J1 - J2>>(
            lhs.getMagnitude() / rhs.getMagnitude());
    }

    template<int L, int M, int T, int I, int Th, int N, int J>
    constexpr auto operator/(long double lhs, const PhysicalQuantity<Dimensionality<L, M, T, I, Th, N, J>>& rhs) noexcept
    {
        return PhysicalQuantity<Dimensionality<>>(lhs) / rhs;
    }
}   // namespace PhysicalQuantities

#endif
