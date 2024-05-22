// Copyright (c) 2020-2024 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: testTokenizer.hpp
// Author: crdrisko
// Date: 11/04/2020-09:19:27
// Description: Provides ~100% unit test coverage over the Tokenizer class functions

#ifndef DRYCHEM_COMMON_UTILITIES_LIBS_STRINGS_TESTS_TESTUTILITIES_TESTTOKENIZER_HPP
#define DRYCHEM_COMMON_UTILITIES_LIBS_STRINGS_TESTS_TESTUTILITIES_TESTTOKENIZER_HPP

#include <deque>
#include <forward_list>
#include <list>
#include <map>
#include <set>
#include <string>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include <common-utils/strings.hpp>
#include <gtest/gtest.h>

GTEST_TEST(testTokenizer, has_mapped_typeReturnsTrueForStdMapsAndOtherMapContainersOnly)
{
    ASSERT_TRUE((CppUtils::Strings::details::has_mapped_type<std::map<int, int>>::value));
    ASSERT_TRUE((CppUtils::Strings::details::has_mapped_type<std::multimap<int, int>>::value));
    ASSERT_TRUE((CppUtils::Strings::details::has_mapped_type<std::unordered_map<int, int>>::value));
    ASSERT_TRUE((CppUtils::Strings::details::has_mapped_type<std::unordered_multimap<int, int>>::value));

    ASSERT_FALSE((CppUtils::Strings::details::has_mapped_type<std::deque<int>>::value));
    ASSERT_FALSE((CppUtils::Strings::details::has_mapped_type<std::forward_list<int>>::value));
    ASSERT_FALSE((CppUtils::Strings::details::has_mapped_type<std::list<int>>::value));
    ASSERT_FALSE((CppUtils::Strings::details::has_mapped_type<std::multiset<int>>::value));
    ASSERT_FALSE((CppUtils::Strings::details::has_mapped_type<std::set<int>>::value));
    ASSERT_FALSE((CppUtils::Strings::details::has_mapped_type<std::string>::value));
    ASSERT_FALSE((CppUtils::Strings::details::has_mapped_type<std::unordered_multiset<int>>::value));
    ASSERT_FALSE((CppUtils::Strings::details::has_mapped_type<std::unordered_set<int>>::value));
    ASSERT_FALSE((CppUtils::Strings::details::has_mapped_type<std::vector<int>>::value));
}

GTEST_TEST(testTokenizer, memberTypesForATokenizerAreCorrect)
{
    using namespace DryChem;

    // clang-format off
    GTEST_COMPILE_ASSERT_((std::is_same_v<Tokenizer<ci_char_traits>::value_type, ci_string>),                      "value_type is incorrect.");
    GTEST_COMPILE_ASSERT_((std::is_same_v<Tokenizer<ci_char_traits>::reference, ci_string&>),                      "reference is incorrect.");
    GTEST_COMPILE_ASSERT_((std::is_same_v<Tokenizer<ci_char_traits>::const_reference, const ci_string&>),          "const_reference is incorrect.");
    GTEST_COMPILE_ASSERT_((std::is_same_v<Tokenizer<ci_char_traits>::iterator, ci_string::iterator>),              "iterator is incorrect.");
    GTEST_COMPILE_ASSERT_((std::is_same_v<Tokenizer<ci_char_traits>::const_iterator, ci_string::const_iterator>),  "const_iterator is incorrect.");
    // clang-format on
}

GTEST_TEST(testTokenizer, ctadWorksForTheStringConstructorOfAStdStringTokenizer)
{
    using DryChem::Tokenizer;

    std::string str {"Hello, World!"};
    std::string punctuation {" .,;:'\"?!"};
    std::string keepChars {",!"};

    Tokenizer tokenizer1 {str};
    Tokenizer tokenizer2 {str, punctuation};
    Tokenizer tokenizer3 {str, punctuation.c_str()};
    Tokenizer tokenizer4 {str, punctuation, keepChars};
    Tokenizer tokenizer5 {str, punctuation.c_str(), keepChars};
    Tokenizer tokenizer6 {str, punctuation, keepChars.c_str()};
    Tokenizer tokenizer7 {str, punctuation.c_str(), keepChars.c_str()};
    Tokenizer<std::char_traits<char>> tokenizer8 {str.begin(), str.end() - 6};
    Tokenizer<std::char_traits<char>> tokenizer9 {str.begin(), str.end() - 6, punctuation};
    Tokenizer<std::char_traits<char>> tokenizer10 {str.begin() + 5, str.end(), punctuation.c_str()};
    Tokenizer<std::char_traits<char>> tokenizer11 {str.begin(), str.end() - 6, punctuation, keepChars};
    Tokenizer<std::char_traits<char>> tokenizer12 {str.begin(), str.end() - 6, punctuation.c_str(), keepChars};
    Tokenizer<std::char_traits<char>> tokenizer13 {str.begin() + 5, str.end(), punctuation, keepChars.c_str()};
    Tokenizer<std::char_traits<char>> tokenizer14 {str.begin() + 6, str.end(), punctuation.c_str(), keepChars.c_str()};

    ASSERT_EQ(tokenizer1.split(), (std::vector<std::string> {"Hello,", "World!"}));
    ASSERT_EQ(tokenizer2.split(), (std::vector<std::string> {"Hello", "World"}));
    ASSERT_EQ(tokenizer3.split(), (std::vector<std::string> {"Hello", "World"}));
    ASSERT_EQ(tokenizer4.split(), (std::vector<std::string> {"Hello", ",", "World", "!"}));
    ASSERT_EQ(tokenizer5.split(), (std::vector<std::string> {"Hello", ",", "World", "!"}));
    ASSERT_EQ(tokenizer6.split(), (std::vector<std::string> {"Hello", ",", "World", "!"}));
    ASSERT_EQ(tokenizer7.split(), (std::vector<std::string> {"Hello", ",", "World", "!"}));
    ASSERT_EQ(tokenizer8.split(), (std::vector<std::string> {"Hello,"}));
    ASSERT_EQ(tokenizer9.split(), (std::vector<std::string> {"Hello"}));
    ASSERT_EQ(tokenizer10.split(), (std::vector<std::string> {"World"}));
    ASSERT_EQ(tokenizer11.split(), (std::vector<std::string> {"Hello", ","}));
    ASSERT_EQ(tokenizer12.split(), (std::vector<std::string> {"Hello", ","}));
    ASSERT_EQ(tokenizer13.split(), (std::vector<std::string> {",", "World", "!"}));
    ASSERT_EQ(tokenizer14.split(), (std::vector<std::string> {"World", "!"}));
}

