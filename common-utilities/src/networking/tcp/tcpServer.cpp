// Copyright (c) 2020-2024 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: tcpServer.cpp
// Author: crdrisko
// Date: 10/18/2020-08:51:18
// Description: Implementation of the TCPServer class

#include "common-utils/networking/tcp/tcpServer.hpp"

#include <memory>

#include "common-utils/networking/tcp/tcpServer.hpp"
#include "common-utils/networking/tcp/tcpStates/tcpState.hpp"
#include "common-utils/networking/utils/networkingExceptions.hpp"
#include "common-utils/networking/utils/networkingHeaders.hpp"

namespace CppUtils::Networking
{
    void TCPServer::bind() { state->bind(this); }

    void TCPServer::listen(int queueSize_) const
    {
        if (::listen(socket, queueSize_) == -1)
            throw BasicNetworkingFailure {"listen", __FILE__, __LINE__};
    }

    std::unique_ptr<TCPSocket> TCPServer::accept() const
    {
        struct ReturnAddress
        {
            sockaddr addr;
            sockaddr_storage storage;
        };

        ReturnAddress returnAddress;
        socklen_t addressSize {sizeof(sockaddr_storage)};

        SOCKET sock {::accept(socket, reinterpret_cast<sockaddr*>(&returnAddress.storage), &addressSize)};

        if (sock == -1)
            throw BasicNetworkingFailure {"accept", __FILE__, __LINE__};

        return std::make_unique<TCPSocket>(sock, state->accept());
    }
}   // namespace CppUtils::Networking
