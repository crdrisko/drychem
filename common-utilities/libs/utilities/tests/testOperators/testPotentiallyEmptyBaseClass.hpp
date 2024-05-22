// Copyright (c) 2020-2024 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: testPotentiallyEmptyBaseClass.hpp
// Author: crdrisko
// Date: 09/18/2020-09:02:30
// Description: Provides ~100% unit test coverage over the potentially empty base class utility

#ifndef DRYCHEM_COMMON_UTILITIES_LIBS_UTILITIES_TESTS_TESTOPERATORS_TESTPOTENTIALLYEMPTYBASECLASS_HPP
#define DRYCHEM_COMMON_UTILITIES_LIBS_UTILITIES_TESTS_TESTOPERATORS_TESTPOTENTIALLYEMPTYBASECLASS_HPP

#include <common-utils/utilities.hpp>
#include <gtest/gtest.h>

#include "../details/operatorDetails.hpp"

GTEST_TEST(testPotentiallyEmptyBaseClass, anEmptyBaseClassHasANonZeroSize)
{
    ASSERT_TRUE(sizeof(DryChem::PotentiallyEmptyBaseClass<bool>) > 0);
}

GTEST_TEST(testPotentiallyEmptyBaseClass, ebcoCouldBeUsedToMinimizeTheSizeOfADerivedEmptyClass)
{
    using CppUtils::Operators::details::testing::EmptyDerived;

    ASSERT_TRUE(sizeof(DryChem::PotentiallyEmptyBaseClass<EmptyDerived>) <= sizeof(EmptyDerived));

    //! The two should be equal if the compiler implements the EBCO, uncomment the following to find out for your compiler:
    // ASSERT_TRUE(sizeof(DryChem::PotentiallyEmptyBaseClass<EmptyDerived>) == sizeof(EmptyDerived));
}

#endif
