// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: testVector3DFunctions.hpp
// Author: crdrisko
// Date: 04/09/2020-21:56:59
// Description: Provides ~100% unit test coverage over all Vector3D functions

#ifndef COMMON_UTILITIES_TESTING_TESTVECTOR3DFUNCTIONS_HPP
#define COMMON_UTILITIES_TESTING_TESTVECTOR3DFUNCTIONS_HPP

#include <algorithm>
#include <array>
#include <cstddef>
#include <exception>
#include <iostream>
#include <string>
#include <utility>

#include <gtest/gtest.h>

#include "errors.hpp"
#include "math.hpp"

using namespace CppUtils::Math;

GTEST_TEST(testContainerFunctions, typeWithNoDefaultConstructorGivesACompileTimeError)
{
    struct NoDefaultConstructor
    {
        // NoDefaultConstructor() = delete;                 // Uncomment for a compile-time error
    };

    Vector3D<NoDefaultConstructor> test {};

    GTEST_COMPILE_ASSERT_(test.size() == 3UL, "size() of Vector 3D should alwauys be 3.");
}

// Test member types
GTEST_TEST(testContainerFunctions, memberTypesForAnExampleVector3DTypeAreCorrect)
{
    // clang-format off
    GTEST_COMPILE_ASSERT_((std::is_same_v<Vector3D<double>::value_type, double>),                    "value_type is incorrect.");
    GTEST_COMPILE_ASSERT_((std::is_same_v<Vector3D<double>::size_type, std::size_t>),                "size_type is incorrect.");
    GTEST_COMPILE_ASSERT_((std::is_same_v<Vector3D<double>::difference_type, std::ptrdiff_t>),       "difference_type is incorrect.");
    GTEST_COMPILE_ASSERT_((std::is_same_v<Vector3D<double>::reference, double&>),                    "reference is incorrect.");
    GTEST_COMPILE_ASSERT_((std::is_same_v<Vector3D<double>::const_reference, const double&>),        "const_reference is incorrect.");
    GTEST_COMPILE_ASSERT_((std::is_same_v<Vector3D<double>::pointer, double*>),                      "pointer is incorrect.");
    GTEST_COMPILE_ASSERT_((std::is_same_v<Vector3D<double>::const_pointer, const double*>),          "const_pointer is incorrect.");
    GTEST_COMPILE_ASSERT_((std::is_same_v<Vector3D<double>::iterator, double*>),                     "iterator is incorrect.");
    GTEST_COMPILE_ASSERT_((std::is_same_v<Vector3D<double>::const_iterator, const double*>),         "const_iterator is incorrect.");
    GTEST_COMPILE_ASSERT_((std::is_same_v<Vector3D<double>::container_type, std::array<double, 3>>), "const_iterator is incorrect.");
    // clang-format on
}

GTEST_TEST(testContainerFunctions, vector3DIsClassifiedLikeAStdArrayAndAContainerAdapter)
{
    ASSERT_FALSE((IsAllocatorAwareContainer<Vector3D<int>>));
    ASSERT_FALSE((IsAssociativeContainer<Vector3D<int>>));
    ASSERT_TRUE((IsContainer<Vector3D<int>>));
    ASSERT_TRUE((IsContainerAdapter<Vector3D<int>>));
    ASSERT_FALSE((IsReversibleContainer<Vector3D<int>>));
    ASSERT_TRUE((IsSequenceContainer<Vector3D<int>>));
    ASSERT_FALSE((IsUnorderedAssociativeContainer<Vector3D<int>>));
}

// Test constructors
GTEST_TEST(testContainerFunctions, differentConstructorsGiveInitializeObjectsAsExpected)
{
    std::array<int, 3> sampleArray {1, 2, 3};

    Vector3D<long double> defaultInitialized {};
    Vector3D<int> arrayInitialized {sampleArray};
    Vector3D<float> valuesInitialized {1.0f, 3.0f, 5.0f};

    for (std::size_t i {}; i < 3; ++i)
    {
        ASSERT_EQ(0.0, defaultInitialized[i]);
        ASSERT_EQ(sampleArray[i], arrayInitialized[i]);
        ASSERT_EQ(2 * sampleArray[i] - 1, valuesInitialized[i]);
    }
}

