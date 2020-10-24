// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: statistics.hpp
// Author: cdrisko
// Date: 02/03/2020-08:22:29
// Description: Common mathematical functions relating to statistics

#ifndef COMMON_UTILITIES_STATISTICS_HPP
#define COMMON_UTILITIES_STATISTICS_HPP

#include <algorithm>
#include <cmath>
#include <iterator>
#include <numeric>
#include <type_traits>
#include <vector>

namespace CppUtils::Math
{
    template<typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
    constexpr int findOrderOfMagnitude(T value) noexcept
    {
        return std::floor(std::log10(value));
    }

    template<typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
    constexpr long double findAbsoluteError(T expectedValue, int significantFigures) noexcept
    {
        return std::pow(10, findOrderOfMagnitude(expectedValue) - (significantFigures - 1));
    }

    template<typename Iterator, typename T = typename std::iterator_traits<Iterator>::value_type,
             typename = std::enable_if_t<std::is_default_constructible_v<T>>>
    constexpr T calculateAverage(Iterator x_begin, Iterator x_end)
    {
        T init {};
        T result {std::accumulate(x_begin, x_end, init) / (x_end - x_begin)};

        return result;
    }

    template<typename Iterator, typename T = typename std::iterator_traits<Iterator>::value_type,
             typename = std::enable_if_t<std::is_default_constructible_v<T>>>
    constexpr T calculateStandardDeviation(Iterator x_begin, Iterator x_end)
    {
        T init {};
        T average {calculateAverage(x_begin, x_end)};

        std::vector<T> averageCorrectedValues(x_end - x_begin);

        std::transform(x_begin, x_end, averageCorrectedValues.begin(),
            [&](auto x) { return (x - average) * (x - average); });

        T result = std::sqrt(
            std::accumulate(averageCorrectedValues.begin(), averageCorrectedValues.end(), init) / (x_end - x_begin - 1));

        return result;
    }
}   // namespace CppUtils::Math

#endif
