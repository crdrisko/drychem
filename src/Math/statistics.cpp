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
    std::map<std::string, long double> linearLeastSquaresFitting(const vector<long double>& x,
        const vector<long double>& y)
    {
        if (x.size() != y.size())
            Utilities_API::Errors::printFatalErrorMessage (1,
                "The vectors x and y must have the same number of elements.");
        
        std::map<std::string, long double> fitParameters;

        long double x_average { calculateAverage(x) };
        long double y_average { calculateAverage(y) };

        vector<long double> numerator(x.size());
        vector<long double> denominator(x.size());

        auto y_iter = y.begin();

        std::transform(x.begin(), x.end(), numerator.begin(), 
            [&](long double x_value) { return (x_value - x_average) * (*y_iter++ - y_average); });

        std::transform(x.begin(), x.end(), denominator.begin(), 
            [&](long double x_value) { return std::pow(x_value - x_average, 2); });

        long double slope_numerator = std::accumulate(numerator.begin(), numerator.end(), 0.0);
        long double slope_denominator = std::accumulate(denominator.begin(), denominator.end(), 0.0);

        fitParameters["slope"] = slope_numerator / slope_denominator;
        fitParameters["intercept"] = calculateAverage(y) - (fitParameters["slope"] * calculateAverage(x));


        vector<long double> y_predictionCorrected(y.size());
        auto x_iter = x.begin();

        std::transform(y.begin(), y.end(), y_predictionCorrected.begin(), 
            [&](const long double& y_value) { return std::pow(y_value - (fitParameters["slope"] * *x_iter++
                + fitParameters["intercept"]), 2); });

        long double stdDevSlope_numerator = std::accumulate(y_predictionCorrected.begin(), 
            y_predictionCorrected.end(), 0.0);

        fitParameters["stdDev(slope)"] = std::sqrt(stdDevSlope_numerator / slope_denominator / (x.size() - 2));

        return fitParameters;
    }
}
