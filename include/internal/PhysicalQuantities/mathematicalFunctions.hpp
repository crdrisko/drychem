// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: mathematicalFunctions.hpp - Version 1.0.0
// Author: crdrisko
// Date: 02/15/2020-09:37:16
// Description: Mathematical functions from the Math library adapted for PhysicalQuantities

#ifndef UTILITIES_API_MATHEMATICALFUNCTIONS_HPP
#define UTILITIES_API_MATHEMATICALFUNCTIONS_HPP

#include <algorithm>
#include <functional>
#include "physicalQuantity.hpp"
#include "../Math/statistics.hpp"
#include "../Math/calculus.hpp"

namespace Utilities_API::PhysicalQuantities::Mathematics
{
    template <typename T>
    inline auto convertQuantitiesToMagnitudes(const std::vector<T>& values)
    {
        std::vector<long double> magnitudes(values.size());

        std::transform(values.begin(), values.end(), magnitudes.begin(), [](const T& value)
            -> long double { return value.getMagnitude(); });

        return magnitudes;
    }


    template <typename TArg, typename TReturn = TArg>
    inline auto mathematicalFunction(const std::vector<TArg>& values,
        std::function<long double (const std::vector<long double>&)> unaryOperator)
    {
        return TReturn(unaryOperator(convertQuantitiesToMagnitudes(values)));
    }

    inline auto calculateAverage = [](const std::vector<long double>& values)
        -> long double { return Utilities_API::Math::calculateAverage<long double>(values); };


    template <typename TArg1, typename TArg2, typename TReturn>
    inline auto mathematicalFunction(const std::vector<TArg1>& x_values,
        const std::vector<TArg2>& y_values, std::function<TReturn
            (const std::vector<long double>&, const std::vector<long double>&)> binaryOperator)
    {
        return TReturn(binaryOperator(convertQuantitiesToMagnitudes(x_values),
            convertQuantitiesToMagnitudes(y_values)));
    }

    inline auto linearLeastSquaresFitting = [](const std::vector<long double>& x_values,
        const std::vector<long double>& y_values)
            -> auto { return Utilities_API::Math::linearLeastSquaresFitting(x_values, y_values); };


    template <typename TArg1, typename TArg2, typename TArg3, typename TReturn>
    inline auto mathematicalFunction(const std::vector<TArg1>& x_values,
        const std::vector<TArg2>& y_values, TArg3 argument, std::function<std::vector<long double>
            (const std::vector<long double>&, const std::vector<long double>&, TArg3)> ternaryOperator)
    {
        std::vector<TReturn> results(x_values.size());
        std::vector<long double> resultsMagnitudes(x_values.size());

        resultsMagnitudes = ternaryOperator(convertQuantitiesToMagnitudes(x_values),
            convertQuantitiesToMagnitudes(y_values), argument);

        std::transform(resultsMagnitudes.begin(), resultsMagnitudes.end(), results.begin(),
            [](long double resultMagnitude) -> TReturn { return TReturn(resultMagnitude); });

        return results;
    }

    inline auto finiteDifferenceMethod = [](const std::vector<long double>& x_values,
        const std::vector<long double>& y_values, std::string_view method = "Centered")
            -> auto { return Utilities_API::Math::finiteDifferenceMethod(x_values, y_values, method); };

    inline auto cumulativeTrapz = [](const std::vector<long double>& x_values,
        const std::vector<long double>& y_values, const int& referenceIndex = 0)
            -> auto { return Utilities_API::Math::cumulativeTrapz(x_values, y_values, referenceIndex); };
}

#endif
