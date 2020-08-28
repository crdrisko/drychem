// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: advancedMath.hpp - Version 1.0.0
// Author: cdrisko
// Date: 03/09/2020-08:03:25
// Description: An abstract interface for advanced mathematical function calls

#ifndef COMMON_UTILITIES_ADVANCEDMATH_HPP
#define COMMON_UTILITIES_ADVANCEDMATH_HPP

#include <memory>
#include <vector>

#include "../errors.hpp"

namespace CommonUtilities::Math
{
    class AdvancedMath
    {
    protected:
        std::vector<long double> x;
        std::vector<long double> y;

        AdvancedMath(const std::vector<long double>& X, const std::vector<long double>& Y) : x{X}, y{Y}
        {
            try
            {
                if ( x.size() != y.size() )
                    throw Errors::InvalidInputException("Common-Utilities",
                        "The size of the x and y vectors must be equal.");
            }
            catch (const Errors::FatalException& except)
            {
                except.handleErrorWithMessage();
            }
        }

    public:
        virtual ~AdvancedMath() = default;
        virtual std::vector<long double> doCalculation() const = 0;
    };

    using AdvancedMathPtr = std::shared_ptr<AdvancedMath>;
}

#endif
