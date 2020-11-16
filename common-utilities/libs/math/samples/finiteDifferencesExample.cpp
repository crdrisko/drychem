// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: finiteDifferencesExample.cpp
// Author: crdrisko
// Date: 10/29/2020-08:31:22
// Description: An example of how to use the math library to approximate derivatives and integrals of a given function

#include <algorithm>
#include <cstddef>
#include <exception>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

#include <common-utils/errors.hpp>
#include <common-utils/math.hpp>

// Function prototypes
std::vector<double> differentiateThenIntegrate(const std::vector<double>& x, const std::vector<double>& y);
std::vector<double> integrateThenDifferentiate(const std::vector<double>& x, const std::vector<double>& y);
void validate(const std::vector<double>& expected, const std::vector<double>& actual, double tolerance);

int main()
{
    try
    {
        try
        {
            const std::size_t num_elements = 100'002ul;
            std::vector<double> x(num_elements), y(num_elements);

            std::iota(x.begin(), x.end(), 0.0l);
            std::transform(x.begin(), x.end(), y.begin(), [](auto& x) {
                x /= 10;                            // Scale back x for more accurate results
                return (4 * x * x) + (2 * x) - 7;   // y = 4x^2 + 2x - 7
            });

            const double tolerance = 2 * (x[1] - x[0]);


            // Expect: ∫ (dy/dx) dx = 4 x^2 + 2x + constant = y
            std::vector<double> expected1 = differentiateThenIntegrate(x, y);

            std::cout << "The calculation of ∫(dy / dx) dx resulted in ";
            validate(y, expected1, tolerance);


            // Expect: d (∫ y dx) / dx = 4 x^2 + 2 x - 7 = y
            std::vector<double> expected2 = integrateThenDifferentiate(x, y);

            std::cout << "The calculation of d(∫y dx) / dx resulted in ";
            validate(y, expected2, tolerance);
        }
        catch (const std::exception& except)
        {
            DryChem::ErrorMessage error;
            error.programName = "Common-Utilities";
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
std::vector<double> differentiateThenIntegrate(const std::vector<double>& x, const std::vector<double>& y)
{
    auto derivative = DryChem::centeredDifferenceMethod(x.begin(), x.end(), y.begin(), y.end());
    auto integral   = DryChem::cumulativeTrapzIntegration(x.begin(), x.end(), derivative.begin(), derivative.end(), 0.0);

    // Account for the constant term we know we're missing from integration
    std::transform(integral.begin(), integral.end(), integral.begin(), [](auto val) { return val + 7; });

    return integral;
}

std::vector<double> integrateThenDifferentiate(const std::vector<double>& x, const std::vector<double>& y)
{
    auto integral   = DryChem::cumulativeTrapzIntegration(x.begin(), x.end(), y.begin(), y.end(), 0.0);
    auto derivative = DryChem::centeredDifferenceMethod(x.begin(), x.end(), integral.begin(), integral.end());

    return derivative;
}

void validate(const std::vector<double>& expected, const std::vector<double>& actual, double tolerance)
{
    std::size_t counter {};

    // We should account for the inaccuarcy of the ends by skipping over the comparison here
    for (std::size_t i {1}; i < expected.size() - 1; ++i)
        if (expected[i] - actual[i] <= tolerance)
            ++counter;

    std::cout << counter << " out of " << actual.size() - 2 << " elements within " << tolerance << " of the exact result."
              << std::endl;
}
