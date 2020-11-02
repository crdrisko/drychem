// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: basicMath.hpp
// Author: cdrisko
// Date: 01/31/2020-15:42:41
// Description: Common mathematical functions

#ifndef COMMON_UTILITIES_BASICMATH_HPP
#define COMMON_UTILITIES_BASICMATH_HPP

#include <algorithm>
#include <type_traits>
#include <vector>

namespace CppUtils::Math
{
    template<typename T, typename = std::enable_if_t<std::is_integral_v<T>>>
    constexpr bool isEven(T i)
    {
        return !(i % 2);
    }

    template<typename T, typename = std::enable_if_t<std::is_integral_v<T>>>
    constexpr bool isOdd(T i)
    {
        return !isEven(i);
    }


    template<typename T>
    constexpr bool withinRange(T value, T min, T max)
    {
        return value <= max && value >= min;
    }

    template<int Min, int Max, typename T>
    constexpr bool withinRange(T value)
    {
        return withinRange(value, static_cast<T>(Min), static_cast<T>(Max));
    }


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