// Test comparison operators
GTEST_TEST(testContainerFunctions, overloadedComparsionOperatorsPerformElementwiseComparisons)
{
    std::array<int, 3> valueArray {1, 2, 3};

    Vector3D<int> value1 {1, 2, 3};
    Vector3D<int> value2 {};
    Vector3D<int> value3 {valueArray};
    Vector3D<int> value4 {1, 0, 3};

    ASSERT_TRUE(value1 == value3);
    ASSERT_FALSE(value1 == value2);

    ASSERT_TRUE(value2 < value1);
    ASSERT_FALSE(value1 < value2);

    ASSERT_TRUE(value3 != value2);
    ASSERT_FALSE(value3 != value1);

    ASSERT_TRUE(value1 <= value3);
    ASSERT_FALSE(value3 <= value4);

    ASSERT_TRUE(value1 > value4);
    ASSERT_FALSE(value2 > value4);

    ASSERT_TRUE(value3 >= value2);
    ASSERT_FALSE(value2 >= value4);
}

// Test element access
GTEST_TEST(testContainerFunctions, atFunctionOverloadsCanReturnAndSetTheInternalData)
{
    Vector3D<long double> coordinates {1.0, -3.0, 5.0};

    ASSERT_EQ(1.0, coordinates.at(0));
    ASSERT_EQ(-3.0, coordinates.at(1));
    ASSERT_EQ(5.0, coordinates.at(2));

    coordinates.at(0) += 4.0;
    coordinates.at(1) += 4.0;
    coordinates.at(2) += 4.0;

    ASSERT_EQ(5.0, coordinates.at(0));
    ASSERT_EQ(1.0, coordinates.at(1));
    ASSERT_EQ(9.0, coordinates.at(2));

    ASSERT_EQ(coordinates.x(), coordinates.at(0));
    ASSERT_EQ(coordinates.y(), coordinates.at(1));
    ASSERT_EQ(coordinates.z(), coordinates.at(2));
}

GTEST_TEST(testContainerFunctions, subscriptOperatorsCanReturnAndSetTheInternalData)
{
    Vector3D<long double> coordinates {1.0, -3.0, 5.0};

    ASSERT_EQ(1.0, coordinates[0]);
    ASSERT_EQ(-3.0, coordinates[1]);
    ASSERT_EQ(5.0, coordinates[2]);

    coordinates[0] += 4.0;
    coordinates[1] += 4.0;
    coordinates[2] += 4.0;

    ASSERT_EQ(5.0, coordinates[0]);
    ASSERT_EQ(1.0, coordinates[1]);
    ASSERT_EQ(9.0, coordinates[2]);

    ASSERT_EQ(coordinates.at(0), coordinates[0]);
    ASSERT_EQ(coordinates.at(1), coordinates[1]);
    ASSERT_EQ(coordinates.at(2), coordinates[2]);
}

GTEST_TEST(testContainerFunctions, xyzFunctionOverloadsCanReturnAndSetTheInternalData)
{
    Vector3D<long double> coordinates {1.0, -3.0, 5.0};

    ASSERT_EQ(1.0, coordinates.x());
    ASSERT_EQ(-3.0, coordinates.y());
    ASSERT_EQ(5.0, coordinates.z());

    coordinates.x() += 4.0;
    coordinates.y() += 4.0;
    coordinates.z() += 4.0;

    ASSERT_EQ(5.0, coordinates.x());
    ASSERT_EQ(1.0, coordinates.y());
    ASSERT_EQ(9.0, coordinates.z());

    ASSERT_EQ(coordinates[0], coordinates.x());
    ASSERT_EQ(coordinates[1], coordinates.y());
    ASSERT_EQ(coordinates[2], coordinates.z());
}

