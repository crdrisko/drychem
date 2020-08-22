// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: statistics.hpp - Version 1.0.0
// Author: cdrisko
// Date: 02/03/2020-08:22:29
// Description: Common mathematical function definitions and prototypes relating to statistics

#ifndef COMMON_UTILITIES_STATISTICS_HPP
#define COMMON_UTILITIES_STATISTICS_HPP

#include <algorithm>
#include <cmath>
#include <map>
#include <numeric>
#include <string>
#include <vector>

#include "advancedMath.hpp"
#include "../../errors.hpp"

namespace CommonUtilities::Math
{
    inline int findOrderOfMagnitude(const long double& value)
    {
        return std::floor(std::log10(value));
    }

    inline long double findAbsoluteError(const long double& expectedValue, const int& significantFigures)
    {
        return std::pow(10, findOrderOfMagnitude(expectedValue) - (significantFigures - 1));
    }

    template<typename T>
    inline T calculateAverage(const std::vector<T>& values)
    {
        return std::accumulate(values.begin(), values.end(), static_cast<T>(0)) / values.size();
    }

    template<typename T>
    inline T calculateStandardDeviation(const std::vector<T>& values)
    {
        T average { calculateAverage(values) };

        std::vector<T> averageCorrectedValues(values.size());

        std::transform(values.begin(), values.end(), averageCorrectedValues.begin(),
            [&](T value) { return std::pow(value - average, 2); });

        return std::sqrt( std::accumulate(averageCorrectedValues.begin(), averageCorrectedValues.end(),
            static_cast<T>(0)) / (values.size() - 1) );
    }


    class LinearLeastSquaresFitting : public AdvancedMath
    {
    private:
        static inline const int numberOfFittingParameters {3};

    public:
        LinearLeastSquaresFitting(const std::vector<long double>& X, const std::vector<long double>& Y)
            : AdvancedMath{X, Y} {}

        virtual std::vector<long double> doCalculation() const override;

        std::map<std::string, long double> mapFittingParametersToLabels(const std::vector<long double>& fittingResults) const
        {
            try
            {
                if (fittingResults.size() != numberOfFittingParameters)
                    throw Errors::InvalidInputException{"Common-Utilities",
                        "The size of input vector must be equal to " + std::to_string(numberOfFittingParameters)};
            }
            catch(const Errors::Exception& except)
            {
                except.handleErrorWithMessage();
            }

            std::map<std::string, long double> fitParameters;

            fitParameters["slope"] = fittingResults[0];
            fitParameters["intercept"] = fittingResults[1];
            fitParameters["stdDev(slope)"] = fittingResults[2];

            return fitParameters;
        }
    };


    inline std::vector<long double> LinearLeastSquaresFitting::doCalculation() const
    {
        std::vector<long double> results(numberOfFittingParameters);

        long double x_average { calculateAverage(x) };
        long double y_average { calculateAverage(y) };

        std::vector<long double> numerator(x.size());
        std::vector<long double> denominator(x.size());

        auto y_iter = y.begin();

        std::transform(x.begin(), x.end(), numerator.begin(),
            [&](long double x_value) { return (x_value - x_average) * (*y_iter++ - y_average); });

        std::transform(x.begin(), x.end(), denominator.begin(),
            [&](long double x_value) { return std::pow(x_value - x_average, 2); });

        long double slope_numerator = std::accumulate(numerator.begin(), numerator.end(), 0.0);
        long double slope_denominator = std::accumulate(denominator.begin(), denominator.end(), 0.0);

        results[0] = slope_numerator / slope_denominator;
        results[1] = y_average - (results[0] * x_average);

        std::vector<long double> y_predictionCorrected(y.size());

        auto x_iter = x.begin();

        std::transform(y.begin(), y.end(), y_predictionCorrected.begin(),
            [&](const long double& y_value) { return std::pow(y_value - (results[0] * *x_iter++
                + results[1]), 2); });

        long double stdDevSlope_numerator = std::accumulate(y_predictionCorrected.begin(),
            y_predictionCorrected.end(), 0.0);

        results[2] = std::sqrt(stdDevSlope_numerator / slope_denominator / (x.size() - 2));

        return results;
    }
}

#endif
