// Copyright (c) 2020-2021 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: tcpState.hpp
// Author: crdrisko
// Date: 01/12/2021-09:14:41
// Description: An abstract class representing the state of a TCP network socket

#ifndef DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_NETWORKING_TCP_TCPSTATES_TCPSTATE_HPP
#define DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_NETWORKING_TCP_TCPSTATES_TCPSTATE_HPP

#include <memory>
#include <string>

#include "common-utils/errors/exceptions/fatalException.hpp"
#include "common-utils/errors/utils/errorTypes.hpp"
#include "common-utils/networking/tcp/tcpSocket.hpp"
#include "common-utils/networking/utils/networkingHeaders.hpp"

namespace CppUtils::Networking
{
    class TCPClient;
    class TCPServer;

    class TCPState
    {
    protected:
        void changeState(TCPSocket* socket_, std::shared_ptr<TCPState> state_) const { socket_->state = state_; }

        SOCKET getSocket(TCPSocket* socket_) const { return socket_->socket; }
        void setSocket(TCPSocket* socket_, SOCKET sock_) const { socket_->socket = sock_; }

        addrinfo* getInfo(TCPSocket* socket_) const { return socket_->info.get(); }

    public:
        virtual ~TCPState() = default;

        virtual void open(TCPSocket*, const addrinfo*) const {}
        virtual void close(TCPSocket*) const {}
        virtual void connect(TCPClient*) const {}
        virtual void bind(TCPServer*) const {}

        virtual std::shared_ptr<TCPState> accept() const
        {
            throw Errors::FatalException {Errors::ErrorMessage {
                "Common-Utilities", "Attempting to create a socket with an unbound server.", __FILE__, __LINE__}};
        }

        virtual std::string queryState() const = 0;
    };
}   // namespace CppUtils::Networking

#endif
