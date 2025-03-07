// Copyright (c) 2020-2025 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: testVector3DFunctions.hpp
// Author: crdrisko
// Date: 04/09/2020-21:56:59
// Description: Provides ~100% unit test coverage over all Vector3D functions

#ifndef DRYCHEM_COMMON_UTILITIES_LIBS_MATH_TESTS_TESTCONTAINERS_TESTVECTOR3DFUNCTIONS_HPP
#define DRYCHEM_COMMON_UTILITIES_LIBS_MATH_TESTS_TESTCONTAINERS_TESTVECTOR3DFUNCTIONS_HPP

#include <algorithm>
#include <array>
#include <cstddef>
#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>
#include <utility>

#include <common-utils/errors.hpp>
#include <common-utils/math.hpp>
#include <common-utils/meta.hpp>
#include <gtest/gtest.h>

GTEST_TEST(testVector3DFunctions, typeWithNoDefaultConstructorGivesACompileTimeError)
{
    struct NoDefaultConstructor
    {
        // NoDefaultConstructor() = delete;                 // Uncomment for a compile-time error
    };

    DryChem::Vector3D<NoDefaultConstructor> test {};

    static_assert(test.size() == 3UL, "size() of Vector 3D should always be 3.");
}

GTEST_TEST(testVector3DFunctions, memberTypesForAnExampleVector3DTypeAreCorrect)
{
    // clang-format off
    static_assert((std::is_same_v<DryChem::Vector3D<double>::value_type, double>),                                      "value_type is incorrect.");
    static_assert((std::is_same_v<DryChem::Vector3D<double>::size_type, std::size_t>),                                  "size_type is incorrect.");
    static_assert((std::is_same_v<DryChem::Vector3D<double>::difference_type, std::ptrdiff_t>),                         "difference_type is incorrect.");
    static_assert((std::is_same_v<DryChem::Vector3D<double>::reference, double&>),                                      "reference is incorrect.");
    static_assert((std::is_same_v<DryChem::Vector3D<double>::const_reference, const double&>),                          "const_reference is incorrect.");
    static_assert((std::is_same_v<DryChem::Vector3D<double>::pointer, double*>),                                        "pointer is incorrect.");
    static_assert((std::is_same_v<DryChem::Vector3D<double>::const_pointer, const double*>),                            "const_pointer is incorrect.");
    static_assert((std::is_same_v<DryChem::Vector3D<double>::iterator, std::array<double, 3>::iterator>),               "iterator is incorrect.");
    static_assert((std::is_same_v<DryChem::Vector3D<double>::const_iterator, std::array<double, 3>::const_iterator>),   "const_iterator is incorrect.");
    static_assert((std::is_same_v<DryChem::Vector3D<double>::container_type, std::array<double, 3>>),                   "const_iterator is incorrect.");
    // clang-format on
}

GTEST_TEST(testVector3DFunctions, vector3DIsClassifiedLikeAStdArrayAndAContainerAdapter)
{
    ASSERT_FALSE((DryChem::is_allocator_aware_container_v<DryChem::Vector3D<int>>));
    ASSERT_FALSE((DryChem::is_associative_container_v<DryChem::Vector3D<int>>));
    ASSERT_TRUE((DryChem::is_container_v<DryChem::Vector3D<int>>));
    ASSERT_TRUE((DryChem::is_container_adapter_v<DryChem::Vector3D<int>>));
    ASSERT_FALSE((DryChem::is_reversible_container_v<DryChem::Vector3D<int>>));
    ASSERT_TRUE((DryChem::is_sequence_container_v<DryChem::Vector3D<int>>));
    ASSERT_FALSE((DryChem::is_unordered_associative_container_v<DryChem::Vector3D<int>>));
}

GTEST_TEST(testVector3DFunctions, differentConstructorsInitializeObjectsAsExpected)
{
    std::array<int, 3> sampleArray {1, 2, 3};

    DryChem::Vector3D<long double> defaultInitialized {};
    DryChem::Vector3D<int> arrayInitialized {sampleArray};
    DryChem::Vector3D<float> valuesInitialized {1.0f, 3.0f, 5.0f};

    for (std::size_t i {}; i < 3; ++i)
    {
        ASSERT_EQ(0.0, defaultInitialized[i]);
        ASSERT_EQ(sampleArray[i], arrayInitialized[i]);
        ASSERT_EQ(2 * sampleArray[i] - 1, valuesInitialized[i]);
    }
}

