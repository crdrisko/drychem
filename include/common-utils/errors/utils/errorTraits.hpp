// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: errorTraits.hpp - Version 2.0.0
// Author: crdrisko
// Date: 08/26/2020-14:26:29
// Description: Type traits used specifically for error and exception handing

#ifndef COMMON_UTILITIES_ERRORTRAITS_HPP
#define COMMON_UTILITIES_ERRORTRAITS_HPP

#include "errorTypes.hpp"

namespace CommonUtilities::Errors::Traits
{
    template<ErrorSeverity Severity>
    struct IsFatalT
    {
        static constexpr bool value = false;
    };

    template<>
    struct IsFatalT<ErrorSeverity::Fatal>
    {
        static constexpr bool value = true;
    };

    template<ErrorSeverity Severity>
    constexpr bool isFatal = IsFatalT<Severity>::value;
}

#endif
