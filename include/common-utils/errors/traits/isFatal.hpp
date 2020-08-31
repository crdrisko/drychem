// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: isFatal.hpp - Version 2.0.1
// Author: crdrisko
// Date: 08/26/2020-14:26:29
// Description: Type traits used specifically for error and exception handing

#ifndef COMMON_UTILITIES_ISFATAL_HPP
#define COMMON_UTILITIES_ISFATAL_HPP

#include "../utils/errorTypes.hpp"

namespace CommonUtilities::Errors
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