GTEST_TEST(testContainerFunctions, atFunctionOverloadsWillThrowWhenIndexIsOutOfRange)
{
    Vector3D<long double> sampleVector {};

    ASSERT_DEATH(
        {
            try
            {
                try
                {
                    std::cout << sampleVector.at(3) << std::endl;
                }
                catch (const std::exception& except)
                {
                    CppUtils::Errors::ErrorMessage error;
                    error.programName = "Common-Utilities";
                    error.message     = "Exception message: " + std::string {except.what()};

                    throw CppUtils::Errors::FatalException(error);
                }
            }
            catch (const CppUtils::Errors::FatalException& except)
            {
                except.handleErrorWithMessage();
            }
        },
        "Common-Utilities Fatal Error:\n\tException message: array::at");

    ASSERT_DEATH(
        {
            try
            {
                try
                {
                    sampleVector.at(3) = 2.0;
                }
                catch (const std::exception& except)
                {
                    CppUtils::Errors::ErrorMessage error;
                    error.programName = "Common-Utilities";
                    error.message     = "Exception message: " + std::string {except.what()};

                    throw CppUtils::Errors::FatalException(error);
                }
            }
            catch (const CppUtils::Errors::FatalException& except)
            {
                except.handleErrorWithMessage();
            }
        },
        "Common-Utilities Fatal Error:\n\tException message: array::at");
}

// Test iterators
GTEST_TEST(testContainerFunctions, aVector3DCanBeUsedInStdAlgorithms)
{
    Vector3D<long double> vec {2.0l, 3.5l, 0.1l};

    ASSERT_FALSE(std::is_sorted(vec.cbegin(), vec.cend()));

    std::sort(vec.begin(), vec.end());

    ASSERT_TRUE(std::is_sorted(vec.begin(), vec.end()));
}

GTEST_TEST(testContainerFunctions, aVector3DCanBeUsedInRangeBasedForLoops)
{
    testing::internal::CaptureStdout();

    for (const auto& elem : Vector3D<long double> {2.2l, 3.3l, 1.1l})
        std::cout << elem << ' ';
    std::cout << std::endl;

    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, "2.2 3.3 1.1 \n");
}

// Test capacity
GTEST_TEST(testContainerFunctions, aVector3DIsNeverEmpty)
{
    Vector3D<long> vec;

    ASSERT_TRUE(!vec.empty());
    ASSERT_FALSE(vec.empty());
}

GTEST_TEST(testContainerFunctions, theSizeOfAVector3DIsAlways3)
{
    Vector3D<long> vec;

    ASSERT_EQ(vec.size(), 3UL);
}

GTEST_TEST(testContainerFunctions, theMaxSizeOfAVector3DIsAlways3)
{
    Vector3D<long> vec;

    ASSERT_EQ(vec.max_size(), 3UL);
}

// Test operations
GTEST_TEST(testContainerFunctions, theFillMemberFunctionSetsAllElementsToTheSameValue)
{
    Vector3D<long double> vec {1.0l, 2.0l, 3.0l};

    long double counter {};

    for (const auto& elem : vec)
        ASSERT_EQ(++counter, elem);

    vec.fill(3.14l);

    for (const auto& elem : vec)
        ASSERT_EQ(3.14l, elem);
}

GTEST_TEST(testContainerFunctions, theSwapMemberFunctionSwapsAllElementsOfTwoVector3Ds)
{
    Vector3D<long double> vec1 {1.0l, 2.0l, 3.0l};
    Vector3D<long double> vec2 {6.0l, 4.0l, 2.0l};

    Vector3D<long double> copyVec1 {vec1};
    Vector3D<long double> copyVec2 {vec2};

    vec1.swap(vec2);

    for (std::size_t i {}; i < vec1.size(); ++i)
    {
        ASSERT_EQ(vec1[i], copyVec2[i]);
        ASSERT_EQ(vec2[i], copyVec1[i]);
    }
}

// Test the tuple-like API with structured bindings
GTEST_TEST(testContainerFunctions, ourTupleLikeAPIProvidesReadAccessToTheElementsViaStructuredBindings)
{
    Vector3D<long double> vec {0.0l, 1.2l, 3.14l};
    auto [x, y, z] = vec;

    ASSERT_EQ(x, vec[0]);
    ASSERT_EQ(y, vec[1]);
    ASSERT_EQ(z, vec[2]);
}

GTEST_TEST(testContainerFunctions, ourTupleLikeAPIProvidesReadAndWriteAccessToTheElementsViaStructuredBindings)
{
    Vector3D<long double> vec {0.0l, 1.2l, 3.14l};

    auto&& [x, y, z] = vec;

    long double value {std::move(z)};

    ASSERT_EQ(value, 3.14l);

    z = 4.2l;
    y += 3.8l;

    ASSERT_EQ(x, 0.0l);
    ASSERT_EQ(y, 5.0l);
    ASSERT_EQ(z, 4.2l);
}

#endif
