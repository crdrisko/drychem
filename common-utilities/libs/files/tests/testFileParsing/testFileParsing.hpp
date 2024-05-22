// Copyright (c) 2020-2024 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: testFileParsing.hpp
// Author: crdrisko
// Date: 12/24/2020-07:55:29
// Description: Provides ~100% unit test coverage over all file parsing functions

#ifndef DRYCHEM_COMMON_UTILITIES_LIBS_FILES_TESTS_TESTFILEPARSING_TESTFILEPARSING_HPP
#define DRYCHEM_COMMON_UTILITIES_LIBS_FILES_TESTS_TESTFILEPARSING_TESTFILEPARSING_HPP

#include <filesystem>
#include <sstream>
#include <string>
#include <vector>

#include <common-utils/files.hpp>
#include <common-utils/strings.hpp>
#include <common-utils/utilities.hpp>
#include <gtest/gtest.h>

#include "../details/fileDetails.hpp"

namespace fs = std::filesystem;

GTEST_TEST(testFileParsing, defaultParsingOfATSVFileGivesAVectorOfStrings)
{
    using CppUtils::Files::details::testing::createOutputFile;

    fs::path fileName {"test.tsv"};

    if (!fs::is_regular_file(fileName))
        createOutputFile(fileName, '\t');

    DryChem::FileParser parser {fileName};

    auto rows = parser.parseDataFile(DryChem::AsRows());
    std::vector<std::string> expectedRows {"1\t2\t3", "4\t5\t6", "7\t8\t9", "10\t11\t12"};

    auto columns = parser.parseDataFile(DryChem::AsColumns());
    std::vector<std::string> expectedColumns {"1\t4\t7\t10", "2\t5\t8\t11", "3\t6\t9\t12"};

    ASSERT_EQ(rows, expectedRows);
    ASSERT_EQ(columns, expectedColumns);
}

GTEST_TEST(testFileParsing, defaultParsingOfACSVFileGivesAVectorOfStrings)
{
    using CppUtils::Files::details::testing::createOutputFile;

    fs::path fileName {"test.csv"};

    if (!fs::is_regular_file(fileName))
        createOutputFile(fileName, ',');

    DryChem::FileParser parser {fileName};

    auto rows = parser.parseDataFile(DryChem::AsRows());
    std::vector<std::string> expectedRows {"1,2,3", "4,5,6", "7,8,9", "10,11,12"};

    std::string csvDelimiter {","};

    auto columns = parser.parseDataFile(DryChem::AsColumns(), csvDelimiter);
    std::vector<std::string> expectedColumns {"1,4,7,10", "2,5,8,11", "3,6,9,12"};

    ASSERT_EQ(rows, expectedRows);
    ASSERT_EQ(columns, expectedColumns);
}

GTEST_TEST(testFileParsing, weCanDefineOurOwnNonDefaultParserUsingALambdaExpression)
{
    using CppUtils::Files::details::testing::createOutputFile;

    fs::path fileName {"test.csv"};

    if (!fs::is_regular_file(fileName))
        createOutputFile(fileName, ',');

    DryChem::FileParser parser {fileName};

    std::vector<std::string> rows;

    parser.parseDataFile(
        [&rows](const std::string& fileContents)
        {
            DryChem::Tokenizer tok {fileContents, "\n"};
            rows = tok.split();
        });

    auto expectedRows = parser.parseDataFile(DryChem::AsRows());

    ASSERT_EQ(rows, expectedRows);
}

GTEST_TEST(testFileParsing, onceAFileIsParsedOnceAllSubsequentTimesUseCaches)
{
    using CppUtils::Files::details::testing::createOutputFile;

    fs::path fileName {"test.tsv"};

    if (!fs::is_regular_file(fileName))
        createOutputFile(fileName, '\t');

    DryChem::FileParser parser {fileName};

    // Slowest
    auto [columns1, timeFor1stColumns]
        = DryChem::timeAndInvoke(&DryChem::FileParser::parseDataFile<DryChem::AsColumns>, parser, DryChem::AsColumns());

    // Slow
    auto [rows1, timeFor1stRows]
        = DryChem::timeAndInvoke(&DryChem::FileParser::parseDataFile<DryChem::AsRows>, parser, DryChem::AsRows());

    // Fast
    auto [columns2, timeFor2ndColumns]
        = DryChem::timeAndInvoke(&DryChem::FileParser::parseDataFile<DryChem::AsColumns>, parser, DryChem::AsColumns());

    // Fast
    auto [rows2, timeFor2ndRows]
        = DryChem::timeAndInvoke(&DryChem::FileParser::parseDataFile<DryChem::AsRows>, parser, DryChem::AsRows());

    ASSERT_EQ(rows1, rows2);
    ASSERT_EQ(columns1, columns2);

    ASSERT_TRUE(timeFor1stRows >= timeFor2ndRows && timeFor1stColumns > timeFor2ndColumns);
}

GTEST_TEST(testFileParsing, returningTheFileNameAllowsUsToUtilizeTheFileSystemLibrary)
{
    using CppUtils::Files::details::testing::createOutputFile;

    fs::path fileName {"test.tsv"};

    if (!fs::is_regular_file(fileName))
        createOutputFile(fileName, '\t');

    DryChem::FileParser parser {fileName};

    ASSERT_TRUE(fs::is_regular_file(parser.getFileName()));

    ASSERT_EQ("test", parser.getFileName().stem());
    ASSERT_EQ(".tsv", parser.getFileName().extension());
}

GTEST_TEST(testFileParsing, tryingToParseANonExistentFileResultsInFatalException)
{
    std::stringstream deathRegex;

    deathRegex << "Common-Utilities Fatal Error: ";

#if GTEST_USES_POSIX_RE
    deathRegex << "[(]fileParser.hpp: *[0-9]*[)]\n\t";
#elif GTEST_USES_SIMPLE_RE
    deathRegex << "\\(fileParser.hpp: \\d*\\)\n\t";
#endif

    deathRegex << "Could not find the requested file.\n";

    ASSERT_DEATH(
        {
            try
            {
                DryChem::FileParser parser {fs::path {"SomeNonExistentFile.txt"}};
                auto rows = parser.parseDataFile(DryChem::AsRows());
            }
            catch (const DryChem::FileNotFound& except)
            {
                except.handleErrorWithMessage();
            }
        },
        deathRegex.str());
}

#endif
