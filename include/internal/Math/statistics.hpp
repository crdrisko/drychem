// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: statistics.hpp - Version 1.0.0
// Author: cdrisko
// Date: 02/03/2020-08:22:29
// Description: Common mathematical function definitions and prototypes relating to statistics

#ifndef UTILITIES_API_STATISTICS_HPP
#define UTILITIES_API_STATISTICS_HPP

#include <cmath>
#include <vector>
#include <numeric>

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
    T calculateAverage(std::vector<T> values)
    {
        T averageValue { std::accumulate(values.begin(), values.end(), static_cast<T>(0)) / values.size() };
        return averageValue;
    }
}

#endif
