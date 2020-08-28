// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: testContainerFunctions.hpp - Version 1.0.0
// Author: crdrisko
// Date: 04/09/2020-21:56:59
// Description: Provides ~100% unit test coverage over all container utility functions

#ifndef TESTCONTAINERFUNCTIONS_HPP
#define TESTCONTAINERFUNCTIONS_HPP

#include <array>

#include <gtest/gtest.h>

#include "../../../include/common-utils/math/containers.hpp"

using namespace CommonUtilities::Math::Containers;

GTEST_TEST(testContainerFunctions, differentConstructorsGiveInitializeObjectsAsExpected)
{
    Vector3D<long double> defaultInitialized {};

    for (std::size_t i {}; i < 3; ++i)
        ASSERT_EQ(0.0, defaultInitialized[i]);


    std::array<int, 3> sampleArray {1, 2, 3};
    Vector3D<int> arrayInitialized {sampleArray};

    for (std::size_t i {}; i < 3; ++i)
        ASSERT_EQ(sampleArray[i], arrayInitialized[i]);


    Vector3D<float> valuesInitialized {1.0, 3.0, 5.0};

    for (std::size_t i {}; i < 3; ++i)
        ASSERT_EQ(2 * sampleArray[i] - 1, valuesInitialized[i]);
}

GTEST_TEST(testContainerFunctions, subscriptOperatorsCanReturnAndSetTheInternalData)
{
    Vector3D<long double> coordinates {1.0, -3.0, 5.0};

    ASSERT_EQ(  1.0, coordinates[0] );
    ASSERT_EQ( -3.0, coordinates[1] );
    ASSERT_EQ(  5.0, coordinates[2] );

    coordinates[0] += 4.0;
    coordinates[1] += 4.0;
    coordinates[2] += 4.0;

    ASSERT_EQ( 5.0, coordinates[0] );
    ASSERT_EQ( 1.0, coordinates[1] );
    ASSERT_EQ( 9.0, coordinates[2] );
}

GTEST_TEST(testContainerFunctions, subscriptOperatorsThrowWhenIndexIsOutOfRange)
{
    Vector3D<long double> sampleVector {};

    ASSERT_DEATH(
    {
        try
        {
            std::cout << sampleVector[3];
        }
        catch(const CommonUtilities::Errors::FatalException& except)
        {
            except.handleErrorWithMessage();
        }
    }, "Common-Utilities Fatal Error:\n\tVector3D index must be within 0 and 2.\n");


    ASSERT_DEATH(
    {
        try
        {
            sampleVector[3] = 2.0;
        }
        catch(const CommonUtilities::Errors::FatalException& except)
        {
            except.handleErrorWithMessage();
        }
    }, "Common-Utilities Fatal Error:\n\tVector3D index must be within 0 and 2.\n");
}

GTEST_TEST(testContainerFunctions, xyzOperatorsCanReturnAndSetTheInternalData)
{
    Vector3D<long double> coordinates {1.0, -3.0, 5.0};

    ASSERT_EQ(  1.0, coordinates.x() );
    ASSERT_EQ( -3.0, coordinates.y() );
    ASSERT_EQ(  5.0, coordinates.z() );

    coordinates.x() += 4.0;
    coordinates.y() += 4.0;
    coordinates.z() += 4.0;

    ASSERT_EQ( 5.0, coordinates.x() );
    ASSERT_EQ( 1.0, coordinates.y() );
    ASSERT_EQ( 9.0, coordinates.z() );

    ASSERT_EQ( coordinates[0], coordinates.x() );
    ASSERT_EQ( coordinates[1], coordinates.y() );
    ASSERT_EQ( coordinates[2], coordinates.z() );
}

#endif
