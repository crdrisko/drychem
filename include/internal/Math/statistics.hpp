// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: statistics.hpp - Version 1.0.0
// Author: cdrisko
// Date: 02/03/2020-08:22:29
// Description: Common mathematical function definitions and prototypes relating to statistics

#ifndef UTILITIES_API_STATISTICS_HPP
#define UTILITIES_API_STATISTICS_HPP

#include <map>
#include <cmath>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include "../Errors/errorUtilities.hpp"

namespace Utilities_API::Math
{
    inline int findOrderOfMagnitude(const long double& value)
    {
        return std::floor(std::log10(value));
    }

    inline long double findAbsoluteError(const long double& expectedValue, const int& significantFigures)
    {
        return std::pow(10, findOrderOfMagnitude(expectedValue) - (significantFigures - 1));
    }

    template<typename T>
    inline T calculateAverage(const std::vector<T>& values)
    {
        return std::accumulate(values.begin(), values.end(), static_cast<T>(0)) / values.size();
    }

    template<typename T>
    inline std::vector<T> averageCorrection(const std::vector<T>& values)
    {
        std::vector<T> newValues(values.size());
        T averageValue { calculateAverage(values) };

        std::transform(values.begin(), values.end(), newValues.begin(), [&](const T& value)
            -> T { return value - averageValue; });

        return newValues;
    }


    template<typename T>
    inline std::map<std::string, T> linearLeastSquaresFitting(const std::vector<T>& x,
        const std::vector<T>& y)
    {
        if (x.size() != y.size())
            Errors::printFatalErrorMessage (1, "The vectors x and y must have the same number of elements.");

        std::vector<T> newX { averageCorrection(x) };
        std::vector<T> newY { averageCorrection(y) };

        std::map<std::string, T> fitParameters;

        std::vector<T> newXSquared(x.size());

        std::transform(newX.begin(), newX.end(), newXSquared.begin(), [](const T& x_value)
            -> T { return x_value * x_value; });

        T slope_numerator { std::inner_product(newX.begin(), newX.end(), newY.begin(), static_cast<T>(0)) };
        T slope_denominator { std::accumulate(newXSquared.begin(), newXSquared.end(), static_cast<T>(0)) };

        fitParameters["slope"] = slope_numerator / slope_denominator;
        fitParameters["intercept"] = calculateAverage(y) - (fitParameters["slope"] * calculateAverage(x));

        return fitParameters;
    }
}

#endif
