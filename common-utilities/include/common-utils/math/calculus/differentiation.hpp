// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: differentiation.hpp
// Author: crdrisko
// Date: 10/28/2020-07:50:09
// Description: Some advanced mathematical functions relating to approximate differentiation methods

#ifndef COMMON_UTILITIES_DIFFERENTIATION_HPP
#define COMMON_UTILITIES_DIFFERENTIATION_HPP

#include <algorithm>
#include <cstddef>
#include <iterator>
#include <type_traits>
#include <vector>

#include "math/utils/mathExceptions.hpp"

namespace CppUtils::Math
{
    template<typename IteratorX, typename IteratorY = IteratorX,
             typename Tx = typename std::iterator_traits<IteratorX>::value_type,
             typename Ty = typename std::iterator_traits<IteratorY>::value_type,
             typename = std::enable_if_t<std::conjunction_v<std::is_default_constructible<Tx>, std::is_default_constructible<Ty>>>>
    constexpr decltype(auto) forwardDifferenceMethod(IteratorX x_begin, IteratorX x_end, IteratorY y_begin, IteratorY y_end)
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

    template<typename IteratorX, typename IteratorY = IteratorX,
             typename Tx = typename std::iterator_traits<IteratorX>::value_type,
             typename Ty = typename std::iterator_traits<IteratorY>::value_type,
             typename = std::enable_if_t<std::conjunction_v<std::is_default_constructible<Tx>, std::is_default_constructible<Ty>>>>
    constexpr decltype(auto) backwardsDifferenceMethod(IteratorX x_begin, IteratorX x_end, IteratorY y_begin, IteratorY y_end)
    {
        using Ty_x = decltype(*y_begin / *x_begin);

        std::ptrdiff_t x_size {x_end - x_begin}, y_size {y_end - y_begin};

        if (x_size != y_size)
            throw InputSizeMismatch {"Common-Utilities", __FILE__, __LINE__};

        std::vector<Ty_x> dy_dx;

        IteratorX x_iter {x_begin + 1};
        IteratorY y_iter {y_begin + 1};

        while (x_iter != x_end)
        {
            dy_dx.push_back((*y_iter - *(y_iter - 1)) / (*x_iter - *(x_iter - 1)));

            ++x_iter;
            ++y_iter;
        }

        return dy_dx;
    }

    template<typename IteratorX, typename IteratorY = IteratorX,
             typename Tx = typename std::iterator_traits<IteratorX>::value_type,
             typename Ty = typename std::iterator_traits<IteratorY>::value_type,
             typename = std::enable_if_t<std::conjunction_v<std::is_default_constructible<Tx>, std::is_default_constructible<Ty>>>>
    constexpr decltype(auto) centeredDifferenceMethod(IteratorX x_begin, IteratorX x_end, IteratorY y_begin, IteratorY y_end,
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
}   // namespace CppUtils::Math

#endif
