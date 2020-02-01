// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: testAssertions.hpp - Version 1.0.0
// Author: cdrisko
// Date: 01/31/2020-16:05:34
// Description: Defines an assertion class to be used when testing unit conversions with GoogleTest

#ifndef TESTASSERTIONS_HPP
#define TESTASSERTIONS_HPP

#include <string_view>
#include <gtest/gtest.h>
#include "../../src/include/internal/Math/mathUtilities.hpp"

class ConversionAssert
{
private:
    std::string initialUnits;
    std::string finalUnits;

    long double doConversion() const;

public:
    ConversionAssert() = delete;
    ConversionAssert(std::string_view InitialUnits, std::string_view FinalUnits)
        : initialUnits{InitialUnits}, finalUnits{FinalUnits} {}

    void isConvertedTo(const long double& expectedValue) const
    {
        ASSERT_DOUBLE_EQ(expectedValue, doConversion());
    }

    void isConvertedToAValueNear(const long double& expectedValue, const int& significantFigures) const
    {
        ASSERT_NEAR( expectedValue, doConversion(), Utilities_API::Math::findAbsoluteError(expectedValue,
            significantFigures) );
    }
};

ConversionAssert assertThat(std::string_view InitialUnits, std::string_view FinalUnits)
{
    ConversionAssert assert {InitialUnits, FinalUnits};
    return assert;
}

#endif
