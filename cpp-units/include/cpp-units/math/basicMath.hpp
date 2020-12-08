// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: basicMath.hpp
// Author: crdrisko
// Date: 08/25/2020-20:21:04
// Description: Function overloads for common mathematical operations in the cmath standard library header

#ifndef DRYCHEM_CPP_UNITS_INCLUDE_CPP_UNITS_MATH_BASICMATH_HPP
#define DRYCHEM_CPP_UNITS_INCLUDE_CPP_UNITS_MATH_BASICMATH_HPP

#include <cmath>

#include "cpp-units/types/physicalQuantity.hpp"

namespace CppUnits::Math
{
#define DECLARE_CMATH_FUNCTION(NAME)                                                                                        \
    template<int L, int M, int T, int I, int Th, int N, int J>                                                              \
    constexpr auto NAME(const PhysicalQuantity<Dimensionality<L, M, T, I, Th, N, J>>& physicalQuantity) noexcept            \
    {                                                                                                                       \
        return PhysicalQuantity<Dimensionality<L, M, T, I, Th, N, J>>(std::NAME(physicalQuantity.getMagnitude()));          \
    }

#define DECLARE_DIMENSIONLESS_CMATH_FUNCTION(NAME)                                                                          \
    template<int L, int M, int T, int I, int Th, int N, int J>                                                              \
    constexpr auto NAME(const PhysicalQuantity<Dimensionality<L, M, T, I, Th, N, J>>& physicalQuantity) noexcept            \
    {                                                                                                                       \
        return PhysicalQuantity<Dimensionality<>>(std::NAME(physicalQuantity.getMagnitude()));                              \
    }

    // Basic operations
    DECLARE_CMATH_FUNCTION(abs)

    // Exponential functions
    DECLARE_DIMENSIONLESS_CMATH_FUNCTION(exp)
    DECLARE_DIMENSIONLESS_CMATH_FUNCTION(exp2)
    DECLARE_DIMENSIONLESS_CMATH_FUNCTION(log)
    DECLARE_DIMENSIONLESS_CMATH_FUNCTION(log2)
    DECLARE_DIMENSIONLESS_CMATH_FUNCTION(log10)

    // Power functions
    namespace details
    {
        template<unsigned int Power, int L, int M, int T, int I, int Th, int N, int J>
        struct PowImpl
        {
            static constexpr auto result(const PhysicalQuantity<Dimensionality<L, M, T, I, Th, N, J>>& physicalQuantity) noexcept
            {
                return physicalQuantity * PowImpl<Power - 1, L, M, T, I, Th, N, J>::result(physicalQuantity);
            }
        };

        template<int L, int M, int T, int I, int Th, int N, int J>
        struct PowImpl<0, L, M, T, I, Th, N, J>
        {
            static constexpr auto result(const PhysicalQuantity<Dimensionality<L, M, T, I, Th, N, J>>&) noexcept
            {
                return PhysicalQuantity<Dimensionality<>>(1.0);
            }
        };

        template<int Power, int L, int M, int T, int I, int Th, int N, int J>
        struct InversePowImpl
        {
            static constexpr auto result(const PhysicalQuantity<Dimensionality<L, M, T, I, Th, N, J>>& physicalQuantity) noexcept
            {
                return 1.0 / (PowImpl<-Power, L, M, T, I, Th, N, J>::result(physicalQuantity));
            }
        };
    }   // namespace details

    template<int Power, int L, int M, int T, int I, int Th, int N, int J>
    constexpr auto pow(const PhysicalQuantity<Dimensionality<L, M, T, I, Th, N, J>>& physicalQuantity) noexcept
    {
        if constexpr (Power >= 0)
            return details::PowImpl<Power, L, M, T, I, Th, N, J>::result(physicalQuantity);
        else
            return details::InversePowImpl<Power, L, M, T, I, Th, N, J>::result(physicalQuantity);
    }

    template<int L, int M, int T, int I, int Th, int N, int J,
             typename = std::enable_if_t<(L % 2 == 0) && (M % 2 == 0) && (T % 2 == 0) && (I % 2 == 0) && (Th % 2 == 0)
                                      && (N % 2 == 0) && (J % 2 == 0)>>
    constexpr auto sqrt(const PhysicalQuantity<Dimensionality<L, M, T, I, Th, N, J>>& physicalQuantity) noexcept
    {
        using TReturn = PhysicalQuantity<Dimensionality<L / 2, M / 2, T / 2, I / 2, Th / 2, N / 2, J / 2>>;
        return TReturn {std::sqrt(physicalQuantity.getMagnitude())};
    }

    template<int L, int M, int T, int I, int Th, int N, int J,
             typename = std::enable_if_t<(L % 3 == 0) && (M % 3 == 0) && (T % 3 == 0) && (I % 3 == 0) && (Th % 3 == 0)
                                      && (N % 3 == 0) && (J % 3 == 0)>>
    constexpr auto cbrt(const PhysicalQuantity<Dimensionality<L, M, T, I, Th, N, J>>& physicalQuantity) noexcept
    {
        using TReturn = PhysicalQuantity<Dimensionality<L / 3, M / 3, T / 3, I / 3, Th / 3, N / 3, J / 3>>;
        return TReturn {std::cbrt(physicalQuantity.getMagnitude())};
    }

    // Trigonometric functions
    DECLARE_DIMENSIONLESS_CMATH_FUNCTION(sin)
    DECLARE_DIMENSIONLESS_CMATH_FUNCTION(cos)
    DECLARE_DIMENSIONLESS_CMATH_FUNCTION(tan)
    DECLARE_DIMENSIONLESS_CMATH_FUNCTION(asin)
    DECLARE_DIMENSIONLESS_CMATH_FUNCTION(acos)
    DECLARE_DIMENSIONLESS_CMATH_FUNCTION(atan)

    // Hyperbolic functions
    DECLARE_DIMENSIONLESS_CMATH_FUNCTION(sinh)
    DECLARE_DIMENSIONLESS_CMATH_FUNCTION(cosh)
    DECLARE_DIMENSIONLESS_CMATH_FUNCTION(tanh)
    DECLARE_DIMENSIONLESS_CMATH_FUNCTION(asinh)
    DECLARE_DIMENSIONLESS_CMATH_FUNCTION(acosh)
    DECLARE_DIMENSIONLESS_CMATH_FUNCTION(atanh)

#undef DECLARE_CMATH_FUNCTION
#undef DECLARE_DIMENSIONLESS_CMATH_FUNCTION
}   // namespace CppUnits::Math

#endif
