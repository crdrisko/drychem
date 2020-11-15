// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: mathExceptions.hpp
// Author: crdrisko
// Date: 10/26/2020-12:50:56
// Description: Exception classes specifically made for errors that could arrise in math-related functions

#ifndef DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_MATH_UTILS_MATHEXCEPTIONS_HPP
#define DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_MATH_UTILS_MATHEXCEPTIONS_HPP

#include <cstddef>
#include <string>

#include "common-utils/errors/exceptions/fatalException.hpp"
#include "common-utils/errors/utils/errorTypes.hpp"

namespace CppUtils::Math
{
    /*!
     * An exception class used specifically for the math libraries when two (or more) input
     *  containers have different sizes.
     */
    class InputSizeMismatch : public Errors::FatalException
    {
    public:
        explicit InputSizeMismatch(const std::string& programName, const std::string& fileName, std::size_t lineNumber)
            : Errors::FatalException {Errors::ErrorMessage {programName, "Input sizes for x and y containers must be the same.",
                fileName, lineNumber}}
        {
        }
    };
}   // namespace CppUtils::Math

#endif
