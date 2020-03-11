// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: testMathFunctions.cpp - Version 1.0.0
// Author: crdrisko
// Date: 03/04/2020-07:50:11
// Description: Provides 100% unit test coverage over all mathematical functions for the PhysicalQuantities

#include <vector>

#include <gtest/gtest.h>
#include <utils-api/math.hpp>

#include "../../include/physicalQuantities.hpp"

using namespace PhysicalQuantities;
using namespace PhysicalQuantities::Literals;

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(testMathFunctions, nonPositiveInputErrorsInNaturalLogAreCaughtAndThrowAnError)
{
    Length length = 1.0_m;
    ASSERT_DOUBLE_EQ(0.0, Math::log(length).getMagnitude());

    ASSERT_DEATH(
    {
        Math::log(-1.0_m);
    }, "CPP-Units:\n\tThe value inside the natural logarithm must be positive.");
}

TEST(testMathFunctions, powFunctionRaisesTheMagnitudeToAGivenPower)
{
    Length length = 5.0_m;

    WaveNumber waveNumber = Math::pow<WaveNumber>(length, -1);
    DimensionlessQuantity dimensionlessQuantity = Math::pow<DimensionlessQuantity>(length, 0);

    ASSERT_DOUBLE_EQ(0.2, waveNumber.getMagnitude());
    ASSERT_DOUBLE_EQ(1.0, dimensionlessQuantity.getMagnitude());
}

TEST(testMathFunctions, specializationsOfPowWithAutomaticTypeDeduction)
{
    Length length = 5.0_m;

    ASSERT_DOUBLE_EQ(25.0, Math::square(length).getMagnitude());
    ASSERT_TRUE(Math::square(length) == Math::pow<Area>(length, 2));

    ASSERT_DOUBLE_EQ(125.0, Math::cube(length).getMagnitude());
    ASSERT_TRUE(Math::cube(length) == Math::pow<Volume>(length, 3));
}

TEST(testMathFunctions, centeredDifferenceMethodOverload)
{
    std::vector<Length> lengthVectorForDerivative { 1.0_m, 2.0_m, 3.0_m, 4.0_m, 5.0_m };
    std::vector<Concentration> concentrationVector { 1.0_M, 2.0_M, 3.0_M, 4.0_M, 5.0_M };
    std::vector<long double> expectedDerivativeResults { 1.0, 1.0, 1.0, 1.0, 1.0 };

    std::vector<ConcentrationGradient> derivativeVector
        = Math::centeredDifferenceMethod(lengthVectorForDerivative, concentrationVector);

    std::vector<long double> actualDerivativeResults;

    for (const auto& result : derivativeVector)
        actualDerivativeResults.push_back( result.getMagnitude() );

    ASSERT_EQ(expectedDerivativeResults, actualDerivativeResults);
}

TEST(testMathFunctions, linearLeastSquaresFittingOverload)
{
    std::vector<Length> lengthVectorForFitting { 0.0_m, 1.0_m, 2.0_m, 3.0_m, 4.0_m, 5.0_m };
    std::vector<Concentration> concentrationVector { 2.0_M, 7.0_M, 3.0_M, 5.0_M, 6.0_M, 10.0_M };

    std::vector<ConcentrationGradient> fittingParameters
        = Math::linearLeastSquaresFitting(lengthVectorForFitting, concentrationVector);

    ASSERT_NEAR(1.1143, fittingParameters[0].getMagnitude(), Utilities_API::Math::findAbsoluteError(1.1143, 5));
    ASSERT_NEAR(2.7143, fittingParameters[1].getMagnitude(), Utilities_API::Math::findAbsoluteError(2.7143, 5));
    ASSERT_NEAR(0.5314593, fittingParameters[2].getMagnitude(), Utilities_API::Math::findAbsoluteError(0.53146, 5));
}

TEST(testMathFunctions, cumulativeTrapzIntegrationOverload)
{
    std::vector<Length> lengthVectorForIntegration { 1.0_m, 2.0_m, 3.0_m, 4.0_m, 5.0_m };
    std::vector<ElectricField> eFieldVector { 1.0_V_m, 2.0_V_m, 3.0_V_m, 4.0_V_m, 5.0_V_m };

    std::vector<double> expectedIntegralResults { 0.0, 1.5, 4.0, 7.5, 12.0 };

    std::vector<ElectricPotential> integralVector
        = Math::cumulativeTrapzIntegration(lengthVectorForIntegration, eFieldVector);

    std::vector<double> actualIntegralResults;

    for (const auto& result : integralVector)
        actualIntegralResults.push_back(result.getMagnitude());

    ASSERT_EQ(expectedIntegralResults, actualIntegralResults);
}
