// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: integration.hpp
// Author: crdrisko
// Date: 10/28/2020-07:49:21
// Description:Some advanced mathematical functions relating to approximate integration methods

#ifndef COMMON_UTILITIES_INTEGRATION_HPP
#define COMMON_UTILITIES_INTEGRATION_HPP

#include <cstddef>
#include <iterator>
#include <optional>
#include <type_traits>
#include <utility>
#include <vector>

#include "math/utils/mathExceptions.hpp"

namespace CppUtils::Math
{
    /*!
     * A simple function responsible for the main work in the cumulativeTrapzIntegration() function,
     *  this computes the following approximation for the integral:
     *      \f$\displaystyle \int_{x_1}^{x_2} y \,dx \approx (x_2 - x_1) \cdot {\frac{y_1 + y_2}{2}}.\f$
     *
     * \tparam Tx The type of x
     * \tparam Ty The type of y (defaults to the type of x)
     *
     * \param x1 The beginning of the range we are integrating the function over
     * \param x2 The end of the range we are integrating the function over
     * \param y1 The value of the function we are integrating at the point \c x1
     * \param y2 The end of the function we are integrating at the point \c x2
     *
     * \returns An approximation of the integral of y in the range from x1 to x2
     */
    template<typename Tx, typename Ty = Tx>
    constexpr auto trapz(Tx x1, Tx x2, Ty y1, Ty y2) noexcept
    {
        return ((x2 - x1) * (y1 + y2)) / 2;
    }


    /*!
     * A function taking the integral (by numerical methods) of a given function y with respect to x.
     *  Each of the functions, x and y, are represeted by containers with an iterator interface.
     *
     * \tparam IteratorX The type of iterator used for the x container
     * \tparam IteratorY The type of iterator used for the y container (defaults to the type of IteratorX)
     * \tparam Tx        The type of data in the x container, must be default constructible
     * \tparam Ty        The type of data in the x container, must be default constructible
     *
     * \param x_begin      The beginning of the range of x values to use
     * \param x_end        The end of the range of x values to use
     * \param y_begin      The beginning of the range of y values to use
     * \param y_end        The end of the range of y values to use
     * \param initialValue An optional value for use as the first point in the returned vector
     *
     * \returns A vector with a size of one less than the input containers, however if the \c initialValue
     *          parameter is set, the size of the output will be the same as than of the input.
     *
     * \exception CppUtils::Math::InputSizeMismatch If the sizes of the two containers don't match, we will throw an exception
     */
    template<typename IteratorX, typename IteratorY = IteratorX,
             typename Tx = typename std::iterator_traits<IteratorX>::value_type,
             typename Ty = typename std::iterator_traits<IteratorY>::value_type,
             typename = std::enable_if_t<std::conjunction_v<std::is_default_constructible<Tx>, std::is_default_constructible<Ty>>>>
    constexpr auto cumulativeTrapzIntegration(IteratorX x_begin, IteratorX x_end, IteratorY y_begin, IteratorY y_end,
        std::optional<decltype(*x_begin * *y_begin)> initialValue = std::nullopt)
    {
        using Txy = decltype(*x_begin * *y_begin);

        std::ptrdiff_t x_size {x_end - x_begin}, y_size {y_end - y_begin};

        if (x_size != y_size)
            throw InputSizeMismatch {"Common-Utilities", __FILE__, __LINE__};

        const Txy init {};
        std::vector<Txy> y_cumulative;

        IteratorX x_iter = x_begin;
        IteratorY y_iter = y_begin;

        if (initialValue)
            y_cumulative.push_back(init);

        for (std::size_t i {}; i < static_cast<std::size_t>(x_size - 1); ++i, ++x_iter, ++y_iter)
        {
            Txy temp = trapz(*x_iter, *(x_iter + 1), *y_iter, *(y_iter + 1));

            if (!initialValue)
            {
                if (i == 0)
                    y_cumulative.push_back(temp);
                else
                    y_cumulative.push_back(y_cumulative[i - 1] + temp);
            }
            else
                y_cumulative.push_back(y_cumulative[i] + temp);
        }

        // Replace initial value if there is a non-zero value to replace
        if (initialValue && initialValue.value() != init)
            y_cumulative[0] = initialValue.value();

        return y_cumulative;
    }
    //! \example finiteDifferencesExample.cpp

    /*!
     * \overload
     */
    template<typename ContainerX, typename ContainerY = ContainerX,
             typename Tx = typename ContainerX::value_type,
             typename Ty = typename ContainerY::value_type,
             typename = std::enable_if_t<std::conjunction_v<std::is_default_constructible<Tx>, std::is_default_constructible<Ty>>>>
    constexpr auto cumulativeTrapzIntegration(const ContainerX& x, const ContainerY& y,
        std::optional<decltype(std::declval<Tx>() * std::declval<Ty>())> initialValue = std::nullopt)
    {
        return cumulativeTrapzIntegration(x.begin(), x.end(), y.begin(), y.end(), initialValue);
    }
}   // namespace CppUtils::Math

#endif
