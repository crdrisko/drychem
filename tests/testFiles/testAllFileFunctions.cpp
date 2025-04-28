// Copyright (c) 2020-2025 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: testAllFileFunctions.cpp
// Author: crdrisko
// Date: 11/17/2020-14:34:04
// Description: Provides ~100% unit test coverage over all file handling functions

#include <gtest/gtest.h>

#include "testFileParsing/testFileParsing.hpp"
#include "testUtilities/testFileExceptions.hpp"

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
