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
#include <vector>

#include "math/utils/mathExceptions.hpp"

namespace CppUtils::Math
{
    template<typename Tx, typename Ty = Tx>
    constexpr auto trapz(Tx x1, Tx x2, Ty y1, Ty y2) { return ((x2 - x1) * (y1 + y2)) / 2; }

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
}   // namespace CppUtils::Math

#endif
