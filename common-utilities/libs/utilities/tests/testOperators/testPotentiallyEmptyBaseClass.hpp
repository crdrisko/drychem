// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: testPotentiallyEmptyBaseClass.hpp
// Author: crdrisko
// Date: 09/18/2020-09:02:30
// Description: Provides ~100% unit test coverage over the potentially empty base class utility

#ifndef COMMON_UTILITIES_TESTING_TESTPOTENTIALLYEMPTYBASECLASS_HPP
#define COMMON_UTILITIES_TESTING_TESTPOTENTIALLYEMPTYBASECLASS_HPP

#include <gtest/gtest.h>

#include "utilities.hpp"

// Helper classes for testing
namespace CppUtils::Operators
{
    // The EBCO and CRTP used together for an empty class
    class EmptyDerived : public PotentiallyEmptyBaseClass<EmptyDerived>
    {
    };
}   // namespace CppUtils::Operators

using namespace CppUtils::Operators;

GTEST_TEST(testPotentiallyEmptyBaseClass, anEmptyBaseClassHasANonZeroSize)
{
    ASSERT_TRUE(sizeof(PotentiallyEmptyBaseClass<bool>) > 0);
}

GTEST_TEST(testPotentiallyEmptyBaseClass, ebcoCouldBeUsedToMinimizeTheSizeOfADerivedEmptyClass)
{
    ASSERT_TRUE(sizeof(PotentiallyEmptyBaseClass<EmptyDerived>) <= sizeof(EmptyDerived));

    // The two should be equal if the compiler implements the EBCO, uncomment the following to find out for your compiler:
    // ASSERT_TRUE(sizeof(PotentiallyEmptyBaseClass<EmptyDerived>) <= sizeof(EmptyDerived));
}

#endif
