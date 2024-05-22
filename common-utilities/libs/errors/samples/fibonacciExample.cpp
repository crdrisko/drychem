// Copyright (c) 2020-2024 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: fibonacciExample.cpp
// Author: crdrisko
// Date: 09/01/2020-12:36:23
// Description: An example of how to throw, catch, and rethrow any std::exception-derived exceptions for helpful error handling

#include <cstddef>
#include <exception>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include <common-utils/errors.hpp>

// Function prototypes
void printNFibonacciNumbers(std::size_t n);

int main()
{
    try
    {
        try
        {
            for (std::size_t i {1}; i <= 125; i *= 5)
            {
                std::cout << std::setw(5) << i << "): ";
                printNFibonacciNumbers(i);
            }
        }
        catch (const std::exception& except)
        {
            DryChem::ErrorMessage error;
            error.programName = "\nCommon-Utilities";
            error.message     = "An exception was thrown from " + std::string {except.what()};

            throw DryChem::FatalException(error);
        }
    }
    catch (const DryChem::FatalException& except)
    {
        except.handleErrorWithMessage();
    }
}

// Function definitions
void printNFibonacciNumbers(std::size_t n)
{
    std::vector<std::size_t> fibonacciNumbers;

    if (std::size_t maxNAllowed {94}; n > maxNAllowed)
        throw DryChem::FatalException {
            DryChem::ErrorMessage {"Common-Utilities", "Overflow error for type std::size_t.", __FILE__, __LINE__}};

    for (std::size_t i {}; i < n; ++i)
    {
        if (i <= 1)
            fibonacciNumbers.push_back(i);
        else
            fibonacciNumbers.push_back(fibonacciNumbers[i - 2] + fibonacciNumbers[i - 1]);

        std::cout << fibonacciNumbers[i] << " ";
    }

    std::cout << std::endl;
}
