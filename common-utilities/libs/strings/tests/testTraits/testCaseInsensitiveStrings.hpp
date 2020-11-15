// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: testCaseInsensitiveStrings.hpp
// Author: crdrisko
// Date: 11/03/2020-08:39:39
// Description: Provides ~100% unit test coverage over the case-insensitive string comparisons

#ifndef DRYCHEM_COMMON_UTILITIES_LIBS_STRINGS_TESTS_TESTUTILITIES_TESTCASEINSENSITIVESTRINGS_HPP
#define DRYCHEM_COMMON_UTILITIES_LIBS_STRINGS_TESTS_TESTUTILITIES_TESTCASEINSENSITIVESTRINGS_HPP

#include <iostream>
#include <iterator>
#include <sstream>
#include <string>

#include <common-utils/strings.hpp>
#include <gtest/gtest.h>

GTEST_TEST(testCaseInsensitiveStrings, only_a_to_z_charsAreConvertedToUpperCase)
{
    for (char ch = 0; ch < 127; ++ch)
    {
        if (ch >= 'a' && ch <= 'z')
            ASSERT_TRUE((ch - 'a' + 'A') == DryChem::ci_char_traits::ct_toupper(ch));
        else
            ASSERT_TRUE(ch == DryChem::ci_char_traits::ct_toupper(ch));
    }

    GTEST_COMPILE_ASSERT_('A' == DryChem::ci_char_traits::ct_toupper('a'), "'a' wasn't converted to 'A'.");
}

GTEST_TEST(testCaseInsensitiveStrings, ci_char_traits_compare_ConvertsBothArgsToUpperCaseBeforeComparison)
{
    GTEST_COMPILE_ASSERT_(DryChem::ci_char_traits::compare("hello", "hElLoWorld", 11) == -1,
        "s2 should be greater than s1.");
    GTEST_COMPILE_ASSERT_(DryChem::ci_char_traits::compare("hello", "hElLo", 6) == 0, "The two strings should be equal.");
    GTEST_COMPILE_ASSERT_(DryChem::ci_char_traits::compare("helloworld", "hElLo", 6) == 1, "s1 should be greater than s2.");
}

GTEST_TEST(testCaseInsensitiveStrings, ci_char_traits_find_ConvertsBothArgsToUpperCaseBeforeSearching)
{
    const char word[12] {"Hello World"};

    const char* actualResult   = DryChem::ci_char_traits::find(word, std::size(word), 'w');
    const char* expectedResult = std::char_traits<char>::find(word, std::size(word), 'W');
    ASSERT_EQ(*actualResult, *expectedResult);

    actualResult = DryChem::ci_char_traits::find(word, std::size(word), 's');
    ASSERT_FALSE(actualResult);   // false because no match

    actualResult = DryChem::ci_char_traits::find(word, 0, 's');
    ASSERT_FALSE(actualResult);   // false because count == 0
}

GTEST_TEST(testCaseInsensitiveStrings, ci_char_traits_eq_ConvertsBothArgsToUpperCaseBeforeComparison)
{
    GTEST_COMPILE_ASSERT_(!std::char_traits<char>::eq('t', 'T'), "'t' should not be equal to 'T'.");
    GTEST_COMPILE_ASSERT_(DryChem::ci_char_traits::eq('t', 'T'), "'t' should be equal to 'T'.");
}

GTEST_TEST(testCaseInsensitiveStrings, ci_char_traits_lt_ConvertsBothArgsToUpperCaseBeforeComparison)
{
    GTEST_COMPILE_ASSERT_(std::char_traits<char>::lt('Z', 'a'), "'Z' should be less than 'a'.");
    GTEST_COMPILE_ASSERT_(!DryChem::ci_char_traits::lt('Z', 'a'), "'Z' should not be less than 'a'.");
}

GTEST_TEST(testCaseInsensitiveStrings, allComparisonOperatorsAreSupportedForA_ci_string)
{
    DryChem::ci_string lower  = "test";
    DryChem::ci_string upper  = "TEST";
    DryChem::ci_string longer = "THis_iS_A_tEsT";

    ASSERT_TRUE(lower == upper);
    ASSERT_TRUE(longer != upper);
    ASSERT_TRUE(lower < longer);
    ASSERT_TRUE(longer > upper);
    ASSERT_TRUE(lower <= upper);
    ASSERT_TRUE(longer >= lower);
}

GTEST_TEST(testCaseInsensitiveStrings, char_traitsCanBeCastIntoOtherchar_traits)
{
    std::string lower = "test";
    std::string upper = "TEST";

    DryChem::ci_string ci_lower = DryChem::traits_cast<DryChem::ci_char_traits>(lower);
    DryChem::ci_string ci_upper = DryChem::traits_cast<DryChem::ci_char_traits>(upper);

    ASSERT_TRUE(lower > upper);
    ASSERT_TRUE(ci_lower == ci_upper);
    ASSERT_FALSE(DryChem::traits_cast<std::char_traits<char>>(ci_lower) == upper);
}

GTEST_TEST(testCaseInsensitiveStrings, a_ci_stringCanUseAllNormalStringMemberFunctions)
{
    DryChem::ci_string ci_lower = "SomE LOng StRInG";

    ASSERT_EQ(DryChem::ci_string::npos, ci_lower.find("x"));
    ASSERT_EQ(1ul, ci_lower.find_first_not_of("s"));
    ASSERT_EQ(2ul, ci_lower.find_first_of("m"));
    ASSERT_EQ(15ul, ci_lower.find_last_not_of("x"));
    ASSERT_EQ(12ul, ci_lower.find_last_of("r"));
    ASSERT_EQ(16ul, ci_lower.length());
}

GTEST_TEST(testCaseInsensitiveStrings, ci_stringsCanBePrintedJustLikeNormalStrings)
{
    using namespace DryChem;
    testing::internal::CaptureStdout();

    ci_string str = "THIS is A casE-InsensiTivE StrinG.";

    std::cout << str << std::endl;

    ci_string actualOutput = traits_cast<ci_char_traits>(testing::internal::GetCapturedStdout());
    ASSERT_EQ(actualOutput, "this is a case-insensitive string.\n");
}

#endif
