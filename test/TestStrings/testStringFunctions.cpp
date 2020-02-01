// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: testStringFunctions.cpp - Version 1.0.0
// Author: cdrisko
// Date: 01/31/2020-16:00:27
// Description: Provides 100% unit test coverage over all string utility functions

#include <gtest/gtest.h>
#include "../../src/include/internal/Strings/stringUtilities.hpp"

using namespace Utilities_API::Strings;

std::string stringToSearch {"This is a test of the stringFinder function."};

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(testStringFunctions, testOf_splitString)
{
    std::vector<std::string> wordsInStringToSearch {splitString(stringToSearch)};

    ASSERT_EQ("This", wordsInStringToSearch[0]);
    ASSERT_EQ("is", wordsInStringToSearch[1]);
    ASSERT_EQ("a", wordsInStringToSearch[2]);
    ASSERT_EQ("test", wordsInStringToSearch[3]);
    ASSERT_EQ("of", wordsInStringToSearch[4]);
    ASSERT_EQ("the", wordsInStringToSearch[5]);
    ASSERT_EQ("stringFinder", wordsInStringToSearch[6]);
    ASSERT_EQ("function.", wordsInStringToSearch[7]);

    // Implementation Note: Will not split on '.' unless we tell it to
    ASSERT_NE("function", wordsInStringToSearch[7]);

    wordsInStringToSearch = splitString(stringToSearch, " .");
    ASSERT_EQ("function", wordsInStringToSearch[7]);
}

TEST(testStringFunctions, testOf_stringFinder)
{
    ASSERT_TRUE(stringFinder("This", stringToSearch));
    ASSERT_TRUE(stringFinder("is", stringToSearch));
    ASSERT_TRUE(stringFinder("a", stringToSearch));
    ASSERT_TRUE(stringFinder("test", stringToSearch));
    ASSERT_TRUE(stringFinder("of", stringToSearch));
    ASSERT_TRUE(stringFinder("the", stringToSearch));
    ASSERT_TRUE(stringFinder("stringFinder", stringToSearch));
    ASSERT_TRUE(stringFinder("function", stringToSearch));

    // Implementation Note: Finds partial words within the string it's searching for
    ASSERT_TRUE(stringFinder("fun", stringToSearch));

    // Implementation Note: Case sensitive searches
    ASSERT_FALSE(stringFinder("this", stringToSearch));
    ASSERT_FALSE(stringFinder("THIS", stringToSearch));
}
