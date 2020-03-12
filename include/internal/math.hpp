// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: math.hpp - Version 1.0.0
// Author: crdrisko
// Date: 03/03/2020-18:45:41
// Description: Mathematical functions from various math libraries adapted for PhysicalQuantities

#ifndef CPP_UNITS_MATH_HPP
#define CPP_UNITS_MATH_HPP

#include <algorithm>
#include <cmath>
#include <memory>
#include <vector>

#include <utils-api/math.hpp>

#include "physicalQuantity.hpp"

namespace PhysicalQuantities::Math
{
    // For cmath functions that would ordinarily accept and return only dimensionless quantities
    #define DeclareNewCMathOverload(NAME)                                                               \
        inline auto NAME(const PhysicalQuantity< Dimensionality<> >& physicalQuantity)                  \
        {                                                                                               \
            return PhysicalQuantity< Dimensionality<> >( std::NAME(physicalQuantity.getMagnitude()) );  \
        }

    DeclareNewCMathOverload(exp)
    DeclareNewCMathOverload(log)
    DeclareNewCMathOverload(log10)
    DeclareNewCMathOverload(sin)
    DeclareNewCMathOverload(cos)
    DeclareNewCMathOverload(tan)
    DeclareNewCMathOverload(sqrt)
    DeclareNewCMathOverload(cbrt)


    template <int L, int M, int T, int I, int Th, int N, int J>
    constexpr auto abs(const PhysicalQuantity< Dimensionality<L, M, T, I, Th, N, J> >& physicalQuantity)
    {
        return PhysicalQuantity< Dimensionality<L, M, T, I, Th, N, J> >(std::abs(physicalQuantity.getMagnitude()));
    }


    template <typename TReturn, int L, int M, int T, int I, int Th, int N, int J>
    constexpr auto pow(const PhysicalQuantity< Dimensionality<L, M, T, I, Th, N, J> >& physicalQuantity, int power)
    {
        return TReturn( std::pow(physicalQuantity.getMagnitude(), power) );
    }


    // Alternatives to pow with automatic return-type deduction
    template <int L, int M, int T, int I, int Th, int N, int J>
    constexpr auto square(const PhysicalQuantity< Dimensionality<L, M, T, I, Th, N, J> >& physicalQuantity)
    {
        return physicalQuantity * physicalQuantity;
    }

    template <int L, int M, int T, int I, int Th, int N, int J>
    constexpr auto cube(const PhysicalQuantity< Dimensionality<L, M, T, I, Th, N, J> >& physicalQuantity)
    {
        return physicalQuantity * physicalQuantity * physicalQuantity;
    }


    // Advanced mathematical functions that act on vector(s) of physical quantities
    template <int L, int M, int T, int I, int Th, int N, int J>
    inline auto convertQuantitiesToMagnitudes(const std::vector< PhysicalQuantity< Dimensionality<L, M, T, I,
        Th, N, J> > >& physicalQuantities)
    {
        std::vector<long double> magnitudes(physicalQuantities.size());

        std::transform(physicalQuantities.begin(), physicalQuantities.end(), magnitudes.begin(),
            [](const PhysicalQuantity< Dimensionality<L, M, T, I, Th, N, J> >& physicalQuantity)
                { return physicalQuantity.getMagnitude(); });

        return magnitudes;
    }


    template <int L, int M, int T, int I, int Th, int N, int J>
    constexpr auto calculateAverage(const std::vector< PhysicalQuantity< Dimensionality<L, M, T, I,
        Th, N, J> > >& physicalQuantities)
    {
        return PhysicalQuantity< Dimensionality<L, M, T, I, Th, N, J> >( Utilities_API::Math::calculateAverage(
            convertQuantitiesToMagnitudes(physicalQuantities)) );
    }

