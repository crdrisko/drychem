// Copyright (c) 2020-2021 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: testAllMetaFunctions.cpp
// Author: crdrisko
// Date: 01/07/2021-15:57:12
// Description: Provides ~100% unit test coverage over all template metaprogramming functions

#include <gtest/gtest.h>

#include "testTraits/testContainerTraits.hpp"
#include "testTypes/testTupleAlgorithms.hpp"

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
