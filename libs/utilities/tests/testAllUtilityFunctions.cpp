// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: testAllUtilityFunctions.cpp - Version 1.0.0
// Author: crdrisko
// Date: 09/18/2020-09:00:10
// Description: Provides ~100% unit test coverage over all helper utility functions

#include <gtest/gtest.h>

#include "testOperators/testComparisonOperators.hpp"
#include "testUtilities/testPotentiallyEmptyBaseClass.hpp"

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
