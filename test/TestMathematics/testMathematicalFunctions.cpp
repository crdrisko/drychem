// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: testMathematicalFunctions.cpp - Version 1.0.0
// Author: crdrisko
// Date: 03/04/2020-07:50:11
// Description: Provides 100% unit test coverage over all mathematical functions for the PhysicalQuantities

#include <vector>

#include <gtest/gtest.h>
#include <utils-api/math.hpp>

#include "../../include/cpp-units/physicalQuantities.hpp"

using namespace PhysicalQuantities;
using namespace PhysicalQuantities::Literals;

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(testMathematicalFunctions, exponentialOverloads)
{
    Length length = 2.0_m;

    ASSERT_NEAR(7.38906, Math::exp(length / 1.0_m).getMagnitude(),
        Utilities_API::Math::findAbsoluteError(7.38906, 6));
}

TEST(testMathematicalFunctions, logarithmOverloads)
{
    Length length = 2.0_m;

    ASSERT_NEAR(0.693147, Math::log(length / 1.0_m).getMagnitude(),
        Utilities_API::Math::findAbsoluteError(0.693147, 6));

    ASSERT_NEAR(0.30103, Math::log10(length / 1.0_m).getMagnitude(),
        Utilities_API::Math::findAbsoluteError(0.30103, 5));
}

TEST(testMathematicalFunctions, trigonometricOverloads)
{
    Angle angle = 2.0_rad * Constants::pi;

    ASSERT_NEAR(0.0, Math::sin(angle / 1.0_rad).getMagnitude(), Utilities_API::Math::findAbsoluteError(0.0, 9));
    ASSERT_NEAR(0.0, Math::cos(angle / 1.0_rad).getMagnitude(), Utilities_API::Math::findAbsoluteError(0.0, 9));
    ASSERT_NEAR(0.0, Math::tan(angle / 1.0_rad).getMagnitude(), Utilities_API::Math::findAbsoluteError(0.0, 9));
}

TEST(testMathematicalFunctions, squareAndCubeRootOverloads)
{
    Length length = 64.0_m;

    ASSERT_EQ(8.0, Math::sqrt(length / 1.0_m).getMagnitude());
    ASSERT_EQ(4.0, Math::cbrt(length / 1.0_m).getMagnitude());
}

TEST(testMathematicalFunctions, absoluteValueOverload)
{
    Length positiveLength = 1.0_m;
    Length negativeLength = -1.0_m;

    ASSERT_DOUBLE_EQ(1.0, Math::abs(positiveLength).getMagnitude());
    ASSERT_DOUBLE_EQ(1.0, Math::abs(negativeLength).getMagnitude());
}

TEST(testMathematicalFunctions, powerOverload)
{
    Length length = 5.0_m;

    WaveNumber waveNumber = Math::pow<WaveNumber>(length, -1);
    DimensionlessQuantity dimensionlessQuantity = Math::pow<DimensionlessQuantity>(length, 0);

    ASSERT_DOUBLE_EQ(0.2, waveNumber.getMagnitude());
    ASSERT_DOUBLE_EQ(1.0, dimensionlessQuantity.getMagnitude());
}

TEST(testMathematicalFunctions, specializationsOfPowWithAutomaticTypeDeduction)
{
    Length length = 5.0_m;

    ASSERT_DOUBLE_EQ(25.0, Math::square(length).getMagnitude());
    ASSERT_TRUE(Math::square(length) == Math::pow<Area>(length, 2));

    ASSERT_DOUBLE_EQ(125.0, Math::cube(length).getMagnitude());
    ASSERT_TRUE(Math::cube(length) == Math::pow<Volume>(length, 3));
}

TEST(testMathematicalFunctions, calculateAverageOverload)
{
    std::vector<Length> lengths { 1.0_m, 2.0_m, 3.0_m, 4.0_m, 5.0_m };

    Length averageLength = Math::calculateAverage(lengths);

    ASSERT_EQ(3, averageLength.getMagnitude());
}

TEST(testMathematicalFunctions, calculateStandardDeviationOverload)
{
    std::vector<Length> lengths { 1.0_m, 2.0_m, 3.0_m, 4.0_m, 5.0_m };

    Length stdDevLength = Math::calculateStandardDeviation(lengths);

    ASSERT_NEAR(1.5811388300842, stdDevLength.getMagnitude(),
        Utilities_API::Math::findAbsoluteError(1.5811388300842, 14));
}

TEST(testMathematicalFunctions, centeredDifferenceMethodOverload)
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

TEST(testMathematicalFunctions, linearLeastSquaresFittingOverload)
{
    std::vector<Length> lengthVectorForFitting { 0.0_m, 1.0_m, 2.0_m, 3.0_m, 4.0_m, 5.0_m };
    std::vector<Concentration> concentrationVector { 2.0_M, 7.0_M, 3.0_M, 5.0_M, 6.0_M, 10.0_M };

    std::vector<ConcentrationGradient> fittingParameters
        = Math::linearLeastSquaresFitting(lengthVectorForFitting, concentrationVector);

    ASSERT_NEAR(1.1143, fittingParameters[0].getMagnitude(), Utilities_API::Math::findAbsoluteError(1.1143, 5));
    ASSERT_NEAR(2.7143, fittingParameters[1].getMagnitude(), Utilities_API::Math::findAbsoluteError(2.7143, 5));
    ASSERT_NEAR(0.5314593, fittingParameters[2].getMagnitude(), Utilities_API::Math::findAbsoluteError(0.53146, 5));
}

TEST(testMathematicalFunctions, cumulativeTrapzIntegrationOverload)
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