GTEST_TEST(testVector3DFunctions, overloadedComparsionOperatorsPerformElementwiseComparisons)
{
    std::array<int, 3> valueArray {1, 2, 3};

    DryChem::Vector3D<int> value1 {1, 2, 3};
    DryChem::Vector3D<int> value2 {};
    DryChem::Vector3D<int> value3 {valueArray};
    DryChem::Vector3D<int> value4 {1, 0, 3};

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

GTEST_TEST(testVector3DFunctions, atFunctionOverloadsCanReturnAndSetTheInternalData)
{
    DryChem::Vector3D<long double> coordinates {1.0, -3.0, 5.0};

    ASSERT_EQ(1.0, coordinates.at(0));
    ASSERT_EQ(-3.0, coordinates.at(1));
    ASSERT_EQ(5.0, coordinates.at(2));

    coordinates.at(0) += 4.0;
    coordinates.at(1) += 4.0;
    coordinates.at(2) += 4.0;

    ASSERT_EQ(5.0, coordinates.at(0));
    ASSERT_EQ(1.0, coordinates.at(1));
    ASSERT_EQ(9.0, coordinates.at(2));
}

GTEST_TEST(testVector3DFunctions, subscriptOperatorsCanReturnAndSetTheInternalData)
{
    DryChem::Vector3D<long double> coordinates {1.0, -3.0, 5.0};

    ASSERT_EQ(1.0, coordinates[0]);
    ASSERT_EQ(-3.0, coordinates[1]);
    ASSERT_EQ(5.0, coordinates[2]);

    coordinates[0] += 4.0;
    coordinates[1] += 4.0;
    coordinates[2] += 4.0;

    ASSERT_EQ(5.0, coordinates[0]);
    ASSERT_EQ(1.0, coordinates[1]);
    ASSERT_EQ(9.0, coordinates[2]);
}

GTEST_TEST(testVector3DFunctions, atFunctionOverloadsWillThrowWhenIndexIsOutOfRange)
{
    std::stringstream deathRegex;

    deathRegex << "Common-Utilities Fatal Error:\n    Exception message: ";

#if GTEST_USES_POSIX_RE
    deathRegex << "array::at";
#elif GTEST_USES_SIMPLE_RE
    try
    {
        std::cout << std::array<int, 3>().at(3) << std::endl;
    }
    catch (const std::out_of_range& except)
    {
        deathRegex << except.what();
    }
#endif

    ASSERT_DEATH(
        {
            try
            {
                try
                {
                    DryChem::Vector3D<int>().at(3);
                }
                catch (const std::exception& except)
                {
                    DryChem::ErrorMessage error;
                    error.programName = "Common-Utilities";
                    error.message     = "Exception message: " + std::string {except.what()};

                    throw DryChem::FatalException(error);
                }
            }
            catch (const DryChem::FatalException& except)
            {
                except.handleErrorWithMessage();
            }
        },
        deathRegex.str());

    ASSERT_DEATH(
        {
            try
            {
                try
                {
                    DryChem::Vector3D<int>().at(3) = 2;
                }
                catch (const std::exception& except)
                {
                    DryChem::ErrorMessage error;
                    error.programName = "Common-Utilities";
                    error.message     = "Exception message: " + std::string {except.what()};

                    throw DryChem::FatalException(error);
                }
            }
            catch (const DryChem::FatalException& except)
            {
                except.handleErrorWithMessage();
            }
        },
        deathRegex.str());
}

GTEST_TEST(testVector3DFunctions, aVector3DCanBeUsedInStdAlgorithms)
{
    DryChem::Vector3D<long double> vec {2.0l, 3.5l, 0.1l};

    ASSERT_FALSE(std::is_sorted(vec.cbegin(), vec.cend()));

    std::sort(vec.begin(), vec.end());

    ASSERT_TRUE(std::is_sorted(vec.begin(), vec.end()));
}

GTEST_TEST(testVector3DFunctions, aVector3DCanBeUsedInRangeBasedForLoops)
{
    testing::internal::CaptureStdout();

    for (const auto& elem : DryChem::Vector3D<long double> {2.2l, 3.3l, 1.1l})
        std::cout << elem << ' ';
    std::cout << std::endl;

    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, "2.2 3.3 1.1 \n");
}

GTEST_TEST(testVector3DFunctions, aVector3DIsNeverEmpty)
{
    DryChem::Vector3D<long> vec;

    ASSERT_TRUE(!vec.empty());
    ASSERT_FALSE(vec.empty());
}

GTEST_TEST(testVector3DFunctions, theSizeOfAVector3DIsAlways3)
{
    DryChem::Vector3D<long> vec;

    ASSERT_EQ(vec.size(), 3UL);
}

GTEST_TEST(testVector3DFunctions, theMaxSizeOfAVector3DIsAlways3)
{
    DryChem::Vector3D<long> vec;

    ASSERT_EQ(vec.max_size(), 3UL);
}

GTEST_TEST(testVector3DFunctions, theFillMemberFunctionSetsAllElementsToTheSameValue)
{
    DryChem::Vector3D<long double> vec {1.0l, 2.0l, 3.0l};

    long double counter {};

    for (const auto& elem : vec)
        ASSERT_EQ(++counter, elem);

    vec.fill(3.14l);

    for (const auto& elem : vec)
        ASSERT_EQ(3.14l, elem);
}

GTEST_TEST(testVector3DFunctions, theSwapMemberFunctionSwapsAllElementsOfTwoVector3Ds)
{
    DryChem::Vector3D<long double> vec1 {1.0l, 2.0l, 3.0l};
    DryChem::Vector3D<long double> vec2 {6.0l, 4.0l, 2.0l};

    DryChem::Vector3D<long double> copyVec1 {vec1};
    DryChem::Vector3D<long double> copyVec2 {vec2};

    vec1.swap(vec2);

    for (std::size_t i {}; i < vec1.size(); ++i)
    {
        ASSERT_EQ(vec1[i], copyVec2[i]);
        ASSERT_EQ(vec2[i], copyVec1[i]);
    }
}

GTEST_TEST(testVector3DFunctions, ourTupleLikeAPIProvidesReadAccessToTheElementsViaStructuredBindings)
{
    DryChem::Vector3D<long double> vec {0.0l, 1.2l, 3.14l};
    auto [x, y, z] = vec;

    ASSERT_EQ(x, vec[0]);
    ASSERT_EQ(y, vec[1]);
    ASSERT_EQ(z, vec[2]);
}

GTEST_TEST(testVector3DFunctions, ourTupleLikeAPIProvidesReadAndWriteAccessToTheElementsViaStructuredBindings)
{
    DryChem::Vector3D<long double> vec {0.0l, 1.2l, 3.14l};

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
