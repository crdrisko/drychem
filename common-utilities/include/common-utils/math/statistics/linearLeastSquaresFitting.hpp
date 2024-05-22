// Copyright (c) 2020-2024 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: linearLeastSquaresFitting.hpp
// Author: crdrisko
// Date: 10/26/2020-11:46:29
// Description: Function to perform a linear least-squares fitting for the supplied inputs

#ifndef DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_MATH_STATISTICS_LINEARLEASTSQUARESFITTING_HPP
#define DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_MATH_STATISTICS_LINEARLEASTSQUARESFITTING_HPP

#include <cstddef>
#include <iterator>
#include <type_traits>

#include "common-utils/math/statistics/statistics.hpp"
#include "common-utils/math/utils/mathExceptions.hpp"

namespace CppUtils::Math
{
    namespace details
    {
        /*!
         * An aggregate structure that can be used as the return type of the \c linearLeastSquaresFitting<>()
         *  function template.
         *
         * \note We hide the return type in the \c details namespace so the user is encouraged to use
         *       structured binding as the way to return from \c linearLeastSquaresFitting<>().
         */
        template<typename T_slope, typename T_intercept = T_slope, typename T_variance  = T_slope,
                 typename = std::enable_if_t<std::conjunction_v<std::is_default_constructible<T_slope>,
                                                                std::is_default_constructible<T_intercept>,
                                                                std::is_default_constructible<T_variance>>>>
        struct LinearLeastSquaresResult
        {
            T_slope slope {};
            T_intercept intercept {};
            T_variance variance {};
        };
    }   // namespace details

    /*!
     * Calculates the linear regression of a given function y with respect to x. Each of the functions,
     *  x and y, are represeted by containers with an iterator interface.
     *
     * \tparam IteratorX - The type of iterator used for the x container
     * \tparam IteratorY - The type of iterator used for the y container (defaults to the type of IteratorX)
     * \tparam        Tx - The type of data in the x container, must be default constructible
     * \tparam        Ty - The type of data in the x container, must be default constructible
     *
     * \param x_begin - The beginning of the range of x values to use
     * \param   x_end - The end of the range of x values to use
     * \param y_begin - The beginning of the range of y values to use
     * \param   y_end - The end of the range of y values to use
     *
     * \returns Three pieces of information which is contained in the specialized structure,
     *          \c details::LinearLeastSquaresResult. However, rather than use this strucure
     *          directly, we can use structured bindings to return the slope, intercept, and
     *          variance.
     *
     * \exception CppUtils::Math::InputSizeMismatch If the sizes of the two containers don't match, we will throw an exception
     *
     * \todo This is a complicated function and would probably lend itself well to a functor class
     * \note We calculate the variance of the slope not the standard deviation, because for physical quantities
     *       \c std::sqrt() isn't overloaded properly.
     */
    template<typename IteratorX, typename IteratorY = IteratorX,
             typename Tx = typename std::iterator_traits<IteratorX>::value_type,
             typename Ty = typename std::iterator_traits<IteratorY>::value_type,
             typename = std::enable_if_t<std::conjunction_v<std::is_default_constructible<Tx>, std::is_default_constructible<Ty>>>>
    constexpr decltype(auto) linearLeastSquaresFitting(IteratorX x_begin, IteratorX x_end, IteratorY y_begin, IteratorY y_end)
    {
        using Txx    = decltype(*x_begin * *x_begin);
        using Txy    = decltype(*x_begin * *y_begin);
        using Tyy    = decltype(*y_begin * *y_begin);
        using Ty_x   = decltype(*y_begin / *x_begin);
        using Tyy_xx = decltype(*y_begin * *y_begin / *x_begin / *x_begin);

        std::ptrdiff_t x_size {x_end - x_begin}, y_size {y_end - y_begin};

        if (x_size != y_size)
            throw InputSizeMismatch {"Common-Utilities", __FILE__, __LINE__};

        details::LinearLeastSquaresResult<Ty_x, Ty, Tyy_xx> results {};

        Tx x_average {calculateAverage(x_begin, x_end)};
        Ty y_average {calculateAverage(y_begin, y_end)};

        IteratorX x_iter = x_begin;
        IteratorY y_iter = y_begin;

        Txy slope_numerator {};
        Txx slope_denominator {};

        while (x_iter != x_end)
        {
            slope_numerator += (*x_iter - x_average) * (*y_iter - y_average);
            slope_denominator += (*x_iter - x_average) * (*x_iter - x_average);

            ++x_iter;
            ++y_iter;
        }

        results.slope     = slope_numerator / slope_denominator;
        results.intercept = y_average - (results.slope * x_average);

        Tyy var_numerator {};

        x_iter = x_begin;
        y_iter = y_begin;

        while (y_iter != y_end)
        {
            Ty res {*y_iter - (results.slope * (*x_iter) + results.intercept)};
            var_numerator += res * res;

            ++x_iter;
            ++y_iter;
        }

        results.variance = var_numerator / (slope_denominator * (y_size - 2));

        return results;
    }
}   // namespace CppUtils::Math

#endif
