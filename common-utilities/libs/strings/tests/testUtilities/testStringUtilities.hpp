// Copyright (c) 2020-2025 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: testStringUtilities.hpp
// Author: crdrisko
// Date: 11/03/2020-13:23:00
// Description: Provides ~100% unit test coverage over the basic string utilities

#ifndef DRYCHEM_COMMON_UTILITIES_LIBS_STRINGS_TESTS_TESTUTILITIES_TESTSTRINGUTILITIES_HPP
#define DRYCHEM_COMMON_UTILITIES_LIBS_STRINGS_TESTS_TESTUTILITIES_TESTSTRINGUTILITIES_HPP

#include <string>

#include <common-utils/strings.hpp>
#include <gtest/gtest.h>

GTEST_TEST(testStringUtilities, foundSubstrFunctionCanBeCalledWithStdStrings)
{
    std::string stringToSearch {"This is a test of the foundSubstr function."};
    std::string stringToFind {"This is a test"};

    ASSERT_TRUE(DryChem::foundSubstr(stringToFind, stringToSearch));
    ASSERT_FALSE(DryChem::foundSubstr(stringToSearch, stringToFind));
}

GTEST_TEST(testStringUtilities, foundSubstrFunctionCanBeCalledWithChars)
{
    std::string stringToSearch {"This is a test of the foundSubstr function."};

    ASSERT_TRUE(DryChem::foundSubstr('T', stringToSearch));
    ASSERT_TRUE(DryChem::foundSubstr('.', stringToSearch));
    ASSERT_FALSE(DryChem::foundSubstr('x', stringToSearch));
}

GTEST_TEST(testStringUtilities, foundSubstrFindsIndividualWordsInLongerString)
{
    std::string stringToSearch {"This is a test of the foundSubstr function."};

    ASSERT_TRUE(DryChem::foundSubstr("This", stringToSearch));
    ASSERT_TRUE(DryChem::foundSubstr("is", stringToSearch));
    ASSERT_TRUE(DryChem::foundSubstr("a", stringToSearch));
    ASSERT_TRUE(DryChem::foundSubstr("test", stringToSearch));
    ASSERT_TRUE(DryChem::foundSubstr("of", stringToSearch));
    ASSERT_TRUE(DryChem::foundSubstr("the", stringToSearch));
    ASSERT_TRUE(DryChem::foundSubstr("foundSubstr", stringToSearch));
    ASSERT_TRUE(DryChem::foundSubstr("function", stringToSearch));
}

GTEST_TEST(testStringUtilities, foundSubstrFunctionCanBeCaseSensitive)
{
    std::string stringToSearch {"This is a test of the foundSubstr function."};

    ASSERT_FALSE(DryChem::foundSubstr("this", stringToSearch));
    ASSERT_FALSE(DryChem::foundSubstr("THIS", stringToSearch));

    DryChem::ci_string ci_stringToSearch {"This is a test of the foundSubstr function."};

    ASSERT_TRUE(DryChem::foundSubstr("this", ci_stringToSearch));
    ASSERT_TRUE(DryChem::foundSubstr("THIS", ci_stringToSearch));
}

#endif
