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

#include "advancedMath.hpp"

namespace Utilities_API::Math
{
    class CenteredDifferenceMethod : public AdvancedMath
    {
    private:
        std::vector<long double> forwardDifferenceMethod() const
        {
            std::vector<long double> dy_dx;

            for (size_t i {}; i < y.size() - 1; ++i)
                dy_dx.push_back((y[i + 1] - y[i]) / (x[i + 1] - x[i]));

            return dy_dx;
        }

        std::vector<long double> backwardsDifferenceMethod() const
        {
            std::vector<long double> dy_dx;

            for (size_t i {1}; i < y.size(); ++i)
                dy_dx.push_back((y[i] - y[i - 1]) / (x[i] - x[i - 1]));

            return dy_dx;
        }

    public:
        CenteredDifferenceMethod(const std::vector<long double>& X, const std::vector<long double>& Y)
            : AdvancedMath{X, Y} {}

        virtual std::vector<long double> doCalculation() const override
        {
            std::vector<long double> result;
            std::vector<long double> forward { forwardDifferenceMethod() };
            std::vector<long double> backward { backwardsDifferenceMethod() };

            forward.push_back(backward.back());
            backward.insert(backward.begin(), forward.front());

            for (size_t i {}; i < y.size(); ++i)
                result.push_back( (forward[i] + backward[i]) / 2 );

            return result;
        }
    };


    class CumulativeTrapzIntegration : public AdvancedMath
    {
    private:
        size_t referenceIndex;

        long double trapz(long double x1, long double x2, long double y1, long double y2) const
        {
            return ( (x2 - x1) * (y1 + y2) ) / 2;
        }

    public:
        CumulativeTrapzIntegration(const std::vector<long double>& X, const std::vector<long double>& Y,
            size_t ReferenceIndex = 0) : AdvancedMath{X, Y}, referenceIndex{ReferenceIndex} {}

        virtual std::vector<long double> doCalculation() const override
        {
            std::vector<long double> y_cumulative;

            for (size_t i {}; i < y.size() - 1; ++i)
            {
                if (i == referenceIndex)
                    y_cumulative.push_back(0);

                y_cumulative.push_back( y_cumulative[i] + trapz(x[i], x[i + 1], y[i], y[i + 1]) );
            }

            return y_cumulative;
        }
    };
}

#endif
