// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: statistics.cpp - Version 1.0.0
// Author: crdrisko
// Date: 02/16/2020-09:17:30
// Description: Common mathematical function definitions relating to statistics

#include <algorithm>
#include "../../include/internal/Math/statistics.hpp"
#include "../../include/internal/Errors/errorUtilities.hpp"

using std::vector;

namespace Utilities_API::Math
{
    vector<long double> correctForAverage(const vector<long double>& values)
    {
        vector<long double> newValues(values.size());
        long double averageValue { calculateAverage(values) };

        std::transform(values.begin(), values.end(), newValues.begin(), [&](const long double& value)
            -> long double { return value - averageValue; });

        return newValues;
    }


    std::map<std::string, long double> linearLeastSquaresFitting(const vector<long double>& x,
        const vector<long double>& y)
    {
        if (x.size() != y.size())
            Utilities_API::Errors::printFatalErrorMessage (1,
                "The vectors x and y must have the same number of elements.");

        vector<long double> newX { correctForAverage(x) };
        vector<long double> newY { correctForAverage(y) };

        std::map<std::string, long double> fitParameters;

        vector<long double> newXSquared(x.size());

        std::transform(newX.begin(), newX.end(), newXSquared.begin(), [](const long double& x_value)
            -> long double { return std::pow(x_value, 2); });

        long double slope_numerator { std::inner_product(newX.begin(), newX.end(), newY.begin(), 0.0) };
        long double slope_denominator { std::accumulate(newXSquared.begin(), newXSquared.end(), 0.0) };

        fitParameters["slope"] = slope_numerator / slope_denominator;
        fitParameters["intercept"] = calculateAverage(y) - (fitParameters["slope"] * calculateAverage(x));

        return fitParameters;
    }
}
