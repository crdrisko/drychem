// Copyright (c) 2020-2021 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: tcpClosed.cpp
// Author: crdrisko
// Date: 01/12/2021-09:26:17
// Description: Implementation of the TCPClosed state

#include "common-utils/networking/tcp/tcpStates/tcpClosed.hpp"

#include <iostream>

#include "common-utils/networking/tcp/tcpClient.hpp"
#include "common-utils/networking/tcp/tcpServer.hpp"
#include "common-utils/networking/tcp/tcpSocket.hpp"
#include "common-utils/networking/tcp/tcpStates/tcpOpened.hpp"
#include "common-utils/networking/utils/networkingExceptions.hpp"
#include "common-utils/networking/utils/networkingHeaders.hpp"

namespace CppUtils::Networking
{
    void TCPClosed::open(TCPSocket* socket_, const addrinfo* results_) const
    {
        SOCKET sock = ::socket(results_->ai_family, results_->ai_socktype, results_->ai_protocol);
        setSocket(socket_, sock);

        if (sock == -1)
            throw BasicNetworkingFailure {"open", __FILE__, __LINE__};
        else
            changeState(socket_, TCPOpened::getInstance());
    }

    void TCPClosed::close(TCPSocket*) const { throw AlreadyInNetworkState {"Closed", __FILE__, __LINE__}; }

    void TCPClosed::bind(TCPServer* server_) const
    {
        // Traverse the list of addresses until we can successfully bind to the client
        for (auto result {getInfo(server_)}; result != nullptr; result = getInfo(server_)->ai_next)
        {
            try
            {
                open(server_, result);
            }
            catch (const Errors::FatalException& except)
            {
                continue;
            }

            server_->bind();

            if (server_->queryState() == "Bound")
                break;
        }
    }

    void TCPClosed::connect(TCPClient* client_) const
    {
        // Traverse the list of addresses until we resolve the connection
        for (auto result {getInfo(client_)}; result != nullptr; result = getInfo(client_)->ai_next)
        {
            try
            {
                open(client_, result);
            }
            catch (const Errors::FatalException& except)
            {
                continue;
            }

            client_->connect();

            if (client_->queryState() == "Connected")
                break;
        }
    }
}   // namespace CppUtils::Networking
