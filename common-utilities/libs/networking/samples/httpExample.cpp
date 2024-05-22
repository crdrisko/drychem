// Copyright (c) 2020-2024 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: clientExample.cpp
// Author: crdrisko
// Date: 10/14/2020-10:17:47
// Description: An example of how to use the HTTP protocol with the Berkeley Sockets API wrapper

#include <iostream>
#include <sstream>
#include <string>
#include <utility>

#include <common-utils/networking.hpp>

int main()
{
    int port {80};
    std::string address {"www.example.com"};

    DryChem::TCPClient client {port, address};

    client.connect();

    std::stringstream sentMessage;
    sentMessage << "GET / HTTP/1.1\r\nHost: " << address << "\r\n\r\n";

    client.send(std::move(sentMessage));

    std::stringstream receivedMessage {client.receive()};
    std::cout << "Received Message:\n" << receivedMessage.str() << std::endl;
}
