// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: isFatal.hpp
// Author: crdrisko
// Date: 08/26/2020-14:26:29
// Description: Type trait used to determine whether a given ErrorSeverity is fatal or not

#ifndef COMMON_UTILITIES_ISFATAL_HPP
#define COMMON_UTILITIES_ISFATAL_HPP

#include <type_traits>

#include "errors/utils/errorTypes.hpp"

namespace CppUtils::Errors
{
    template<ErrorSeverity Severity>
    struct is_fatal : std::false_type
    {
    };

    template<>
    struct is_fatal<ErrorSeverity::Fatal> : std::true_type
    {
    };

    template<ErrorSeverity Severity>
    constexpr bool is_fatal_v = is_fatal<Severity>::value;
}   // namespace CppUtils::Errors

#endif