    template <int L, int M, int T, int I, int Th, int N, int J>
    constexpr auto calculateStandardDeviation(const std::vector< PhysicalQuantity< Dimensionality<L, M, T, I,
        Th, N, J> > >& physicalQuantities)
    {
        return PhysicalQuantity< Dimensionality<L, M, T, I, Th, N, J> >(
            Utilities_API::Math::calculateStandardDeviation(convertQuantitiesToMagnitudes(physicalQuantities)) );
    }


    template <typename TReturn, class AdvancedMathFunction,
              int L1, int M1, int T1, int I1, int Th1, int N1, int J1,
              int L2, int M2, int T2, int I2, int Th2, int N2, int J2>
    inline auto mathematicalFunction(const std::vector< PhysicalQuantity< Dimensionality<L1, M1, T1, I1, Th1,
        N1, J1> > >& x, const std::vector< PhysicalQuantity< Dimensionality<L2, M2, T2, I2, Th2, N2, J2> > >& y)
    {
        std::vector<long double> x_magnitudes { convertQuantitiesToMagnitudes(x) };
        std::vector<long double> y_magnitudes { convertQuantitiesToMagnitudes(y) };

        Utilities_API::Math::AdvancedMathPtr mathematicalFunction
            = std::make_shared<AdvancedMathFunction>(x_magnitudes, y_magnitudes);

        std::vector<TReturn> results(x.size());
        std::vector<long double> resultsMagnitudes { mathematicalFunction->doCalculation() };

        std::transform(resultsMagnitudes.begin(), resultsMagnitudes.end(), results.begin(),
            [](long double resultMagnitude) { return TReturn(resultMagnitude); });

        return results;
    }


    template <int L1, int M1, int T1, int I1, int Th1, int N1, int J1,
              int L2, int M2, int T2, int I2, int Th2, int N2, int J2>
    constexpr auto centeredDifferenceMethod(const std::vector< PhysicalQuantity< Dimensionality<L1, M1, T1, I1,
        Th1, N1, J1> > >& x, const std::vector< PhysicalQuantity< Dimensionality<L2, M2, T2, I2, Th2, N2, J2> > >& y)
    {
        return mathematicalFunction<PhysicalQuantity< Dimensionality<L2 - L1, M2 - M1, T2 - T1, I2 - I1, Th2 - Th1,
            N2 - N1, J2 - J1> >, Utilities_API::Math::CenteredDifferenceMethod>(x, y);
    }

    template <int L1, int M1, int T1, int I1, int Th1, int N1, int J1,
              int L2, int M2, int T2, int I2, int Th2, int N2, int J2>
    constexpr auto cumulativeTrapzIntegration(const std::vector< PhysicalQuantity< Dimensionality<L1, M1, T1, I1,
        Th1, N1, J1> > >& x, const std::vector< PhysicalQuantity< Dimensionality<L2, M2, T2, I2, Th2, N2, J2> > >& y)
    {
        return mathematicalFunction<PhysicalQuantity< Dimensionality<L2 + L1, M2 + M1, T2 + T1, I2 + I1, Th2 + Th1,
            N2 + N1, J2 + J1> >, Utilities_API::Math::CumulativeTrapzIntegration>(x, y);
    }

    template <int L1, int M1, int T1, int I1, int Th1, int N1, int J1,
              int L2, int M2, int T2, int I2, int Th2, int N2, int J2>
    constexpr auto linearLeastSquaresFitting(const std::vector< PhysicalQuantity< Dimensionality<L1, M1, T1, I1,
        Th1, N1, J1> > >& x, const std::vector< PhysicalQuantity< Dimensionality<L2, M2, T2, I2, Th2, N2, J2> > >& y)
    {
        return mathematicalFunction<PhysicalQuantity< Dimensionality<L2 - L1, M2 - M1, T2 - T1, I2 - I1, Th2 - Th1,
            N2 - N1, J2 - J1> >, Utilities_API::Math::LinearLeastSquaresFitting>(x, y);
    }


    // Limit the scope of the preprocessing macros we used by undefining them here
    #undef DeclareNewCMathOverload
}

#endif
