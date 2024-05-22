// Copyright (c) 2020-2024 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: networking.hpp - Version 1.0.0
// Author: crdrisko
// Date: 10/29/2020-06:28:00
// Description: The public API for the Networking section of the Common-Utilities library.
//   This header file should be included in all user programs using these utilities.
//
// Note: The internal implementation details associated with this API should not be used in any
//   user program as they are subject to change at any time without warning.

#ifndef DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_NETWORKING_HPP
#define DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_NETWORKING_HPP

#include "networking/tcp/tcpClient.hpp"
#include "networking/tcp/tcpServer.hpp"
#include "networking/tcp/tcpSocket.hpp"
#include "networking/tcp/tcpStates/tcpBound.hpp"
#include "networking/tcp/tcpStates/tcpClosed.hpp"
#include "networking/tcp/tcpStates/tcpConnected.hpp"
#include "networking/tcp/tcpStates/tcpOpened.hpp"
#include "networking/tcp/tcpStates/tcpState.hpp"
#include "networking/utils/networkingExceptions.hpp"
#include "networking/utils/networkingHeaders.hpp"

//! Allow for a shorter namespace name for less \c using statements
namespace DryChem
{
    inline namespace CppUtils
    {
        inline namespace Networking
        {
            using namespace ::CppUtils::Networking;
        }
    }   // namespace CppUtils
}   // namespace DryChem

#endif