GTEST_TEST(testTokenizer, ctadWorksForTheStringConstructorOfACaseInsensitiveTokenizer)
{
    using DryChem::Tokenizer;

    DryChem::ci_string str {"HeLlO, wOrLd!"};
    DryChem::ci_string punctuation {" .,;:'\"?!"};
    DryChem::ci_string keepChars {",!"};

    Tokenizer tokenizer1 {str};
    Tokenizer tokenizer2 {str, punctuation};
    Tokenizer tokenizer3 {str, punctuation.c_str()};
    Tokenizer tokenizer4 {str, punctuation, keepChars};
    Tokenizer tokenizer5 {str, punctuation.c_str(), keepChars};
    Tokenizer tokenizer6 {str, punctuation, keepChars.c_str()};
    Tokenizer tokenizer7 {str, punctuation.c_str(), keepChars.c_str()};
    Tokenizer<DryChem::ci_char_traits> tokenizer8 {str.begin(), str.end() - 6};
    Tokenizer<DryChem::ci_char_traits> tokenizer9 {str.begin(), str.end() - 6, punctuation};
    Tokenizer<DryChem::ci_char_traits> tokenizer10 {str.begin() + 5, str.end(), punctuation.c_str()};
    Tokenizer<DryChem::ci_char_traits> tokenizer11 {str.begin(), str.end() - 6, punctuation, keepChars};
    Tokenizer<DryChem::ci_char_traits> tokenizer12 {str.begin(), str.end() - 6, punctuation.c_str(), keepChars};
    Tokenizer<DryChem::ci_char_traits> tokenizer13 {str.begin() + 5, str.end(), punctuation, keepChars.c_str()};
    Tokenizer<DryChem::ci_char_traits> tokenizer14 {str.begin() + 6, str.end(), punctuation.c_str(), keepChars.c_str()};

    ASSERT_EQ(tokenizer1.split(), (std::vector<DryChem::ci_string> {"hello,", "world!"}));
    ASSERT_EQ(tokenizer2.split(), (std::vector<DryChem::ci_string> {"hello", "world"}));
    ASSERT_EQ(tokenizer3.split(), (std::vector<DryChem::ci_string> {"hello", "world"}));
    ASSERT_EQ(tokenizer4.split(), (std::vector<DryChem::ci_string> {"hello", ",", "world", "!"}));
    ASSERT_EQ(tokenizer5.split(), (std::vector<DryChem::ci_string> {"hello", ",", "world", "!"}));
    ASSERT_EQ(tokenizer6.split(), (std::vector<DryChem::ci_string> {"hello", ",", "world", "!"}));
    ASSERT_EQ(tokenizer7.split(), (std::vector<DryChem::ci_string> {"hello", ",", "world", "!"}));
    ASSERT_EQ(tokenizer8.split(), (std::vector<DryChem::ci_string> {"hello,"}));
    ASSERT_EQ(tokenizer9.split(), (std::vector<DryChem::ci_string> {"hello"}));
    ASSERT_EQ(tokenizer10.split(), (std::vector<DryChem::ci_string> {"world"}));
    ASSERT_EQ(tokenizer11.split(), (std::vector<DryChem::ci_string> {"hello", ","}));
    ASSERT_EQ(tokenizer12.split(), (std::vector<DryChem::ci_string> {"hello", ","}));
    ASSERT_EQ(tokenizer13.split(), (std::vector<DryChem::ci_string> {",", "world", "!"}));
    ASSERT_EQ(tokenizer14.split(), (std::vector<DryChem::ci_string> {"world", "!"}));
}

