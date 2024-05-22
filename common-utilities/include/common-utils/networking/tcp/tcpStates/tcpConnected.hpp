// Copyright (c) 2020-2024 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: tcpConnected.hpp
// Author: crdrisko
// Date: 01/12/2021-12:28:11
// Description: A TCP network socket state representing a connected socket

#ifndef DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_NETWORKING_TCP_TCPSTATES_TCPCONNECTED_HPP
#define DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_NETWORKING_TCP_TCPSTATES_TCPCONNECTED_HPP

#include <memory>
#include <string>

#include "common-utils/networking/tcp/tcpStates/tcpOpened.hpp"
#include "common-utils/networking/tcp/tcpStates/tcpState.hpp"
#include "common-utils/networking/utils/networkingExceptions.hpp"

namespace CppUtils::Networking
{
    class TCPConnected : public TCPState
    {
    private:
        static inline std::shared_ptr<TCPState> instance {nullptr};

    public:
        static auto getInstance()
        {
            if (!instance)
                instance = std::make_shared<TCPConnected>();

            return instance;
        }

        void open(TCPSocket* socket_, const addrinfo* results_) const override
        {
            TCPOpened::getInstance()->open(socket_, results_);
        }

        void close(TCPSocket* socket_) const override { TCPOpened::getInstance()->close(socket_); }

        void connect(TCPClient*) const override { throw AlreadyInNetworkState {"Connected", __FILE__, __LINE__}; }

        std::string queryState() const override { return "Connected"; }
    };
}   // namespace CppUtils::Networking

#endif
