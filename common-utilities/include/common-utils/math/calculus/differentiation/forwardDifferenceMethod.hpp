// Copyright (c) 2020-2021 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: forwardDifferenceMethod.hpp
// Author: crdrisko
// Date: 11/13/2020-10:53:58
// Description: Approximating the derivative of a function using the forward difference method

#ifndef DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_MATH_CALCULUS_DIFFERENTIATION_FORWARDDIFFERENCEMETHOD_HPP
#define DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_MATH_CALCULUS_DIFFERENTIATION_FORWARDDIFFERENCEMETHOD_HPP

#include <cstddef>
#include <iterator>
#include <type_traits>
#include <vector>

#include "common-utils/math/utils/mathExceptions.hpp"

namespace CppUtils::Math
{
    /*!
     * A function taking the derivative (by numerical methods) of a given function y with respect to x.
     *  Each of the functions, x and y, are represeted by containers with an iterator interface. The
     *  function computes the following:
     *      \f$\frac{dy}{dx} \approx \frac{y_{n+1} - y_n}{x_{n+1} - x_n}.\f$
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
     * \returns A vector with a size of one less than the input containers.
     *
     * \exception CppUtils::Math::InputSizeMismatch If the sizes of the two containers don't match, we will throw an exception
     */
    template<typename IteratorX, typename IteratorY = IteratorX,
             typename Tx = typename std::iterator_traits<IteratorX>::value_type,
             typename Ty = typename std::iterator_traits<IteratorY>::value_type,
             typename = std::enable_if_t<std::conjunction_v<std::is_default_constructible<Tx>, std::is_default_constructible<Ty>>>>
    constexpr auto forwardDifferenceMethod(IteratorX x_begin, IteratorX x_end, IteratorY y_begin, IteratorY y_end)
    {
        using Ty_x = decltype(*y_begin / *x_begin);

        std::ptrdiff_t x_size {x_end - x_begin}, y_size {y_end - y_begin};

        if (x_size != y_size)
            throw InputSizeMismatch {"Common-Utilities", __FILE__, __LINE__};

        std::vector<Ty_x> dy_dx;

        IteratorX x_iter {x_begin};
        IteratorY y_iter {y_begin};

        while (x_iter != x_end - 1)
        {
            dy_dx.push_back((*(y_iter + 1) - *y_iter) / (*(x_iter + 1) - *x_iter));

            ++x_iter;
            ++y_iter;
        }

        return dy_dx;
    }

    /*!
     * \overload
     */
    template<typename ContainerX, typename ContainerY = ContainerX,
             typename = std::enable_if_t<std::conjunction_v<std::is_default_constructible<typename ContainerX::value_type>,
                                                            std::is_default_constructible<typename ContainerY::value_type>>>>
    constexpr auto forwardDifferenceMethod(const ContainerX& x, const ContainerY& y)
    {
        return forwardDifferenceMethod(x.begin(), x.end(), y.begin(), y.end());
    }
}   // namespace CppUtils::Math

#endif
