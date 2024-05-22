// Copyright (c) 2020-2024 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: tcpClient.cpp
// Author: crdrisko
// Date: 10/18/2020-08:51:22
// Description: Implementation of the TCPClient class

#include "common-utils/networking/tcp/tcpClient.hpp"

#include "common-utils/networking/tcp/tcpStates/tcpState.hpp"

namespace CppUtils::Networking
{
    void TCPClient::connect() { state->connect(this); }
}   // namespace CppUtils::Networking
