// Copyright (c) 2020-2025 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: isFatal.hpp
// Author: crdrisko
// Date: 08/26/2020-14:26:29
// Description: Type trait used to determine whether a given ErrorSeverity is fatal or not

#ifndef DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_ERRORS_TRAITS_ISFATAL_HPP
#define DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_ERRORS_TRAITS_ISFATAL_HPP

#include <type_traits>

#include "common-utils/errors/utils/errorTypes.hpp"

namespace CppUtils::Errors
{
    /*!
     * A type trait to determine whether or not the supplied ErrorSeverity describes a 
     *  fatal error.
     *
     * \tparam Severity - The severity of the error in question
     */
    template<ErrorSeverity Severity>
    struct is_fatal : std::false_type
    {
    };

    /*!
     * A partial specialization of our \c is_fatal type trait for when the given
     *  error severity is fatal.
     */
    template<>
    struct is_fatal<ErrorSeverity::Fatal> : std::true_type
    {
    };

    //! Convenience variable template for ease-of-use
    template<ErrorSeverity Severity>
    constexpr bool is_fatal_v = is_fatal<Severity>::value;
}   // namespace CppUtils::Errors

#endif
