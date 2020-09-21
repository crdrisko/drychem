// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: isFatal.hpp - Version 2.0.0
// Author: crdrisko
// Date: 08/26/2020-14:26:29
// Description: Type trait used to determine whether a given ErrorSeverity is fatal or not

#ifndef COMMON_UTILITIES_ISFATAL_HPP
#define COMMON_UTILITIES_ISFATAL_HPP

#include <type_traits>

#include "errors/utils/errorTypes.hpp"

namespace CommonUtilities::Errors
{
    template<ErrorSeverity Severity>
    struct IsFatalT : std::false_type {};

    template<>
    struct IsFatalT<ErrorSeverity::Fatal> : std::true_type {};

    template<ErrorSeverity Severity>
    constexpr bool isFatal = IsFatalT<Severity>::value;
}

#endif
