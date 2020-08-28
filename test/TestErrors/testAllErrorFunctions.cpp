// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: testAllErrorFunctions.cpp - Version 2.0.0
// Author: cdrisko
// Date: 01/31/2020-15:55:57
// Description: Provides ~100% unit test coverage over all error and exception handling functions

#include <gtest/gtest.h>

#include "TestExceptions/testCommonExceptionTypes.hpp"
#include "TestExceptions/testExceptionHandling.hpp"
#include "TestUtilities/testErrorHandling.hpp"
#include "TestUtilities/testErrorTraits.hpp"
#include "TestUtilities/testErrorTypes.hpp"

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
