// Copyright (c) 2020-2021 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: testAllStringFunctions.cpp
// Author: crdrisko
// Date: 11/06/2020-15:13:55
// Description: Provides ~100% unit test coverage over all string functions

#include <gtest/gtest.h>

#include "testTraits/testCaseInsensitiveStrings.hpp"
#include "testUtilities/testLexicalCast.hpp"
#include "testUtilities/testStringUtilities.hpp"
#include "testUtilities/testTokenizer.hpp"

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
