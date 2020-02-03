// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: basicMath.cpp - Version 1.0.0
// Author: cdrisko
// Date: 02/03/2020-08:34:59
// Description: Common mathematical function definitions

#include "../../include/internal/Math/basicMath.hpp"

using std::vector;

namespace Utilities_API::Math
{
    vector<long double> linearlyInterpolate(vector<long double> x, long double y1, long double y2)
    {
        vector<long double> y;

        long double x2 { x[x.size() - 1] };
        long double x1 { x[0] };

        long double slope { (y2 - y1) / (x2 - x1) };
        long double intercept { y1 - (slope * x1) };

        for (const auto& element : x)
            y.push_back(slope * element + intercept);

        return y;
    }
}
