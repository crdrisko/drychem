// Copyright (c) 2020-2024 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: tcpOpened.hpp
// Author: crdrisko
// Date: 01/12/2021-09:14:49
// Description: A TCP network socket state representing an open socket

#ifndef DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_NETWORKING_TCP_TCPSTATES_TCPOPENED_HPP
#define DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_NETWORKING_TCP_TCPSTATES_TCPOPENED_HPP

#include <memory>
#include <string>

#include "common-utils/networking/tcp/tcpStates/tcpState.hpp"
#include "common-utils/networking/utils/networkingHeaders.hpp"

namespace CppUtils::Networking
{
    class TCPOpened : public TCPState
    {
    private:
        static inline std::shared_ptr<TCPState> instance {nullptr};

    public:
        static auto getInstance()
        {
            if (!instance)
                instance = std::make_shared<TCPOpened>();

            return instance;
        }

        void open(TCPSocket* socket_, const addrinfo* results_) const override;
        void close(TCPSocket* socket_) const override;
        void connect(TCPClient* client_) const override;
        void bind(TCPServer* server_) const override;

        std::string queryState() const override { return "Opened"; }
    };
}   // namespace CppUtils::Networking

#endif
