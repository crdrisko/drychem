// Copyright (c) 2020-2021 Cody R. Drisko. All rights reserved.
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
        unsigned long long operator()(unsigned long long iter) const
        {
            unsigned long long result {};

            for (unsigned long long i {}; i < iter; ++i)
                result += i * i;

            return result;
        }
    };

    class MyClass
    {
    private:
        unsigned long long iter {};

    public:
        explicit MyClass(unsigned long long Iter) : iter {Iter} {}

        unsigned long long sumSquares() const
        {
            unsigned long long result {};

            for (unsigned long long i {}; i < iter; ++i)
                result += i * i;

            return result;
        }
    };

    unsigned long long sumSquares(unsigned long long iter)
    {
        unsigned long long result {};

        for (unsigned long long i {}; i < iter; ++i)
            result += i * i;

        return result;
    }

    void voidSumSquares(unsigned long long iter)
    {
        unsigned long long result {};

        for (unsigned long long i {}; i < iter; ++i)
            result += i * i;

        std::cout << result << '\n';
    }
}   // namespace CppUtils::Testing::details::testing

#endif
