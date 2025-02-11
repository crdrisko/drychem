// Copyright (c) 2020-2025 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: testFileExceptions.hpp
// Author: crdrisko
// Date: 01/03/2021-17:25:28
// Description: Provides ~100% unit test coverage over all exceptions specifically relating to the file handling library

#ifndef DRYCHEM_COMMON_UTILITIES_LIBS_FILES_TESTS_TESTUTILITIES_TESTFILEEXCEPTIONS_HPP
#define DRYCHEM_COMMON_UTILITIES_LIBS_FILES_TESTS_TESTUTILITIES_TESTFILEEXCEPTIONS_HPP

#include <sstream>

#include <common-utils/errors.hpp>
#include <common-utils/files.hpp>
#include <gtest/gtest.h>

GTEST_TEST(testFileExceptions, fileNotFoundIsAFatalExceptionAndCanTerminateWhenHandled)
{
    std::stringstream deathRegex;

    deathRegex << "Common-Utilities Fatal Error: ";

#if GTEST_USES_POSIX_RE
    deathRegex << "[(]testFileExceptions.hpp: *[0-9]*[)]\n\t";
#elif GTEST_USES_SIMPLE_RE
    deathRegex << "\\(testFileExceptions.hpp: \\d*\\)\n\t";
#endif

    deathRegex << "Could not find the requested file.\n";

    DryChem::FileNotFound exception1 {"Common-Utilities", __FILE__, __LINE__};

    ASSERT_DEATH(
        {
            try
            {
                throw exception1;
            }
            catch (const DryChem::FileNotFound& except)
            {
                except.handleErrorWithMessage();
            }
        },
        deathRegex.str());
}

GTEST_TEST(testFileExceptions, derivedExceptionsCanBeCaughtByBaseFatalException)
{
    std::stringstream deathRegex;

    deathRegex << "Common-Utilities Fatal Error: ";

#if GTEST_USES_POSIX_RE
    deathRegex << "[(]testFileExceptions.hpp: *[0-9]*[)]\n\t";
#elif GTEST_USES_SIMPLE_RE
    deathRegex << "\\(testFileExceptions.hpp: \\d*\\)\n\t";
#endif

    deathRegex << "Could not find the requested file.\n";

    ASSERT_DEATH(
        {
            try
            {
                throw DryChem::FileNotFound("Common-Utilities", __FILE__, __LINE__);
            }
            catch (const DryChem::FatalException& except)
            {
                except.handleErrorWithMessage();
            }
        },
        deathRegex.str());
}

#endif