GTEST_TEST(testTokenizer, withoutATemplateParameterSplitReturnsAVectorOfStrings)
{
    std::string str {"This\n is,\ta test."};

    DryChem::Tokenizer tokenizer {str, ",. \t\n"};

    auto tokens = tokenizer.split();

    std::vector<std::string> expected {"This", "is", "a", "test"};

    ASSERT_EQ(tokens, expected);
}

GTEST_TEST(testTokenizer, aDequeOfStringsSplitsTokensNormally)
{
    std::string str {"This\n is,\ta test."};

    DryChem::Tokenizer tokenizer {str, ",. \t\n"};

    auto tokens = tokenizer.split<std::deque<std::string>>();

    std::deque<std::string> expected {"This", "is", "a", "test"};

    ASSERT_EQ(tokens, expected);
}

GTEST_TEST(testTokenizer, aForwardListOfStringsReversesTheTokens)
{
    std::string str {"This\n is,\ta test."};

    DryChem::Tokenizer tokenizer {str, ",. \t\n"};

    auto tokens = tokenizer.split<std::forward_list<std::string>>();

    std::forward_list<std::string> expected {"test", "a", "is", "This"};

    ASSERT_EQ(tokens, expected);
}

GTEST_TEST(testTokenizer, aListOfStringsSplitsTokensNormally)
{
    std::string str {"This\n is,\ta test."};

    DryChem::Tokenizer tokenizer {str, ",. \t\n"};

    auto tokens = tokenizer.split<std::list<std::string>>();

    std::list<std::string> expected {"This", "is", "a", "test"};

    ASSERT_EQ(tokens, expected);
}

GTEST_TEST(testTokenizer, aMultiSetOfStringsOrdersTokens)
{
    std::string str {"This\n is,\ta test."};

    DryChem::Tokenizer tokenizer {str, ",. \t\n"};

    auto tokens = tokenizer.split<std::multiset<std::string>>();

    std::multiset<std::string> expected {"This", "a", "is", "test"};

    ASSERT_EQ(tokens, expected);
}

GTEST_TEST(testTokenizer, aSetOfStringsOrdersTokens)
{
    std::string str {"This\n is,\ta test."};

    DryChem::Tokenizer tokenizer {str, ",. \t\n"};

    auto tokens = tokenizer.split<std::set<std::string>>();

    std::set<std::string> expected {"This", "a", "is", "test"};

    ASSERT_EQ(tokens, expected);
}

GTEST_TEST(testTokenizer, aSetOfCaseInsensitiveStringsOrdersTokensWithoutRegardToCase)
{
    DryChem::ci_string ci_str {"This\n is,\ta test."};

    DryChem::Tokenizer tokenizer {ci_str, ",. \t\n"};

    auto tokens = tokenizer.split<std::set<DryChem::ci_string>>();

    std::set<DryChem::ci_string> expected {"a", "is", "test", "This"};

    ASSERT_EQ(tokens, expected);
}

GTEST_TEST(testTokenizer, aStringTruncatesAllButTheFirstLetterOfTheToken)
{
    std::string str {"This\n is,\ta test."};

    DryChem::Tokenizer tokenizer {str, ",. \t\n"};

    auto tokens = tokenizer.split<std::string>();

    std::string expected {"Tiat"};

    ASSERT_EQ(tokens, expected);
}

GTEST_TEST(testTokenizer, anUnorderedMultiSetHashesTheTokens)
{
    std::string str = "This\n is,\ta test.";

    DryChem::Tokenizer tokenizer {str, ",. \t\n"};

    auto tokens = tokenizer.split<std::unordered_multiset<std::string>>();

    // Not sure what the hash will be so make a version with only the tokens we expect
    std::unordered_multiset<std::string> expected {"This", "is", "a", "test"};

    ASSERT_EQ(tokens, expected);
}

GTEST_TEST(testTokenizer, anUnorderedSetHashesTheTokens)
{
    std::string str {"This\n is,\ta test."};

    DryChem::Tokenizer tokenizer {str, ",. \t\n"};

    auto tokens = tokenizer.split<std::unordered_set<std::string>>();

    // Not sure what the hash will be so make a version with only the tokens we expect
    std::unordered_set<std::string> expected {"This", "is", "a", "test"};

    ASSERT_EQ(tokens, expected);
}

GTEST_TEST(testTokenizer, weCanCastStringsToAnyTypeJustBySpecifyingTheContainersTemplateParameter)
{
    testing::internal::CaptureStdout();

    std::string str = "1.234\t2.345\t3.456";

    DryChem::Tokenizer tokenizer {str};

    auto tokens = tokenizer.split<std::list<long double>>();

    for (const auto& token : tokens)
        std::cout << token << std::endl;

    std::string actualOutput = testing::internal::GetCapturedStdout();
    ASSERT_EQ(actualOutput, "1.234\n2.345\n3.456\n");
}

#endif
