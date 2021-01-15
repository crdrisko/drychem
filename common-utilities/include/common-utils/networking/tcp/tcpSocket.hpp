// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: tcpSocket.hpp
// Author: crdrisko
// Date: 10/13/2020-09:34:55
// Description: A simple wrapper for a TCP socket using the Berkeley Sockets API

#ifndef DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_NETWORKING_TCP_TCPSOCKET_HPP
#define DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_NETWORKING_TCP_TCPSOCKET_HPP

#include <memory>
#include <sstream>
#include <string>

#include "common-utils/networking/utils/networkingHeaders.hpp"

namespace CppUtils::Networking
{
    class TCPState;

    class TCPSocket
    {
    private:
        friend class TCPState;

        void setAddressInfo(const std::string& address_, int port_, const addrinfo& hints_);

    protected:
        std::shared_ptr<TCPState> state;

        SOCKET socket {static_cast<SOCKET>(0xFFFFFFFF)};
        std::unique_ptr<addrinfo, decltype(&::freeaddrinfo)> info {nullptr, &::freeaddrinfo};

    public:
        explicit TCPSocket(int port_, const std::string& address_ = "");
        TCPSocket(SOCKET socket_, std::shared_ptr<TCPState> state_);

        virtual ~TCPSocket();
        TCPSocket(const TCPSocket&) = delete;
        TCPSocket(TCPSocket&&)      = default;
        TCPSocket& operator=(const TCPSocket&) = delete;
        TCPSocket& operator=(TCPSocket&&) = default;

        void send(std::stringstream&& data_) const;
        std::stringstream receive() const;

        std::string queryState() const;
    };
}   // namespace CppUtils::Networking

#endif
