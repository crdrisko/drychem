// Copyright (c) 2020-2024 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: tcpSocket.cpp
// Author: crdrisko
// Date: 10/18/2020-08:51:11
// Description: Implementation of the TCPSocket class

#include "common-utils/networking/tcp/tcpSocket.hpp"

#include <cstddef>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>

#include "common-utils/errors/exceptions/fatalException.hpp"
#include "common-utils/errors/utils/errorTypes.hpp"
#include "common-utils/networking/tcp/tcpStates/tcpClosed.hpp"
#include "common-utils/networking/utils/networkingExceptions.hpp"
#include "common-utils/networking/utils/networkingHeaders.hpp"

namespace CppUtils::Networking
{
    TCPSocket::TCPSocket(int port_, const std::string& address_) : state {TCPClosed::getInstance()}
    {
        // clang-format off
    #ifdef _MSC_VER
        WSADATA wsaData;

        if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
            throw Errors::FatalException {Errors::ErrorMessage {"Common-Utilities", "Winsock startup failed.", __FILE__, __LINE__}};
    #endif
        // clang-format on

        addrinfo hints {};

        if (address_.empty())
            hints.ai_flags = AI_PASSIVE;

        hints.ai_family   = AF_UNSPEC;
        hints.ai_socktype = SOCK_STREAM;

        this->setAddressInfo(address_, port_, hints);
    }

    TCPSocket::TCPSocket(SOCKET socket_, std::shared_ptr<TCPState> state_) : state {state_}, socket {socket_} {}

    TCPSocket::~TCPSocket()
    {
        state->close(this);

        // clang-format off
    #ifdef _MSC_VER
        WSACleanup();
    #endif
        // clang-format on
    }

    void TCPSocket::setAddressInfo(const std::string& address_, int port_, const addrinfo& hints_)
    {
        addrinfo* temp {nullptr};

        int status {::getaddrinfo(address_.c_str(), std::to_string(port_).c_str(), &hints_, &temp)};

        if (status)
            throw Errors::FatalException(Errors::ErrorMessage {"Common-Utilities",
                "getaddrinfo() exited with the following error: " + std::string {::gai_strerror(status)}});

        info.reset(temp);
    }

    void TCPSocket::send(std::stringstream&& data_) const
    {
        std::string strData {std::move(data_).str()};

        // clang-format off
    #ifdef _MSC_VER
        int len = static_cast<int>(strData.length());
    #else
        std::size_t len = strData.length();
    #endif
        // clang-format on

        if (::send(socket, strData.c_str(), len, 0) == -1)
            throw BasicNetworkingFailure {"send", __FILE__, __LINE__};
    }

    std::stringstream TCPSocket::receive() const
    {
        const int size {4096};
        char dataReceived[size];

        int sock = static_cast<int>(socket);

        ssize_t status {::recv(sock, dataReceived, size - 1, 0)};

        if (status == -1)
            throw BasicNetworkingFailure {"receive", __FILE__, __LINE__};
        else if (status == 0)
            std::cerr << "Detected a closed connection." << std::endl;
        else
            dataReceived[status] = '\0';

        std::stringstream data;

        data << dataReceived;

        return data;
    }

    std::string TCPSocket::queryState() const { return state->queryState(); }
}   // namespace CppUtils::Networking
