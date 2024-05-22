// Copyright (c) 2020-2024 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: tcpClosed.hpp
// Author: crdrisko
// Date: 01/12/2021-09:14:55
// Description: A TCP network socket state representing a closed socket

#ifndef DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_NETWORKING_TCP_TCPSTATES_TCPCLOSED_HPP
#define DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_NETWORKING_TCP_TCPSTATES_TCPCLOSED_HPP

#include <memory>
#include <string>

#include "common-utils/networking/tcp/tcpStates/tcpState.hpp"
#include "common-utils/networking/utils/networkingHeaders.hpp"

namespace CppUtils::Networking
{
    class TCPClosed : public TCPState
    {
    private:
        static inline std::shared_ptr<TCPState> instance {nullptr};

    public:
        static auto getInstance()
        {
            if (!instance)
                instance = std::make_shared<TCPClosed>();

            return instance;
        }

        void open(TCPSocket* socket_, const addrinfo* results_) const override;
        void close(TCPSocket* socket_) const override;
        void connect(TCPClient* client_) const override;
        void bind(TCPServer* server_) const override;

        std::string queryState() const override { return "Closed"; }
    };
}   // namespace CppUtils::Networking

#endif
