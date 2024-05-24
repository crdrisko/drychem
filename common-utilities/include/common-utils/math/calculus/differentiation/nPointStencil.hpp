// Copyright (c) 2020-2024 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: nPointStencil.hpp
// Author: crdrisko
// Date: 10/06/2023-08:10:58
// Description: Approximating the derivative of a function using an n-point stencil determined at compile time

#ifndef DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_MATH_CALCULUS_DIFFERENTIATION_NPOINTSTENCIL_HPP
#define DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_MATH_CALCULUS_DIFFERENTIATION_NPOINTSTENCIL_HPP

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
    namespace details
    {
        /*!
         * A function taking the derivative (by numerical methods) of a given function y with respect to x.
         *  Each of the functions, x and y, are represeted by containers.
         *
         * \tparam          N - The nPointStencilMethod to use (5, 7, or 9)
         * \tparam ContainerX - A container for a default constructible type x
         * \tparam ContainerY - A container for a default constructible type y
         *
         * \param x - The x values to use
         * \param y - The y values to use
         *
         * \returns A vector of equal size to the input containers with default values for the beginning
         *           and end of the vector depending on the method used
         *
         * \exception CppUtils::Math::InputSizeMismatch If the sizes of the two containers don't match, we will throw an exception
         */
        template<std::size_t N, typename ContainerX, typename ContainerY = ContainerX,
                                typename = std::enable_if_t<std::conjunction_v<std::is_default_constructible<typename ContainerX::value_type>,
                                                                               std::is_default_constructible<typename ContainerY::value_type>>>>
        constexpr auto nPointStencilMethod(const ContainerX& x, const ContainerY& y)
        {
            using Ty_x = decltype(y.at(0) / x.at(0));

            if (x.size() != y.size())
                throw InputSizeMismatch {"Common-Utilities", __FILE__, __LINE__};

            std::vector<Ty_x> dy_dx(x.size());

            if constexpr(N == 5)
            {
                for (std::size_t i {2}; i < x.size() - 2; ++i)
                {
                    dy_dx[i] = (y[i - 2] - (8 * y[i + 1]) + (8 * y[i - 1]) - y[i + 2])
                             / (12 * (x[i + 1] - x[i]));
                }
            }
            else if constexpr(N == 7)
            {
                for (std::size_t i {3}; i < x.size() - 3; ++i)
                {
                    dy_dx[i] = ((-1 * y[i - 3]) + (9 * y[i - 2]) - (45 * y[i + 1]) + (45 * y[i - 1]) - (9 * y[i + 2]) + y[i + 3])
                             / (60 * (x[i + 1] - x[i]));
                }
            }
            else if constexpr(N == 9)
            {
                for (std::size_t i {4}; i < x.size() - 4; ++i)
                {
                    dy_dx[i] = ((3 * y[i - 4]) - (32 * y[i - 3]) + (168 * y[i - 2]) - (672 * y[i + 1]) + (672 * y[i - 1]) - (168 * y[i + 2]) + (32 * y[i + 3]) - (3 * y[i + 4]))
                             / (840 * (x[i + 1] - x[i]));
                }
            }

            return dy_dx;
        }
    }   // namespace details

    /*!
     * \overload
     */
    template<typename ContainerX, typename ContainerY = ContainerX,
             typename = std::enable_if_t<std::conjunction_v<std::is_default_constructible<typename ContainerX::value_type>,
                                                            std::is_default_constructible<typename ContainerY::value_type>>>>
    constexpr auto fivePointStencilMethod(const ContainerX& x, const ContainerY& y) { return details::nPointStencilMethod<5>(x, y); }

    /*!
     * \overload
     */
    template<typename ContainerX, typename ContainerY = ContainerX,
             typename = std::enable_if_t<std::conjunction_v<std::is_default_constructible<typename ContainerX::value_type>,
                                                            std::is_default_constructible<typename ContainerY::value_type>>>>
    constexpr auto sevenPointStencilMethod(const ContainerX& x, const ContainerY& y) { return details::nPointStencilMethod<7>(x, y); }

    /*!
     * \overload
     */
    template<typename ContainerX, typename ContainerY = ContainerX,
             typename = std::enable_if_t<std::conjunction_v<std::is_default_constructible<typename ContainerX::value_type>,
                                                            std::is_default_constructible<typename ContainerY::value_type>>>>
    constexpr auto ninePointStencilMethod(const ContainerX& x, const ContainerY& y) { return details::nPointStencilMethod<9>(x, y); }
}   // namespace CppUtils::Math

#endif
