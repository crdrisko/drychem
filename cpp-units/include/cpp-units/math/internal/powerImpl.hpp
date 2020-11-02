// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: powerImpl.hpp
// Author: crdrisko
// Date: 08/25/2020-16:41:09
// Description: Helper templates for compile-time calculations of powers of PhysicalQuantities

#ifndef CPP_UNITS_POWERIMPL_HPP
#define CPP_UNITS_POWERIMPL_HPP

#include "types/physicalQuantity.hpp"

namespace CppUnits::Math::Internal
{
    template<unsigned int Power, int L, int M, int T, int I, int Th, int N, int J>
    struct PowImpl
    {
        static constexpr auto result(const PhysicalQuantity<Dimensionality<L, M, T, I, Th, N, J>>& physicalQuantity) noexcept
        {
            return physicalQuantity * PowImpl<Power - 1, L, M, T, I, Th, N, J>::result(physicalQuantity);
        }
    };

    // Partial template specialization for termination condition
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
}   // namespace CppUnits::Math::Internal

#endif
