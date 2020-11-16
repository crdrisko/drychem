// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: testingDetails.hpp
// Author: crdrisko
// Date: 11/15/2020-11:11:33
// Description: Details to be used with the testing of the testing portion of the utilities library

#ifndef DRYCHEM_COMMON_UTILITIES_LIBS_UTILITIES_TESTS_DETAILS_TESTINGDETAILS_HPP
#define DRYCHEM_COMMON_UTILITIES_LIBS_UTILITIES_TESTS_DETAILS_TESTINGDETAILS_HPP

#include <cstddef>

namespace CppUtils::Testing::details::testing
{
    struct SumSquares
    {
        std::size_t operator()(std::size_t iter) const
        {
            std::size_t result {};

            for (std::size_t i {}; i < iter; ++i)
                result += i * i;

            return result;
        }
    };

    class MyClass
    {
    private:
        std::size_t iter {};

    public:
        explicit MyClass(std::size_t Iter) : iter {Iter} {}

        std::size_t sumSquares() const
        {
            std::size_t result {};

            for (std::size_t i {}; i < iter; ++i)
                result += i * i;

            return result;
        }
    };

    std::size_t sumSquares(std::size_t iter)
    {
        std::size_t result {};

        for (std::size_t i {}; i < iter; ++i)
            result += i * i;

        return result;
    }

    void voidSumSquares(std::size_t iter)
    {
        std::size_t result {};

        for (std::size_t i {}; i < iter; ++i)
            result += i * i;
    }
}   // namespace CppUtils::Testing::details::testing

#endif
