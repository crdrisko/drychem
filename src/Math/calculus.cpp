// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: calculus.cpp - Version 1.0.0
// Author: cdrisko
// Date: 01/31/2020-15:22:23
// Description: Common mathematical function definitions relating to calculus

#include "../../include/internal/Math/calculus.hpp"
#include "../../include/internal/Errors/errorUtilities.hpp"

using std::vector;
using std::string_view;

namespace Utilities_API::Math
{
    vector<long double> finiteDifferenceMethod(const vector<long double>& x, const vector<long double>& y,
        string_view method)
    {
        vector<long double> dy_dx;

        if (x.size() != y.size())
            Utilities_API::Errors::printFatalErrorMessage (1,
                "The vectors x and y must have the same number of elements.");

        if (method == "Forward")
            for (size_t i {}; i < y.size() - 1; ++i)
                dy_dx.push_back((y[i + 1] - y[i]) / (x[i + 1] - x[i]));

        else if (method == "Backward")
            for (size_t i {1}; i < y.size(); ++i)
                dy_dx.push_back((y[i] - y[i - 1]) / (x[i] - x[i - 1]));

        else
        {
            if (method != "Centered")
                Utilities_API::Errors::printNonFatalErrorMessage("Centered finite difference method used");

            for (size_t i {}; i < y.size(); ++i)
            {
                if (i == 0)
                {
                    vector<long double> firstX { x[0], x[1] };
                    vector<long double> firstY { y[0], y[1] };

                    dy_dx.push_back(finiteDifferenceMethod(firstX, firstY, "Forward")[0]);
                }
                else if (i == y.size() - 1)
                {
                    vector<long double> lastX { x[y.size() - 2], x[y.size() - 1] };
                    vector<long double> lastY { y[y.size() - 2], y[y.size() - 1] };

                    dy_dx.push_back(finiteDifferenceMethod(lastX, lastY, "Backward")[0]);
                }
                else
                {
                    dy_dx.push_back(((y[i + 1] - y[i]) / (x[i + 1] - x[i])
                        + (y[i] - y[i - 1]) / (x[i] - x[i - 1])) / 2);
                }
            }
        }

        return dy_dx;
    }


    vector<long double> cumulativeTrapz(const vector<long double>& x, const vector<long double>& y,
        const size_t& referenceIndex)
    {
        vector<long double> y_cumulative;

        if (x.size() != y.size())
            Utilities_API::Errors::printFatalErrorMessage (1, 
                "The vectors x and y must have the same number of elements.");
        else
            for (size_t i {}; i < y.size() - 1; ++i)
            {
                if (i == referenceIndex)
                    y_cumulative.push_back(0);
                y_cumulative.push_back( y_cumulative[i] + trapz(x[i], x[i+1], y[i], y[i+1]) );
            }

        return y_cumulative;
    }
}
