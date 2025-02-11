// Copyright (c) 2020-2025 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: testLexicalCast.hpp
// Author: crdrisko
// Date: 11/09/2020-11:07:16
// Description: Provides ~100% unit test coverage over the lexical_cast functions

#ifndef DRYCHEM_COMMON_UTILITIES_LIBS_STRINGS_TESTS_TESTUTILITIES_TESTLEXICALCAST_HPP
#define DRYCHEM_COMMON_UTILITIES_LIBS_STRINGS_TESTS_TESTUTILITIES_TESTLEXICALCAST_HPP

#include <limits>
#include <string>

#include <common-utils/strings.hpp>
#include <gtest/gtest.h>

#include "../details/stringDetails.hpp"

GTEST_TEST(testLexicalCast, lexiCastOnAStringResultsInTheSameString)
{
    std::string str1 {"This is the string to \"convert\""};
    std::string str2 {DryChem::lexical_cast<std::string>(str1)};

    DryChem::ci_string ci_str1 {"This is the string to \"convert\""};
    DryChem::ci_string ci_str2 {DryChem::lexical_cast<DryChem::ci_string>(ci_str1)};

    ASSERT_EQ(str1, str2);
    ASSERT_EQ(ci_str1, ci_str2);
}

GTEST_TEST(testLexicalCast, anInputStreamThatDoesntFailIsUsedToConvertTheStringToItsProperValue)
{
    using CppUtils::Strings::details::testing::GoodValue;

    GoodValue val = DryChem::lexical_cast<GoodValue>("14");

    ASSERT_EQ(14, val.getValue());
}

GTEST_TEST(testLexicalCast, ifInputStreamFailsWithTheBadBitSetAWarningIsPrintedAndValueIsSetToDefault)
{
    using CppUtils::Strings::details::testing::BadValue;

    testing::internal::CaptureStderr();

    BadValue val = DryChem::lexical_cast<BadValue>("14");

    std::string output = testing::internal::GetCapturedStderr();
    ASSERT_EQ(output, "Common-Utilities Warning:\n    Error in lexical_cast, default value returned.\n");

    ASSERT_EQ(0, val.getValue());
}

GTEST_TEST(testLexicalCast, ifInputStreamFailsWithTheFailBitAWarningIsPrintedAndValueIsSetToDefault)
{
    using CppUtils::Strings::details::testing::FailValue;

    testing::internal::CaptureStderr();

    FailValue val = DryChem::lexical_cast<FailValue>("14");

    std::string output = testing::internal::GetCapturedStderr();
    ASSERT_EQ(output, "Common-Utilities Warning:\n    Error in lexical_cast, default value returned.\n");

    ASSERT_EQ(0, val.getValue());
}

GTEST_TEST(testLexicalCast, lexiCastOnLongDoubleIsTheSameAsCallingStdFunction)
{
    std::string str {std::to_string(std::numeric_limits<long double>::max())};

    ASSERT_EQ(std::stold(std::to_string(std::numeric_limits<long double>::max())), DryChem::lexical_cast<long double>(str));
}

GTEST_TEST(testLexicalCast, lexiCastOnDoubleIsTheSameAsCallingStdFunction)
{
    std::string str {std::to_string(std::numeric_limits<double>::max())};

    ASSERT_EQ(std::stod(std::to_string(std::numeric_limits<double>::max())), DryChem::lexical_cast<double>(str));
}

GTEST_TEST(testLexicalCast, lexiCastOnFloatIsTheSameAsCallingStdFunction)
{
    std::string str {std::to_string(std::numeric_limits<float>::max())};

    ASSERT_EQ(std::stof(std::to_string(std::numeric_limits<float>::max())), DryChem::lexical_cast<float>(str));
}

GTEST_TEST(testLexicalCast, lexiCastOnIntIsTheSameAsCallingStdFunction)
{
    std::string str {std::to_string(std::numeric_limits<int>::max())};

    ASSERT_EQ(std::stoi(std::to_string(std::numeric_limits<int>::max())), DryChem::lexical_cast<int>(str));
}

GTEST_TEST(testLexicalCast, lexiCastOnLongIsTheSameAsCallingStdFunction)
{
    std::string str {std::to_string(std::numeric_limits<long>::max())};

    ASSERT_EQ(std::stol(std::to_string(std::numeric_limits<long>::max())), DryChem::lexical_cast<long>(str));
}

GTEST_TEST(testLexicalCast, lexiCastOnUnsignedLongIsTheSameAsCallingStdFunction)
{
    std::string str {std::to_string(std::numeric_limits<unsigned long>::max())};

    ASSERT_EQ(
        std::stoul(std::to_string(std::numeric_limits<unsigned long>::max())), DryChem::lexical_cast<unsigned long>(str));
}

GTEST_TEST(testLexicalCast, lexiCastOnLongLongIsTheSameAsCallingStdFunction)
{
    std::string str {std::to_string(std::numeric_limits<long long>::max())};

    ASSERT_EQ(std::stoll(std::to_string(std::numeric_limits<long long>::max())), DryChem::lexical_cast<long long>(str));
}

GTEST_TEST(testLexicalCast, lexiCastOnUnsignedLongLongIsTheSameAsCallingStdFunction)
{
    std::string str {std::to_string(std::numeric_limits<unsigned long long>::max())};

    ASSERT_EQ(std::stoull(std::to_string(std::numeric_limits<unsigned long long>::max())),
        DryChem::lexical_cast<unsigned long long>(str));
}

#endif
