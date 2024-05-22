// Copyright (c) 2020-2024 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: networkingHeaders.hpp
// Author: crdrisko
// Date: 01/10/2021-12:39:06
// Description: A single collection of all headers and configuration options related to cross-platform networking

#ifndef DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_NETWORKING_UTILS_NETWORKINGHEADERS_HPP
#define DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_NETWORKING_UTILS_NETWORKINGHEADERS_HPP

// clang-format off
#ifdef _MSC_VER
    #pragma comment(lib, "Ws2_32.lib")

    #include <Winsock2.h>
    #include <WS2tcpip.h>

    using ssize_t = SSIZE_T;
#else
    #include <netdb.h>
    #include <unistd.h>

    #include <sys/types.h>
    #include <sys/socket.h>

    using SOCKET = int;
#endif
// clang-format on

#endif
