// Copyright (c) 2020-2024 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: serverClientExample.cpp
// Author: crdrisko
// Date: 01/15/2021-09:06:35
// Description: An example of how to use the Berkeley Sockets API wrapper for servers and clients alike

#include <iostream>
#include <sstream>
#include <string>
#include <thread>
#include <utility>

#include <common-utils/networking.hpp>

void runClientCode(int port, const std::string& address)
{
    DryChem::TCPClient client {port, address};

    client.connect();

    std::stringstream sentMessage;
    sentMessage << "Sending data over a network!";

    client.send(std::move(sentMessage));
}

int main()
{
    int port {3000};
    std::string address {"127.0.0.1"};

    DryChem::TCPServer server {port};

    std::thread clientThread {runClientCode, port, address};

    server.bind();
    server.listen();
    auto acceptedSocket = server.accept();

    std::cout << "Received Message: " << acceptedSocket->receive().str() << std::endl;

    clientThread.join();
}
