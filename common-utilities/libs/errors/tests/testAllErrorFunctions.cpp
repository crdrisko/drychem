// Copyright (c) 2020-2021 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: testAllErrorFunctions.cpp
// Author: cdrisko
// Date: 01/31/2020-15:55:57
// Description: Provides ~100% unit test coverage over all error and exception handling functions

#include <gtest/gtest.h>

#include "testExceptions/testExceptionHandling.hpp"
#include "testTraits/testErrorTraits.hpp"
#include "testUtilities/testErrorHandling.hpp"
#include "testUtilities/testErrorTypes.hpp"

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
