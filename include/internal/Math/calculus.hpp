// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: calculus.hpp - Version 1.0.0
// Author: cdrisko
// Date: 02/03/2020-08:22:39
// Description: Common mathematical function definitions and prototypes relating to calculus

#ifndef UTILITIES_API_CALCULUS_HPP
#define UTILITIES_API_CALCULUS_HPP

#include <vector>
#include <string_view>

namespace Utilities_API::Math
{
    std::vector<long double> finiteDifferenceMethod(std::vector<long double> x, std::vector<long double> y,
        std::string_view method="Centered");

    std::vector<long double> cumulativeTrapz(std::vector<long double> x, std::vector<long double> y);

    inline long double trapz(long double x1, long double x2, long double y1, long double y2)
    {
        return (x2 - x1) * (y1 + y2) / 2;
    }
}

#endif
