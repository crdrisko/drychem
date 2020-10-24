// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: basicMath.hpp
// Author: crdrisko
// Date: 08/25/2020-20:21:04
// Description: Function overloads for common mathematical operations in the cmath standard library header

#ifndef CPP_UNITS_BASICMATH_HPP
#define CPP_UNITS_BASICMATH_HPP

#include <cmath>

#include "math/internal/powerImpl.hpp"
#include "types/physicalQuantity.hpp"

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
    template<int Power, int L, int M, int T, int I, int Th, int N, int J>
    constexpr auto pow(const PhysicalQuantity<Dimensionality<L, M, T, I, Th, N, J>>& physicalQuantity) noexcept
    {
        if constexpr (Power >= 0)
            return Internal::PowImpl<Power, L, M, T, I, Th, N, J>::result(physicalQuantity);
        else
            return Internal::InversePowImpl<Power, L, M, T, I, Th, N, J>::result(physicalQuantity);
    }

    DECLARE_DIMENSIONLESS_CMATH_FUNCTION(sqrt)
    DECLARE_DIMENSIONLESS_CMATH_FUNCTION(cbrt)

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
