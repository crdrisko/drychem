// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: testAllNetworkingFunctions.cpp
// Author: crdrisko
// Date: 10/29/2020-06:31:36
// Description: Provides ~100% unit test coverage over all networking functions and utilities

#include <gtest/gtest.h>

#include "testNetworking/testTCPClient.hpp"
#include "testNetworking/testTCPServer.hpp"
#include "testNetworking/testTCPSocket.hpp"

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
