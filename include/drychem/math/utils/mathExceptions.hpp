// Copyright (c) 2020-2025 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: mathExceptions.hpp
// Author: crdrisko
// Date: 10/26/2020-12:50:56
// Description: Exception classes specifically made for errors that could arrise in math-related functions

#ifndef DRYCHEM_INCLUDE_DRYCHEM_MATH_UTILS_MATHEXCEPTIONS_HPP
#define DRYCHEM_INCLUDE_DRYCHEM_MATH_UTILS_MATHEXCEPTIONS_HPP

#include <cstddef>
#include <string>

#include "drychem/errors/exceptions/fatalException.hpp"
#include "drychem/errors/utils/errorTypes.hpp"

namespace DryChem
{
    /*!
     * An exception class used specifically for the math libraries when two (or more) input
     *  containers have different sizes.
     */
    class InputSizeMismatch : public FatalException
    {
    public:
        InputSizeMismatch(const std::string& programName_, const std::string& fileName_, std::size_t lineNumber_)
            : FatalException {ErrorMessage {
                  programName_, "Input sizes for x and y containers must be the same.", fileName_, lineNumber_}}
        {
        }
    };
}   // namespace DryChem

#endif
