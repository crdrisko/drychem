// Copyright (c) 2020-2021 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: fivePointStencil.hpp
// Author: crdrisko
// Date: 10/06/2023-08:10:58
// Description:

#ifndef DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_MATH_CALCULUS_DIFFERENTIATION_FIVEPOINTSTENCIL_HPP
#define DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_MATH_CALCULUS_DIFFERENTIATION_FIVEPOINTSTENCIL_HPP

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
    template<typename ContainerX, typename ContainerY = ContainerX,
             typename = std::enable_if_t<std::conjunction_v<std::is_default_constructible<typename ContainerX::value_type>,
                                                            std::is_default_constructible<typename ContainerY::value_type>>>>
    constexpr auto fivePointStencilMethod(const ContainerX& x, const ContainerY& y)
    {
        using Ty_x = decltype(y.at(0) / x.at(0));

        if (x.size() != y.size())
            throw InputSizeMismatch {"Common-Utilities", __FILE__, __LINE__};

        std::vector<Ty_x> dy_dx(x.size());

        for (std::size_t i {2}; i < x.size() - 2; ++i)
        {
            dy_dx[i] = ((8 * y[i + 1]) - (8 * y[i - 1]) - y[i + 2] + y[i - 2]) / (12 * (x[i + 1] - x[i]));
        }

        return dy_dx;
    }
}   // namespace CppUtils::Math

#endif
