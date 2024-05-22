// Copyright (c) 2020-2024 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: tcpClient.hpp
// Author: crdrisko
// Date: 10/14/2020-08:06:57
// Description: A simple wrapper for a TCP client socket using the Berkeley Sockets API

#ifndef DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_NETWORKING_TCP_TCPCLIENT_HPP
#define DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_NETWORKING_TCP_TCPCLIENT_HPP

#include <string>

#include "common-utils/networking/tcp/tcpSocket.hpp"

namespace CppUtils::Networking
{
    class TCPClient : public TCPSocket
    {
    public:
        explicit TCPClient(int port_, const std::string& address_ = "") : TCPSocket {port_, address_} {}

        void connect();
    };
}   // namespace CppUtils::Networking

#endif
