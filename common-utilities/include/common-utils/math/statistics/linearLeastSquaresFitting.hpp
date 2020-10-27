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
    template<typename T_slope, typename T_intercept = T_slope, typename T_variance  = T_slope,
             typename = std::enable_if_t<std::is_default_constructible_v<T_slope>
                                      && std::is_default_constructible_v<T_intercept>
                                      && std::is_default_constructible_v<T_variance>>>
    struct LinearLeastSquaresResult
    {
        T_slope slope {};
        T_intercept intercept {};
        T_variance variance_slope {};
    };

    /* All these template parameters are necessary if we want to fit containers of physical quantities
        as well as the built-in types */
    template<typename IteratorX, typename IteratorY = IteratorX,
             typename Tx = typename std::iterator_traits<IteratorX>::value_type,
             typename Ty = typename std::iterator_traits<IteratorY>::value_type,
             typename = std::enable_if_t<std::is_default_constructible_v<Tx> && std::is_default_constructible_v<Ty>>>
    constexpr decltype(auto) linearLeastSquaresFitting(IteratorX x_begin, IteratorX x_end, IteratorY y_begin, IteratorY y_end)
    {
        using Txx    = decltype(*x_begin * *x_begin);
        using Txy    = decltype(*x_begin * *y_begin);
        using Tyy    = decltype(*y_begin * *y_begin);
        using Ty_x   = decltype(*y_begin / *x_begin);
        using Tyy_xx = decltype((*y_begin * *y_begin) / (*x_begin * *x_begin));

        std::ptrdiff_t x_size {x_end - x_begin}, y_size {y_end - y_begin};

        if (x_size != y_size)
            throw InputSizeMismatch {"Common-Utilities"};

        const Txx xx_init {};
        const Txy xy_init {};
        const Tyy yy_init {};

        Tx x_average {calculateAverage(x_begin, x_end)};
        Ty y_average {calculateAverage(y_begin, y_end)};

        std::vector<Txy> numerator(x_size);
        std::vector<Txx> denominator(x_size);

        IteratorY y_iter = y_begin;

        std::transform(x_begin, x_end, numerator.begin(), [&](auto x) { return (x - x_average) * (*y_iter++ - y_average); });
        std::transform(x_begin, x_end, denominator.begin(), [&](auto x) { return (x - x_average) * (x - x_average); });

        Txy slope_numerator   = std::accumulate(numerator.begin(), numerator.end(), xy_init);
        Txx slope_denominator = std::accumulate(denominator.begin(), denominator.end(), xx_init);

        Ty_x slope   = slope_numerator / slope_denominator;
        Ty intercept = y_average - (slope * x_average);

        /* Calculate the variance of the slope - don't use standard deviation here because for physical quantities
            std::sqrt() isn't overloaded properly */
        std::vector<Tyy> y_predicted(y_size);

        IteratorX x_iter = x_begin;

        std::transform(y_begin, y_end, y_predicted.begin(),
            [&](auto y) { auto res {y - (slope * *x_iter++ + intercept)}; return res * res; });

        Tyy var_numerator   = std::accumulate(y_predicted.begin(), y_predicted.end(), yy_init);
        Txx var_denominator = slope_denominator * (y_size - 2);

        Tyy_xx variance = var_numerator / var_denominator;

        return LinearLeastSquaresResult<Ty_x, Ty, Tyy_xx> {slope, intercept, variance};
    }
}   // namespace CppUtils::Math

#endif
