// Copyright (c) 2020-2021 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: errorTypes.hpp
// Author: crdrisko
// Date: 08/26/2020-14:53:34
// Description: Common types to be used with the various error handling techniques

#ifndef DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_ERRORS_UTILS_ERRORTYPES_HPP
#define DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_ERRORS_UTILS_ERRORTYPES_HPP

#include <cstddef>
#include <string>

namespace CppUtils::Errors
{
    /*! 
     * A simple scoped enumeration for use in defining the severity of the error in a cleaner, 
     *  more verbose way than simple boolean flags would allow. 
     */
    enum class ErrorSeverity
    {
        Warning,   //!< Describes the severity of an error that only requires a warning
        Fatal      //!< Describes the severity of a fatal, non-recoverable error
    };

    /*! 
     * Defines an aggregate and can be initialized as such without the explicitly
     *  defined constructors.
     */
    struct ErrorMessage
    {
        std::string programName {};   //!< The name of the program where the exception originated
        std::string message {};       //!< The main error message describing the error
        std::string fileName {};      //!< The file name where the error took place, use the __FILE__ macro
        std::size_t lineNumber {};    //!< The line number where the error took place, use the __LINE__ macro
    };
}   // namespace CppUtils::Errors

#endif
