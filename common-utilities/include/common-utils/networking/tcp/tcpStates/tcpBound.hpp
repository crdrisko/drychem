// Copyright (c) 2020-2024 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: tcpBound.hpp
// Author: crdrisko
// Date: 01/12/2021-16:59:29
// Description: A TCP network socket state representing a bound socket

#ifndef DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_NETWORKING_TCP_TCPSTATES_TCPBOUND_HPP
#define DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_NETWORKING_TCP_TCPSTATES_TCPBOUND_HPP

#include <memory>
#include <string>

#include "common-utils/networking/tcp/tcpStates/tcpOpened.hpp"
#include "common-utils/networking/tcp/tcpStates/tcpState.hpp"
#include "common-utils/networking/utils/networkingExceptions.hpp"

namespace CppUtils::Networking
{
    class TCPBound : public TCPState
    {
    private:
        static inline std::shared_ptr<TCPState> instance {nullptr};

    public:
        static auto getInstance()
        {
            if (!instance)
                instance = std::make_shared<TCPBound>();

            return instance;
        }

        void open(TCPSocket* socket_, const addrinfo* results_) const override
        {
            TCPOpened::getInstance()->open(socket_, results_);
        }

        void close(TCPSocket* socket_) const override { TCPOpened::getInstance()->close(socket_); }

        void bind(TCPServer*) const override { throw AlreadyInNetworkState {"Bound", __FILE__, __LINE__}; }

        std::shared_ptr<TCPState> accept() const override { return TCPBound::getInstance(); }

        std::string queryState() const override { return "Bound"; }
    };
}   // namespace CppUtils::Networking

#endif
