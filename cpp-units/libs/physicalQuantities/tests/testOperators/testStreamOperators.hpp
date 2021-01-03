// Copyright (c) 2020-2021 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: testStreamOperators.hpp
// Author: crdrisko
// Date: 09/17/2020-09:50:41
// Description: Provides ~100% unit test coverage over the overloaded stream functions

#ifndef DRYCHEM_CPP_UNITS_LIBS_PHYSICALQUANTITIES_TESTS_TESTOPERATORS_TESTSTREAMOPERATORS_HPP
#define DRYCHEM_CPP_UNITS_LIBS_PHYSICALQUANTITIES_TESTS_TESTOPERATORS_TESTSTREAMOPERATORS_HPP

#include <iostream>
#include <string>

#include <gtest/gtest.h>

#include "cpp-units/physicalQuantities.hpp"

using namespace CppUnits;
using namespace CppUnits::Literals;

GTEST_TEST(testStreamOperators, overloadedStreamOperatorPrintsMagnitudeToStandardOut)
{
    testing::internal::CaptureStdout();

    Length length = 5.0_m;
    Time time     = 2.5_s;
    Velocity vel  = length / time;

    std::cout << length << " m / " << time << " s = " << vel << " m/s" << std::endl;

    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, "5 m / 2.5 s = 2 m/s\n");
}

#endif
