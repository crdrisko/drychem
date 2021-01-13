// Copyright (c) 2020-2021 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: tcpOpened.cpp
// Author: crdrisko
// Date: 01/12/2021-09:26:28
// Description: Implementation of the TCPOpened state

#include "common-utils/networking/tcp/tcpStates/tcpOpened.hpp"

#include <iostream>

#include "common-utils/networking/tcp/tcpClient.hpp"
#include "common-utils/networking/tcp/tcpServer.hpp"
#include "common-utils/networking/tcp/tcpSocket.hpp"
#include "common-utils/networking/tcp/tcpStates/tcpBound.hpp"
#include "common-utils/networking/tcp/tcpStates/tcpClosed.hpp"
#include "common-utils/networking/tcp/tcpStates/tcpConnected.hpp"
#include "common-utils/networking/utils/networkingExceptions.hpp"
#include "common-utils/networking/utils/networkingHeaders.hpp"

namespace CppUtils::Networking
{
    void TCPOpened::open(TCPSocket*, const addrinfo*) const { throw AlreadyInNetworkState {"Opened", __FILE__, __LINE__}; }

    void TCPOpened::close(TCPSocket* socket_) const
    {
        SOCKET sock = getSocket(socket_);

        // clang-format off
    #ifdef _MSC_VER
        auto closeResult = ::closesocket(sock); 
    #else
        auto closeResult = ::close(sock);
    #endif
        // clang-format on    

        if (closeResult == -1)
            throw BasicNetworkingFailure {"close", __FILE__, __LINE__};
        else
            changeState(socket_, TCPClosed::getInstance()); 

        setSocket(socket_, static_cast<SOCKET>(0xFFFFFFFF));
    }

    void TCPOpened::bind(TCPServer* server_) const
    {
        if (::bind(getSocket(server_), getInfo(server_)->ai_addr, getInfo(server_)->ai_addrlen) == 0)
            changeState(server_, TCPBound::getInstance());
        else
            throw BasicNetworkingFailure {"bind", __FILE__, __LINE__};
    }

    void TCPOpened::connect(TCPClient* client_) const
    {
        if (::connect(getSocket(client_), getInfo(client_)->ai_addr, getInfo(client_)->ai_addrlen) == 0)
            changeState(client_, TCPConnected::getInstance());
        else
            throw BasicNetworkingFailure {"connect", __FILE__, __LINE__};
    }
}   // namespace CppUtils::Networking
