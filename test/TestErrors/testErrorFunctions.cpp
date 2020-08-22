// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: testErrorFunctions.cpp - Version 1.0.0
// Author: cdrisko
// Date: 01/31/2020-15:55:57
// Description: Provides ~100% unit test coverage over all error utility functions

#include <exception>
#include <iostream>
#include <memory>
#include <string>

#include <gtest/gtest.h>

#include "../../include/common-utils/errors.hpp"

using namespace CommonUtilities::Errors;

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

GTEST_TEST(testErrorFunctions, errorSeveritiesConvertToCorrectBooleanValues)
{
    ASSERT_FALSE( static_cast<bool>(ErrorSeverity::Warning) );
    ASSERT_TRUE( static_cast<bool>(ErrorSeverity::Fatal) );
}

GTEST_TEST(testErrorFunctions, errorPrintsMessageToStandardError)
{
    testing::internal::CaptureStderr();

    ErrorMessagePtr errorMessage { std::make_shared<ErrorMessage>("Common-Utilities") };

    errorMessage->printErrorMessage("Testing the output of the non-fatal error message command.");

    std::string output = testing::internal::GetCapturedStderr();
    ASSERT_EQ(output, "Common-Utilities:\n\tTesting the output of the non-fatal error message command.\n");
}

GTEST_TEST(testErrorFunctions, fatalErrorCausesProgramTermination)
{
    ASSERT_DEATH(
    {
        ErrorMessagePtr errorMessage { std::make_shared<FatalErrorMessage>("Common-Utilities", 1) };

        errorMessage->printErrorMessage("Fatal Error, Program Terminated.");
    }, "Common-Utilities:\n\tFatal Error, Program Terminated.\n");
}

GTEST_TEST(testErrorFunctions, readabilityOfConstructorIsEnhancedWithErrorSeverities)
{
    Exception exceptFatal1 {"Common-Utilities", "This would be the error message.", true};
    ASSERT_TRUE( exceptFatal1.isFatal() );

    Exception exceptFatal2 {"Common-Utilities", "This would be the error message.", ErrorSeverity::Fatal};
    ASSERT_TRUE( exceptFatal2.isFatal() );


    Exception exceptWarning1 {"Common-Utilities", "This would be the error message.", false};
    ASSERT_FALSE( exceptWarning1.isFatal() );

    Exception exceptWarning2 {"Common-Utilities", "This would be the error message.", ErrorSeverity::Warning};
    ASSERT_FALSE( exceptWarning2.isFatal() );
}

GTEST_TEST(testErrorFunctions, derivedExceptionClassIsCaughtByParentClass)
{
    testing::internal::CaptureStderr();

    try
    {
        try
        {
            throw Exception("Common-Utilities", "Let's throw a non-fatal warning.", ErrorSeverity::Warning);
        }
        catch (const Exception& except)
        {
            except.handleErrorWithMessage();

            throw;                  // Re-throw the error to catch it with std::exception
        }
    }
    catch (const std::exception& except)
    {
        std::cerr << except.what() << std::endl;
    }

    std::string expectedOutput1 {"Common-Utilities Warning:\n\tLet's throw a non-fatal warning.\n"};
    std::string expectedOutput2 {"Let's throw a non-fatal warning.\n"};

    std::string actualOutput = testing::internal::GetCapturedStderr();

    ASSERT_EQ(actualOutput, expectedOutput1 + expectedOutput2);
}

GTEST_TEST(testErrorFunctions, catchingFatalErrorMustResultInProgramTermination)
{
    ASSERT_DEATH(
    {
        try
        {
            throw Exception("Common-Utilities", "Must terminate program.", ErrorSeverity::Fatal);
        }
        catch (const std::exception& except)
        {
            std::cerr << except.what() << std::endl;
        }
    }, "Common-Utilities Fatal Error:\n\tMust terminate program.\n");
}

GTEST_TEST(testErrorFunctions, invalidInputExceptionResultsInProgramTermination)
{
    InvalidInputException invalid_input {"Common-Utilities"};
    ASSERT_TRUE( invalid_input.isFatal() );

    ASSERT_DEATH(
    {
        try
        {
            throw InvalidInputException("Common-Utilities");
        }
        catch (const Exception& except)
        {
            except.handleErrorWithMessage();
        }
    }, "Common-Utilities Fatal Error:\n\tUser supplied input is invalid.\n");
}

GTEST_TEST(testErrorFunctions, invalidInputExceptionPrintsNonDefaultMessage)
{
    ASSERT_DEATH(
    {
        try
        {
            throw InvalidInputException("Common-Utilities", "Let's throw a fatal error.");
        }
        catch (const Exception& except)
        {
            except.handleErrorWithMessage();
        }
    }, "Common-Utilities Fatal Error:\n\tLet's throw a fatal error.\n");
}

GTEST_TEST(testErrorFunctions, fileNotFoundExceptionResultsInProgramTermination)
{
    FileNotFoundException file_not_found {"Common-Utilities", "test.cpp"};
    ASSERT_TRUE( file_not_found.isFatal() );

    ASSERT_DEATH(
    {
        try
        {
            throw FileNotFoundException("Common-Utilities", "test.cpp");
        }
        catch (const Exception& except)
        {
            except.handleErrorWithMessage();
        }
    }, "Common-Utilities Fatal Error:\n\tUnable to open file: test.cpp\n");
}
