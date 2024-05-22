// Copyright (c) 2020-2024 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: testTCPSocket.hpp
// Author: crdrisko
// Date: 10/19/2020-07:23:52
// Description: Provides ~100% unit test coverage over all functions associated with the TCPSocket class

#ifndef DRYCHEM_COMMON_UTILITIES_LIBS_NETWORKING_TESTS_TESTNETWORKING_TESTTCPSOCKET_HPP
#define DRYCHEM_COMMON_UTILITIES_LIBS_NETWORKING_TESTS_TESTNETWORKING_TESTTCPSOCKET_HPP

#include <common-utils/networking.hpp>
#include <gtest/gtest.h>

using namespace DryChem;

GTEST_TEST(testTCPSocket, aUniquePtrWithCustomDeleterCalls_freeaddrinfo_OnDestruction)
{
#ifndef _MSC_VER
    testing::internal::CaptureStdout();

    std::unique_ptr<addrinfo, decltype(&::freeaddrinfo)> info {nullptr, &::freeaddrinfo};

    addrinfo* temp {nullptr};

    addrinfo hints {};
    hints.ai_family   = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    getaddrinfo("www.google.com", "80", &hints, &temp);

    SOCKET sockfd {socket(temp->ai_family, temp->ai_socktype, temp->ai_protocol)};

    info.reset(temp);

    // #ifdef _MSC_VER
    // int nameLength = static_cast<int>(info->ai_addrlen);
    // #else
    socklen_t nameLength = info->ai_addrlen;
    // #endif
    int connectionResult {connect(sockfd, info->ai_addr, nameLength)};

    if (connectionResult != -1)
        std::cout << "Connection successful!" << std::endl;

    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, "Connection successful!\n");
#endif
}

GTEST_TEST(testTCPSocket, anAdditionalCallTo_freeaddrinfo_resultsInProgramFailure)
{
    using AddrInfoPtr = std::unique_ptr<addrinfo, decltype(&::freeaddrinfo)>;

#ifndef _MSC_VER
    ASSERT_DEATH(
        {
            AddrInfoPtr info(nullptr, &::freeaddrinfo);

            addrinfo* temp = nullptr;

            addrinfo hints {};
            hints.ai_family   = AF_UNSPEC;
            hints.ai_socktype = SOCK_STREAM;

            getaddrinfo("www.google.com", "80", &hints, &temp);

            info.reset(temp);

            freeaddrinfo(info.get());
        },
        "");
#endif
}

#endif
