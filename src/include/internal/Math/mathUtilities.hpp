// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: mathUtilities.hpp - Version 1.0.0
// Author: cdrisko
// Date: 01/31/2020-15:42:41
// Description: Common mathematical function definitions and prototypes

#ifndef UTILITIES_API_MATHUTILITIES_HPP
#define UTILITIES_API_MATHUTILITIES_HPP

#include <cmath>
#include <vector>
#include <numeric>
#include <string_view>

namespace Utilities_API::Math
{
    std::vector<long double> finiteDifferenceMethod(std::vector<long double> x, std::vector<long double> y,
        std::string_view method="Centered");
    std::vector<long double> cumulativeTrapz(std::vector<long double> x, std::vector<long double> y);
    std::vector<long double> linearlyInterpolate(std::vector<long double> x, long double y1, long double y2);


    inline long double trapz(long double x1, long double x2, long double y1, long double y2)
    {
        return (x2 - x1) * (y1 + y2) / 2;
    }


    inline int findOrderOfMagnitude(const long double& value)
    {
        return std::floor(std::log10(value));
    }


    inline long double findAbsoluteError(const long double& expectedValue, const int& significantFigures)
    {
        return std::pow(10, findOrderOfMagnitude(expectedValue) - (significantFigures - 1));
    }


    template<typename T>
    inline bool withinRange(const T& value, const T& min, const T& max)
    {
        return (value <= max) && (value >= min);
    }


    template<int min, int max, typename T>
    inline bool withinRange(const T& value)
    {
        return withinRange(value, static_cast<T>(min), static_cast<T>(max));
    }


    template<typename T>
    T calculateAverage(std::vector<T> values)
    {
        T averageValue { std::accumulate(values.begin(), values.end(), static_cast<T>(0)) / values.size() };
        return averageValue;
    }
}

#endif
