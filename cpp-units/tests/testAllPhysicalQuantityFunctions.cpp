// Copyright (c) 2020-2025 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: testAllPhysicalQuantityFunctions.cpp
// Author: crdrisko
// Date: 09/02/2020-14:03:22
// Description: Provides ~100% unit test coverage over all overloaded operators and other miscellaneous functions

#include <gtest/gtest.h>

#include "testOperators/testArithmeticOperators.hpp"
#include "testOperators/testComparisonOperators.hpp"
#include "testOperators/testStreamOperators.hpp"
#include "testTypes/testDimensionality.hpp"
#include "testTypes/testPhysicalQuantity.hpp"

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
