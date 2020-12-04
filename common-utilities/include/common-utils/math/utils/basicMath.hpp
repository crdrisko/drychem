// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: basicMath.hpp
// Author: cdrisko
// Date: 01/31/2020-15:42:41
// Description: Common mathematical functions

#ifndef DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_MATH_UTILS_BASICMATH_HPP
#define DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_MATH_UTILS_BASICMATH_HPP

#include <algorithm>
#include <type_traits>
#include <vector>

namespace CppUtils::Math
{
    /*!
     * Function to determine whether an integral type is even.
     *
     * \tparam T The type of the input to check, must be an integral type
     *
     * \param value The input integral to check
     */
    template<typename T, typename = std::enable_if_t<std::is_integral_v<T> && !std::is_same_v<T, bool>>>
    constexpr bool isEven(T value)
    {
        return !(value % 2);
    }

    /*!
     * Function to determine whether an integral type is odd.
     *
     * \tparam T The type of the input to check, must be an integral type
     *
     * \param value The input integral to check
     */
    template<typename T, typename = std::enable_if_t<std::is_integral_v<T>>>
    constexpr bool isOdd(T value)
    {
        return !isEven(value);
    }


    /*!
     * A function to determine whether a given value is greater than or equal to a
     *  minimum value and less than or equal to a maximum value.
     *
     * \tparam T The type of the input variables
     *
     * \param value The value we want to compare
     * \param min   The minimum number in the range
     * \param max   The maximum number in the range
     */
    template<typename T>
    constexpr bool withinRange(T value, T min, T max)
    {
        return value <= max && value >= min;
    }

    /*!
     * \overload
     */
    template<int Min, int Max, typename T>
    constexpr bool withinRange(T value)
    {
        return withinRange(value, static_cast<T>(Min), static_cast<T>(Max));
    }


    /*!
     * A function to linearly interpolate some function over a range set by an input vector.
     *
     * \tparam T The type of the values we are interpolating
     *
     * \param x  The input vector containing the values we are interpolating over
     * \param y1 The value of the function we are interpolating in the beginning of the range
     * \param y2 The value of the function we are interpolating in the end of the range
     *
     * \returns A vector of y values with a size equal to that of the input \c x
     */
    template<typename T>
    constexpr std::vector<T> linearlyInterpolate(const std::vector<T>& x, T y1, T y2)
    {
        std::vector<T> y(x.size());

        T slope     = (y2 - y1) / (x.back() - x.front());
        T intercept = y1 - slope * x.front();

        std::transform(x.begin(), x.end(), y.begin(), [=](auto val) { return slope * val + intercept; });
        return y;
    }
}   // namespace CppUtils::Math

#endif
