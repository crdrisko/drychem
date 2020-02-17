// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: testMiscellaneousUnitFunctions.cpp - Version 1.0.0
// Author: cdrisko
// Date: 01/31/2020-16:04:24
// Description: Provides 100% unit test coverage over all operators and other miscellaneous functions

#include <gtest/gtest.h>
#include "../../../include/internal/PhysicalQuantities/mathematicalFunctions.hpp"
#include "../../../include/internal/PhysicalQuantities/MKSQuantities/GeometricQuantities/length.hpp"
#include "../../../include/internal/PhysicalQuantities/MolarQuantities/concentrationGradient.hpp"
#include "../../../include/internal/PhysicalQuantities/ElectromagneticQuantities/ChargedQuantities/electricField.hpp"
#include "../../../include/internal/PhysicalQuantities/ElectromagneticQuantities/ChargedQuantities/electricPotential.hpp"
#include "../../../include/internal/PhysicalQuantities/ElectromagneticQuantities/ChargedQuantities/mobility.hpp"

using namespace Utilities_API::PhysicalQuantities;

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(testMiscellaneousUnitFunctions, properPrintingOfPhysicalQuantitysMagnitude)
{
    testing::internal::CaptureStdout();

    DimensionlessQuantity value = 1.0_;

    std::cout << value << std::endl;
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, "1\n");
}

TEST(testMiscellaneousUnitFunctions, testComparisonOperators)
{
    DimensionlessQuantity value1 = 1.0_;
    DimensionlessQuantity value2 = 2.0_;
    DimensionlessQuantity value3 = 5.0_;
    DimensionlessQuantity value4(1.0);

    ASSERT_TRUE(value1 < value2);
    ASSERT_TRUE(value1 <= value2);
    ASSERT_TRUE(value3 > value2);
    ASSERT_TRUE(value3 >= value2);
    ASSERT_TRUE(value1 == value4);
    ASSERT_TRUE(value3 != value2);

    ASSERT_FALSE(value1 == value2);
    ASSERT_FALSE(value1 >= value2);
    ASSERT_FALSE(value4 != value1);
}

TEST(testMiscellaneousUnitFunctions, testArithmeticOperators)
{
    DimensionlessQuantity dimensionlessQuantity = 5.0_;
    DimensionlessQuantity dimensionlessQuantitySquared = dimensionlessQuantity.raisePower(2);

    ASSERT_DOUBLE_EQ(30.0, (dimensionlessQuantitySquared + dimensionlessQuantity).getMagnitude());

    dimensionlessQuantity += 2.0_;
    ASSERT_DOUBLE_EQ(7.0, dimensionlessQuantity.getMagnitude());

    ASSERT_DOUBLE_EQ(18.0, (dimensionlessQuantitySquared - dimensionlessQuantity).getMagnitude());

    dimensionlessQuantity -= 2.0_;
    ASSERT_DOUBLE_EQ(5.0, dimensionlessQuantity.getMagnitude());

    ASSERT_DOUBLE_EQ(125.0, (dimensionlessQuantitySquared * dimensionlessQuantity).getMagnitude());
    ASSERT_DOUBLE_EQ(5.0, (dimensionlessQuantitySquared / dimensionlessQuantity).getMagnitude());
}

