// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: physicalQuantity.hpp - Version 1.0.0
// Author: crdrisko
// Date: 03/03/2020-18:45:26
// Description: Defines the PhysicalQuantity class template with SI base units

#ifndef CPP_UNITS_PHYSICALQUANTITY_HPP
#define CPP_UNITS_PHYSICALQUANTITY_HPP

#include <string>
#include <utility>
#include <iostream>

#include <utils-api/errors.hpp>

using namespace std::rel_ops;           // Allow unqualified comparison operators

namespace PhysicalQuantities
{
    template <int L = 0, int M = 0, int T = 0, int I = 0, int Th = 0, int N = 0, int J = 0>
    struct Dimensionality
    {
        enum { Length = L, Mass = M, Time = T, ElectricCurrent = I, Temperature = Th,
               AmountOfSubstance = N, LuminousIntensity = J };
    };


    template <typename BaseDimensionality>
    class PhysicalQuantity
    {
    private:
        long double magnitude {0.0};

    public:
        constexpr PhysicalQuantity() = default;
        constexpr explicit PhysicalQuantity(long double Magnitude) noexcept : magnitude{Magnitude} {}
        constexpr explicit PhysicalQuantity(const std::string& Magnitude) { magnitude = std::stold(Magnitude); }

        constexpr long double getMagnitude() const noexcept { return magnitude; }
        constexpr void setMagnitude(long double Magnitude) noexcept { magnitude = Magnitude; }

        // Comparison Operators
        constexpr bool operator==(const PhysicalQuantity<BaseDimensionality>& rhs) const noexcept
        {
            return (magnitude == rhs.getMagnitude());
        }

        constexpr bool operator<(const PhysicalQuantity<BaseDimensionality>& rhs) const noexcept
        {
            return (magnitude < rhs.getMagnitude());
        }

        // Arithmetic Operators
        constexpr auto operator+=(const PhysicalQuantity<BaseDimensionality>& rhs) noexcept
        {
            magnitude += rhs.getMagnitude();
            return *this;
        }

        constexpr auto operator+(const PhysicalQuantity<BaseDimensionality>& rhs) const noexcept
        {
            return PhysicalQuantity<BaseDimensionality>(*this) += rhs;
        }

        constexpr auto operator-=(const PhysicalQuantity<BaseDimensionality>& rhs) noexcept
        {
            magnitude -= rhs.getMagnitude();
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

        // constexpr explicit operator long double() const noexcept
        // {
        //     return magnitude;
        // }

        constexpr auto convertQuantity(PhysicalQuantity< Dimensionality<> > conversionFactor,
            long double externalShearingFactor = 0.0, long double internalShearingFactor = 0.0) const noexcept
        {
            return PhysicalQuantity<BaseDimensionality>( ((magnitude + internalShearingFactor)
                * conversionFactor.getMagnitude()) + externalShearingFactor );
        }
    };


    template <int L1, int M1, int T1, int I1, int Th1, int N1, int J1,
              int L2, int M2, int T2, int I2, int Th2, int N2, int J2>
    constexpr auto operator*(const PhysicalQuantity< Dimensionality<L1, M1, T1, I1, Th1, N1, J1> >& lhs,
        const PhysicalQuantity< Dimensionality<L2, M2, T2, I2, Th2, N2, J2> >& rhs) noexcept
    {
        return PhysicalQuantity< Dimensionality<L1 + L2, M1 + M2, T1 + T2, I1 + I2, Th1 + Th2,
                N1 + N2, J1 + J2> >(lhs.getMagnitude() * rhs.getMagnitude());
    }

    template <int L1, int M1, int T1, int I1, int Th1, int N1, int J1,
              int L2, int M2, int T2, int I2, int Th2, int N2, int J2>
    constexpr auto operator/(const PhysicalQuantity< Dimensionality<L1, M1, T1, I1, Th1, N1, J1> >& lhs,
        const PhysicalQuantity< Dimensionality<L2, M2, T2, I2, Th2, N2, J2> >& rhs) noexcept
    {
        return PhysicalQuantity< Dimensionality<L1 - L2, M1 - M2, T1 - T2, I1 - I2, Th1 - Th2,
                N1 - N2, J1 - J2> >(lhs.getMagnitude() / rhs.getMagnitude());
    }

    template <int L, int M, int T, int I, int Th, int N, int J>
    constexpr std::ostream& operator<<(std::ostream& stream, const PhysicalQuantity< Dimensionality<L, M, T,
        I, Th, N, J> >& physicalQuantity)
    {
        stream << physicalQuantity.getMagnitude();
        return stream;
    }
}

#endif
