// Copyright (c) 2020-2025 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: centeredDifferenceMethod.hpp
// Author: crdrisko
// Date: 11/13/2020-10:54:15
// Description: Approximating the derivative of a function using the centered difference method

#ifndef DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_MATH_CALCULUS_DIFFERENTIATION_CENTEREDDIFFERENCEMETHOD_HPP
#define DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_MATH_CALCULUS_DIFFERENTIATION_CENTEREDDIFFERENCEMETHOD_HPP

#include <algorithm>
#include <cstddef>
#include <iterator>
#include <type_traits>
#include <vector>

#include "common-utils/math/calculus/differentiation/backwardsDifferenceMethod.hpp"
#include "common-utils/math/calculus/differentiation/forwardDifferenceMethod.hpp"
#include "common-utils/math/utils/mathExceptions.hpp"

namespace CppUtils::Math
{
    /*!
     * A function taking the derivative (by numerical methods) of a given function y with respect to x.
     *  Each of the functions, x and y, are represeted by containers with an iterator interface. The
     *  function computes the following:
     *      \f$\frac{dy}{dx} \approx \frac{\frac{y_{n+1} - y_n}{x_{n+1} - x_n} + \frac{y_n - y_{n-1}}{x_n - x_{n-1}}}{2}.\f$
     *
     * \tparam IteratorX - The type of iterator used for the x container
     * \tparam IteratorY - The type of iterator used for the y container (defaults to the type of IteratorX)
     * \tparam        Tx - The type of data in the x container, must be default constructible
     * \tparam        Ty - The type of data in the y container, must be default constructible
     *
     * \param           x_begin - The beginning of the range of x values to use
     * \param             x_end - The end of the range of x values to use
     * \param           y_begin - The beginning of the range of y values to use
     * \param             y_end - The end of the range of y values to use
     * \param correctBoundaries - Approximates the derivative on the ends with the forward and backwards methods
     *
     * \returns A vector with the same size as that of the input containers, however if the \c correctBoundaries
     *          flag is set to false, the size of the output will be two less than the input size.
     *
     * \exception CppUtils::Math::InputSizeMismatch If the sizes of the two containers don't match, we will throw an exception
     */
    template<typename IteratorX, typename IteratorY = IteratorX,
             typename Tx = typename std::iterator_traits<IteratorX>::value_type,
             typename Ty = typename std::iterator_traits<IteratorY>::value_type,
             typename = std::enable_if_t<std::conjunction_v<std::is_default_constructible<Tx>, std::is_default_constructible<Ty>>>>
    constexpr auto centeredDifferenceMethod(IteratorX x_begin, IteratorX x_end, IteratorY y_begin, IteratorY y_end,
        bool correctBoundaries = true)
    {
        using Ty_x = decltype(*y_begin / *x_begin);

        std::ptrdiff_t x_size {x_end - x_begin}, y_size {y_end - y_begin};

        if (x_size != y_size)
            throw InputSizeMismatch {"Common-Utilities", __FILE__, __LINE__};

        std::vector<Ty_x> dy_dx(x_size - 2);
        std::vector<Ty_x> forward  = forwardDifferenceMethod(x_begin, x_end, y_begin, y_end);
        std::vector<Ty_x> backward = backwardsDifferenceMethod(x_begin, x_end, y_begin, y_end);

        typename std::vector<Ty_x>::iterator forwardStart {forward.begin() + 1};

        // Optionally use forward and backwards approximations on last and first elements of the derivative, respectively
        if (correctBoundaries)
        {
            forward.push_back(backward.back());
            backward.insert(backward.begin(), forward.front());

            dy_dx.resize(x_size);

            forwardStart = forward.begin();
        }

        typename std::vector<Ty_x>::iterator back = backward.begin();

        std::transform(forwardStart, forward.end(), dy_dx.begin(), [&](auto fwd) { return (fwd + *back++) / 2; });

        return dy_dx;
    }

    /*!
     * \overload
     */
    template<typename ContainerX, typename ContainerY = ContainerX,
             typename = std::enable_if_t<std::conjunction_v<std::is_default_constructible<typename ContainerX::value_type>,
                                                            std::is_default_constructible<typename ContainerY::value_type>>>>
    constexpr auto centeredDifferenceMethod(const ContainerX& x, const ContainerY& y, bool correctBoundaries = true)
    {
        return centeredDifferenceMethod(x.begin(), x.end(), y.begin(), y.end(), correctBoundaries);
    }
}   // namespace CppUtils::Math

#endif