TEST(testMiscellaneousUnitFunctions, testAdvancedMathFunctions)
{
    // A test of the PhysicalQuantity class's finite difference method function
    std::vector<Length> lengthVectorForDerivative { 1.0_m, 2.0_m, 3.0_m, 4.0_m, 5.0_m };
    std::vector<Concentration> concentrationVector { 1.0_M, 2.0_M, 3.0_M, 4.0_M, 5.0_M };

    std::vector<double> expectedDerivativeResults { 1.0, 1.0, 1.0, 1.0, 1.0 };

    std::vector<ConcentrationGradient> derivativeVector
        = Mathematics::mathematicalFunction< Length, Concentration, std::string, ConcentrationGradient >
            (lengthVectorForDerivative, concentrationVector, "Centered", Mathematics::finiteDifferenceMethod);

    std::vector<double> actualDerivativeResults;

    for (const auto& result : derivativeVector)
        actualDerivativeResults.push_back(result.getMagnitude());

    ASSERT_EQ(expectedDerivativeResults, actualDerivativeResults);


    // A test of the PhysicalQuantity class's least squares fitting function
    std::map<std::string, long double> fittingParameters
        = Mathematics::mathematicalFunction< Length, Concentration, std::map<std::string, long double> >
            (lengthVectorForDerivative, concentrationVector, Mathematics::linearLeastSquaresFitting);

    ASSERT_EQ(1.0, fittingParameters["slope"]);
    ASSERT_EQ(0.0, fittingParameters["intercept"]);


    // A test of the PhysicalQuantity class's cumulative trapz function
    std::vector<Length> lengthVectorForIntegration { 1.0_m, 2.0_m, 3.0_m, 4.0_m, 5.0_m };
    std::vector<ElectricField> eFieldVector { 1.0_V_m, 2.0_V_m, 3.0_V_m, 4.0_V_m, 5.0_V_m };

    std::vector<double> expectedIntegralResults { 0.0, 1.5, 4.0, 7.5, 12.0 };

    std::vector<ElectricPotential> integralVector
        = Mathematics::mathematicalFunction< Length, ElectricField, int, ElectricPotential >
            (lengthVectorForIntegration, eFieldVector, 0, Mathematics::cumulativeTrapz);

    std::vector<double> actualIntegralResults;

    for (const auto& result : integralVector)
        actualIntegralResults.push_back(result.getMagnitude());

    ASSERT_EQ(expectedIntegralResults, actualIntegralResults);


    // A test of the PhysicalQuantity class's average calculation method
    Length averageLength
        = Mathematics::mathematicalFunction<Length>
            (lengthVectorForIntegration, Mathematics::calculateAverage);

    ASSERT_EQ(3, averageLength.getMagnitude());
}

TEST(testMiscellaneousUnitFunctions, testAllOtherMiscellaneousFunctions)
{
    // A test of the PhysicalQuantity class's negation function
    DimensionlessQuantity positiveValue = 1.0_;
    ASSERT_DOUBLE_EQ(1.0, positiveValue.getMagnitude());
    ASSERT_DOUBLE_EQ(-1.0, positiveValue.negateQuantity().getMagnitude());


    // A test of the PhysicalQuantity class's natural logarithm function
    Concentration concentration = 1.0_M;
    ASSERT_DOUBLE_EQ(0.0, concentration.takeNaturalLogarithm().getMagnitude());


    // A test of the PhysicalQuantity class's default initializer
    DimensionlessQuantity defaultInitialized;
    ASSERT_DOUBLE_EQ(0.0, defaultInitialized.getMagnitude());

    defaultInitialized.setMagnitude(1e5);
    ASSERT_DOUBLE_EQ(1e5, defaultInitialized.getMagnitude());
}

TEST(testMiscellaneousUnitFunctions, testTransportCalculations)
{
    ElectricCharge q_ion = 1.0_C;
    CurrentDensity Jc_ion = 1.0e8_A_m2;
    Force gradientOfElectrochemcialPotential_ion = 10.0_N;
    Concentration conc_ion = 0.1_M;

    ElectricConductivity sigma_ion { Calculations::calculateElectricalConductivity(q_ion, Jc_ion,
        gradientOfElectrochemcialPotential_ion) };

    MolarConductivity lambda_ion { Calculations::calculateMolarConductivity(sigma_ion, conc_ion) };

    Mobility mobility_ion { Calculations::calculateMobility(lambda_ion, q_ion) };

    ASSERT_DOUBLE_EQ(1.0e7, sigma_ion.getMagnitude());
    ASSERT_DOUBLE_EQ(1.0e8, lambda_ion.getMagnitude());
    ASSERT_NEAR( 1036.43, mobility_ion.getMagnitude(), Utilities_API::Math::findAbsoluteError(1036.43, 6) );
}
