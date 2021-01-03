// Copyright (c) 2020-2021 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: testAllMathFunctions.cpp
// Author: cdrisko
// Date: 01/31/2020-15:58:59
// Description: Provides ~100% unit test coverage over all mathematical functions

#include <gtest/gtest.h>

#include "testCalculus/testDifferentiationMethods.hpp"
#include "testCalculus/testIntegrationMethods.hpp"
#include "testContainers/testVector3DFunctions.hpp"
#include "testStatistics/testLinearLeastSquaresFitting.hpp"
#include "testStatistics/testStatisticalFunctions.hpp"
#include "testUtilities/testBasicMathFunctions.hpp"
#include "testUtilities/testMathExceptions.hpp"

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
