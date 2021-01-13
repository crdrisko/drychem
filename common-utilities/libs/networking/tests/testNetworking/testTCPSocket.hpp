// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: testTCPSocket.hpp
// Author: crdrisko
// Date: 10/19/2020-07:23:52
// Description: Provides ~100% unit test coverage over all functions associated with the TCPSocket class

#ifndef COMMON_UTILITIES_TESTING_TESTTCPSOCKET_HPP
#define COMMON_UTILITIES_TESTING_TESTTCPSOCKET_HPP

#include <gtest/gtest.h>

#include "utilities.hpp"

using namespace CppUtils::Networking;

GTEST_TEST(testTCPSocket, aUniquePtrWithCustomDeleterCalls_freeaddrinfo_OnDestruction)
{
    testing::internal::CaptureStdout();

    std::unique_ptr<addrinfo, decltype(addrinfo_deleter)> info {nullptr, addrinfo_deleter};

    addrinfo* temp {nullptr};

    addrinfo hints {};
    hints.ai_family   = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    getaddrinfo("www.google.com", "80", &hints, &temp);

    int sockfd {socket(temp->ai_family, temp->ai_socktype, temp->ai_protocol)};

    info.reset(temp);

    int connectionResult {connect(sockfd, info->ai_addr, info->ai_addrlen)};

    if (connectionResult != -1)
        std::cout << "Connection successful!" << std::endl;

    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, "Connection successful!\n");
}

GTEST_TEST(testTCPSocket, anAdditionalCallTo_freeaddrinfo_resultsInProgramFailure)
{
    using AddrInfoPtr = std::unique_ptr<addrinfo, decltype(addrinfo_deleter)>;

    ASSERT_DEATH(
        {
            AddrInfoPtr info(nullptr, addrinfo_deleter);

            addrinfo* temp = nullptr;

            addrinfo hints {};
            hints.ai_family   = AF_UNSPEC;
            hints.ai_socktype = SOCK_STREAM;

            getaddrinfo("www.google.com", "80", &hints, &temp);

            info.reset(temp);

            freeaddrinfo(info.get());
        },
        "");
}

#endif
