// Copyright (c) 2020-2024 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: testNetworkingExceptions.hpp
// Author: crdrisko
// Date: 08/30/2021-07:24:54
// Description: Provides ~100% unit test coverage over all exceptions specifically relating to the networking library

#ifndef DRYCHEM_COMMON_UTILITIES_LIBS_NETWORKING_TESTS_TESTUTILITIES_TESTNETWORKINGEXCEPTIONS_HPP
#define DRYCHEM_COMMON_UTILITIES_LIBS_NETWORKING_TESTS_TESTUTILITIES_TESTNETWORKINGEXCEPTIONS_HPP

#include <sstream>

#include <common-utils/errors.hpp>
#include <common-utils/networking.hpp>
#include <gtest/gtest.h>

GTEST_TEST(testNetworkingExceptions, basicNetworkingFailureIsAFatalExceptionAndCanTerminateWhenHandled)
{
    std::stringstream deathRegex;

    deathRegex << "Common-Utilities Fatal Error: ";

#if GTEST_USES_POSIX_RE
    deathRegex << "[(]testNetworkingExceptions.hpp: *[0-9]*[)]\n\tsend[(][)]";
#elif GTEST_USES_SIMPLE_RE
    deathRegex << "\\(testNetworkingExceptions.hpp: \\d*\\)\n\ttsend\\(\\)";
#endif

    deathRegex << " failed.\n";

    DryChem::BasicNetworkingFailure exception1 {"send", __FILE__, __LINE__};

    ASSERT_DEATH(
        {
            try
            {
                throw exception1;
            }
            catch (const DryChem::BasicNetworkingFailure& except)
            {
                except.handleErrorWithMessage();
            }
        },
        deathRegex.str());
}

GTEST_TEST(testNetworkingExceptions, alreadyInNetworkStateIsAFatalExceptionAndCanTerminateWhenHandled)
{
    std::stringstream deathRegex;

    deathRegex << "Common-Utilities Fatal Error: ";

#if GTEST_USES_POSIX_RE
    deathRegex << "[(]testNetworkingExceptions.hpp: *[0-9]*[)]\n\t";
#elif GTEST_USES_SIMPLE_RE
    deathRegex << "\\(testNetworkingExceptions.hpp: \\d*\\)\n\t";
#endif

    deathRegex << "Socket is already in the Closed state.\n";

    DryChem::AlreadyInNetworkState exception1 {"Closed", __FILE__, __LINE__};

    ASSERT_DEATH(
        {
            try
            {
                throw exception1;
            }
            catch (const DryChem::AlreadyInNetworkState& except)
            {
                except.handleErrorWithMessage();
            }
        },
        deathRegex.str());
}

GTEST_TEST(testNetworkingExceptions, derivedExceptionsCanBeCaughtByBaseFatalException)
{
    std::stringstream deathRegex1;
    std::stringstream deathRegex2;

    deathRegex1 << "Common-Utilities Fatal Error: ";

#if GTEST_USES_POSIX_RE
    deathRegex1 << "[(]testNetworkingExceptions.hpp: *[0-9]*[)]\n\t";
#elif GTEST_USES_SIMPLE_RE
    deathRegex1 << "\\(testNetworkingExceptions.hpp: \\d*\\)\n\t";
#endif

    deathRegex2 << deathRegex1.str();

#if GTEST_USES_POSIX_RE
    deathRegex1 << "send[(][)]";
#elif GTEST_USES_SIMPLE_RE
    deathRegex1 << "send\\(\\)";
#endif
    deathRegex1 << " failed.\n";

    ASSERT_DEATH(
        {
            try
            {
                throw DryChem::BasicNetworkingFailure("send", __FILE__, __LINE__);
            }
            catch (const DryChem::FatalException& except)
            {
                except.handleErrorWithMessage();
            }
        },
        deathRegex1.str());

    deathRegex2 << "Socket is already in the Closed state.\n";

    ASSERT_DEATH(
        {
            try
            {
                throw DryChem::AlreadyInNetworkState("Closed", __FILE__, __LINE__);
            }
            catch (const DryChem::FatalException& except)
            {
                except.handleErrorWithMessage();
            }
        },
        deathRegex2.str());
}

#endif
