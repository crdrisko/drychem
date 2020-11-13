// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: testDimensionality.hpp
// Author: crdrisko
// Date: 09/17/2020-09:54:53
// Description: Provides ~100% unit test coverage over all dimensionality functions and types

#ifndef DRYCHEM_CPP_UNITS_TESTING_TESTDIMENSIONALITY_HPP
#define DRYCHEM_CPP_UNITS_TESTING_TESTDIMENSIONALITY_HPP

#include <gtest/gtest.h>

#include "cpp-units/physicalQuantities.hpp"

using namespace CppUnits;

GTEST_TEST(testDimensionality, aDimensionalityCanBeDecomposedIntoItsVariousComponents)
{
    using MolarEntropyDimensionality = Dimensionality<2, 1, -2, 0, -1, -1>;

    ASSERT_EQ(MolarEntropyDimensionality::Length, 2);
    ASSERT_EQ(MolarEntropyDimensionality::Mass, 1);
    ASSERT_EQ(MolarEntropyDimensionality::Time, -2);
    ASSERT_EQ(MolarEntropyDimensionality::ElectricCurrent, 0);
    ASSERT_EQ(MolarEntropyDimensionality::Temperature, -1);
    ASSERT_EQ(MolarEntropyDimensionality::AmountOfSubstance, -1);
    ASSERT_EQ(MolarEntropyDimensionality::LuminousIntensity, 0);
}

GTEST_TEST(testDimensionality, aDimensionalitysTypeCanBeDecomposedIntoItsVariousComponents)
{
    using MolarEntropyDimensionality = Dimensionality<2, 1, -2, 0, -1, -1>;

    ASSERT_EQ(MolarEntropyDimensionality::Type::Length, 2);
    ASSERT_EQ(MolarEntropyDimensionality::Type::Mass, 1);
    ASSERT_EQ(MolarEntropyDimensionality::Type::Time, -2);
    ASSERT_EQ(MolarEntropyDimensionality::Type::ElectricCurrent, 0);
    ASSERT_EQ(MolarEntropyDimensionality::Type::Temperature, -1);
    ASSERT_EQ(MolarEntropyDimensionality::Type::AmountOfSubstance, -1);
    ASSERT_EQ(MolarEntropyDimensionality::Type::LuminousIntensity, 0);
}

#endif
