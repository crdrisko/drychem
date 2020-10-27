// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: linearLeastSquaresFitting.hpp
// Author: crdrisko
// Date: 10/26/2020-11:46:29
// Description: Function to perform a linear least-squares fitting for the supplied inputs

#ifndef COMMON_UTILITIES_LINEARLEASTSQUARESFITTING_HPP
#define COMMON_UTILITIES_LINEARLEASTSQUARESFITTING_HPP

#include <algorithm>
#include <cmath>
#include <cstddef>
#include <iterator>
#include <numeric>
#include <type_traits>
#include <vector>

#include "math/statistics/statistics.hpp"
#include "math/utils/mathExceptions.hpp"

namespace CppUtils::Math
{
    // An aggregate structure that can be used as the return type of the linearLeastSquaresFitting<>() function template
    template<typename T, typename = std::enable_if_t<std::is_default_constructible_v<T>>>
    struct LinearLeastSquaresResult
    {
        T slope {};
        T intercept {};
        T stdDev_slope {};
    };


    template<typename Iterator, typename T = typename std::iterator_traits<Iterator>::value_type,
             typename = std::enable_if_t<std::is_default_constructible_v<T>>>
    constexpr decltype(auto) linearLeastSquaresFitting(Iterator x_begin, Iterator x_end, Iterator y_begin, Iterator y_end)
    {
        std::ptrdiff_t x_size {x_end - x_begin}, y_size {y_end - y_begin};

        if (x_size != y_size)
            throw InputSizeMismatch {"Common-Utilities"};

        const T init {};
        T slope {}, intercept {}, stdDev {};

        T x_average {calculateAverage(x_begin, x_end)};
        T y_average {calculateAverage(y_begin, y_end)};

        std::vector<T> numerator(x_size);
        std::vector<T> denominator(x_size);

        auto y_iter = y_begin;

        std::transform(x_begin, x_end, numerator.begin(), [&](auto x) { return (x - x_average) * (*y_iter++ - y_average); });
        std::transform(x_begin, x_end, denominator.begin(), [&](auto x) { return (x - x_average) * (x - x_average); });

        T slope_numerator   = std::accumulate(numerator.begin(), numerator.end(), init);
        T slope_denominator = std::accumulate(denominator.begin(), denominator.end(), init);

        slope     = slope_numerator / slope_denominator;
        intercept = y_average - (slope * x_average);

        // Calculate standard deviation in slope
        std::vector<T> y_predicted(y_size);

        auto x_iter = x_begin;

        std::transform(y_begin, y_end, y_predicted.begin(),
            [&](auto y) { auto res {y - (slope * *x_iter++ + intercept)}; return res * res; });

        T stdDev_numerator   = std::accumulate(y_predicted.begin(), y_predicted.end(), init);
        T stdDev_denominator = slope_denominator * (y_size - 2);

        stdDev = std::sqrt(stdDev_numerator / stdDev_denominator);

        return LinearLeastSquaresResult<T> {slope, intercept, stdDev};
    }
}   // namespace CppUtils::Math

#endif
