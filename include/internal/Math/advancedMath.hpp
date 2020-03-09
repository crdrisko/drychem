// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: advancedMath.hpp - Version 1.0.0
// Author: cdrisko
// Date: 03/09/2020-08:03:25
// Description: An abstract interface for advanced mathematical function calls

#ifndef UTILITIES_API_ADVANCEDMATH_HPP
#define UTILITIES_API_ADVANCEDMATH_HPP

#include <memory>
#include <vector>

#include "../Errors/errorUtilities.hpp"

namespace Utilities_API::Math
{
    class AdvancedMath
    {
    protected:
        std::vector<long double> x;
        std::vector<long double> y;

        Errors::ErrorMessagePtr errorMessage { std::make_shared<Errors::FatalErrorMessage>("Utilities-API", 1) };

        AdvancedMath(const std::vector<long double>& X, const std::vector<long double>& Y) : x{X}, y{Y}
        {
            if ( x.size() != y.size() )
                errorMessage->printErrorMessage("The vectors x and y must have the same number of elements.");
        }

    public:
        virtual ~AdvancedMath() = default;
        virtual std::vector<long double> doCalculation() const = 0;
    };

    using AdvancedMathPtr = std::shared_ptr<AdvancedMath>;
}

#endif
