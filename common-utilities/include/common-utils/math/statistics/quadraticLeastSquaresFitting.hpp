// Copyright (c) 2020-2024 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: quadraticLeastSquaresFitting.hpp
// Author: crdrisko
// Date: 10/11/2023-07:27:16
// Description:

#ifndef DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_MATH_STATISTICS_QUADRATICLEASTSQUARESFITTING_HPP
#define DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_MATH_STATISTICS_QUADRATICLEASTSQUARESFITTING_HPP

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
         * An aggregate structure that can be used as the return type of the \c quadraticLeastSquaresFitting<>()
         *  function template.
         * 
         * Returns the coefficents according to the following equation: ax^2 + bx + c.
         *
         * \note We hide the return type in the \c details namespace so the user is encouraged to use
         *       structured binding as the way to return from \c quadraticLeastSquaresFitting<>().
         */
        template<typename T_a, typename T_b = T_a, typename T_c = T_a,
                 typename = std::enable_if_t<std::conjunction_v<std::is_default_constructible<T_a>,
                                                                std::is_default_constructible<T_b>,
                                                                std::is_default_constructible<T_c>>>>
        struct QuadraticLeastSquaresResult
        {
            T_a a {};
            T_b b {};
            T_c c {};
        };
    }   // namespace details

    /*!
     * Calculates the quadratic least squares regression of a given function y with respect to x. Each of the functions,
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
     *          \c details::QuadraticLeastSquaresResult. However, rather than use this strucure
     *          directly, we can use structured bindings to return the parameters a, b, and c.
     *
     * \exception CppUtils::Math::InputSizeMismatch If the sizes of the two containers don't match, we will throw an exception
     *
     * \todo This is a complicated function and would probably lend itself well to a functor class
     */
    template<typename IteratorX, typename IteratorY = IteratorX,
        typename Tx = typename std::iterator_traits<IteratorX>::value_type,
        typename Ty = typename std::iterator_traits<IteratorY>::value_type,
        typename = std::enable_if_t<std::conjunction_v<std::is_default_constructible<Tx>, std::is_default_constructible<Ty>>>>
    constexpr decltype(auto) quadraticLeastSquaresFitting(IteratorX x_begin, IteratorX x_end, IteratorY y_begin, IteratorY y_end)
    {
        using Txx   = decltype(*x_begin * *x_begin);
        using Txxx  = decltype(*x_begin * *x_begin * *x_begin);
        using Txxxx = decltype(*x_begin * *x_begin * *x_begin * *x_begin);

        using Txy  = decltype(*x_begin * *y_begin);
        using Txxy = decltype(*x_begin * *x_begin * *y_begin);

        using Ty_x  = decltype(*y_begin / *x_begin);
        using Ty_xx = decltype(*y_begin / *x_begin / *x_begin);

        const std::ptrdiff_t x_size {x_end - x_begin}, y_size {y_end - y_begin};

        if (x_size != y_size)
            throw InputSizeMismatch {"Common-Utilities", __FILE__, __LINE__};

        details::QuadraticLeastSquaresResult<Ty_xx, Ty_x, Ty> results {};

        Tx x1 {};
        Txx x2 {};
        Txxx x3 {};
        Txxxx x4 {};

        Ty y1 {};

        Txy x1y1 {};
        Txxy x2y1 {};

        IteratorX x_iter = x_begin;
        IteratorY y_iter = y_begin;

        while (x_iter != x_end)
        {
            const Tx x_i = (*x_iter);
            const Ty y_i = (*y_iter);

            x1 += x_i;
            x2 += x_i * x_i;
            x3 += x_i * x_i * x_i;
            x4 += x_i * x_i * x_i * x_i;

            y1 += y_i;

            x1y1 += x_i * y_i;
            x2y1 += x_i * x_i * y_i;

            ++x_iter;
            ++y_iter;
        }

        auto denominator = x4 * (x2 * x_size - x1 * x1) - x3 * (x3 * x_size - x1 * x2) + x2 * (x3 * x1 - x2 * x2);

        auto a_numerator = x2y1 * (x2 * x_size - x1 * x1) - x3 * (x1y1 * x_size - x1 * y1) + x2 * (x1y1 * x1 - x2 * y1);
        auto b_numerator = x4 * (x1y1 * x_size - x1 * y1) - x2y1 * (x3 * x_size - x1 * x2) + x2 * (x3 * y1 - x1y1 * x2);
        auto c_numerator = x4 * (x2 * y1 - x1y1 * x1) - x3 * (x3 * y1 - x1y1 * x2) + x2y1 * (x3 * x1 - x2 * x2);

        results.a = a_numerator / denominator;
        results.b = b_numerator / denominator;
        results.c = c_numerator / denominator;

        return results;
    }
}   // namespace CppUtils::Math

#endif
