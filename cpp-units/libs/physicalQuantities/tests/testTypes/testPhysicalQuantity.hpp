// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: testPhysicalQuantity.hpp
// Author: crdrisko
// Date: 09/17/2020-09:54:44
// Description: Provides ~100% unit test coverage over all miscellaneous PhysicalQuantity member functions

#ifndef CPP_UNITS_TESTING_TESTPHYSICALQUANTITY_HPP
#define CPP_UNITS_TESTING_TESTPHYSICALQUANTITY_HPP

#include <exception>
#include <string>

#include <common-utils/errors.hpp>
#include <gtest/gtest.h>

#include "physicalQuantities.hpp"

GTEST_TEST(testPhysicalQuantity, aPhysicalQuantityKnowsItsDimensionality)
{
    using MolarEntropyDimensionality = Dimensionality<2, 1, -2, 0, -1, -1>;

    ASSERT_EQ(MolarEntropyDimensionality::Length, MolarEntropy::DimensionalityType::Length);
    ASSERT_EQ(MolarEntropyDimensionality::Mass, MolarEntropy::DimensionalityType::Mass);
    ASSERT_EQ(MolarEntropyDimensionality::Time, MolarEntropy::DimensionalityType::Time);
    ASSERT_EQ(MolarEntropyDimensionality::ElectricCurrent, MolarEntropy::DimensionalityType::ElectricCurrent);
    ASSERT_EQ(MolarEntropyDimensionality::Temperature, MolarEntropy::DimensionalityType::Temperature);
    ASSERT_EQ(MolarEntropyDimensionality::AmountOfSubstance, MolarEntropy::DimensionalityType::AmountOfSubstance);
    ASSERT_EQ(MolarEntropyDimensionality::LuminousIntensity, MolarEntropy::DimensionalityType::LuminousIntensity);
}

GTEST_TEST(testPhysicalQuantity, defaultInitializerSetsPhysicalQuantitysMagnitudeToZero)
{
    DimensionlessQuantity defaultInitialized {};
    ASSERT_EQ(0.0, defaultInitialized.getMagnitude());
}

GTEST_TEST(testPhysicalQuantity, setterFunctionsCanTakeDoubleValuesAsInputParameters)
{
    Length len = 2.0_m;
    len.setMagnitude(1e5);

    ASSERT_EQ(1e5, len.getMagnitude());
}

GTEST_TEST(testPhysicalQuantity, physicalQuantitiesCanBeConstructedFromStrings)
{
    DimensionlessQuantity dimensionlessQuantity {"1e5"};
    ASSERT_DOUBLE_EQ(1e5, dimensionlessQuantity.getMagnitude());

    Length length {"1e5_m"};                                    // Non-number part ignored - could be anything
    ASSERT_DOUBLE_EQ(1e5, length.getMagnitude());
}

GTEST_TEST(testPhysicalQuantity, stringConstructorCanThrowAnException)
{
    ASSERT_DEATH(
    {
        try
        {
            try
            {
                DimensionlessQuantity dimensionlessQuantity("Not a number");
            }
            catch (const std::exception& except)
            {
                CommonUtilities::Errors::ErrorMessage error;
                error.programName = "C++ Units";
                error.message = "Exception message: " + std::string{except.what()};

                throw CommonUtilities::Errors::FatalException(error);
            }
        }
        catch (const CommonUtilities::Errors::FatalException& except)
        {
            except.handleErrorWithMessage();
        }
    }, "C++ Units Fatal Error:\n\tException message: stold");
}

#endif
