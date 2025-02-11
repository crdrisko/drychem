// Copyright (c) 2020-2025 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: testAllMathFunctions.cpp
// Author: crdrisko
// Date: 08/25/2020-20:34:44
// Description: Provides ~100% unit test coverage over all mathematical functions for the PhysicalQuantities

#include <gtest/gtest.h>

#include "testMathFunctions/testAdvancedMathFunctions.hpp"
#include "testMathFunctions/testBasicMathFunctions.hpp"

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
