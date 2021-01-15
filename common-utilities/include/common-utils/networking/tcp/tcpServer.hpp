// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: tcpServer.hpp
// Author: crdrisko
// Date: 10/14/2020-08:06:49
// Description: A simple wrapper for a TCP server socket using the Berkeley Sockets API

#ifndef DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_NETWORKING_TCP_TCPSERVER_HPP
#define DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_NETWORKING_TCP_TCPSERVER_HPP

#include <memory>
#include <string>

#include "common-utils/networking/tcp/tcpSocket.hpp"

namespace CppUtils::Networking
{
    class TCPServer : public TCPSocket
    {
    public:
        explicit TCPServer(int port_, const std::string& address_ = "") : TCPSocket {port_, address_} {}

        void bind();
        void listen(int queueSize_ = 5) const;
        std::unique_ptr<TCPSocket> accept() const;
    };
}   // namespace CppUtils::Networking

#endif
