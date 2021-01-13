// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: serverExample.cpp
// Author: crdrisko
// Date: 10/14/2020-10:17:41
// Description: An example of how to create a TCP server using the Berkeley Sockets API wrapper

#include <exception>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>

#include <common-utils/errors.hpp>
#include <common-utils/networking.hpp>

int main()
{
    try
    {
        try
        {
            int port {3000};
            DryChem::TCPServer server {port};

            server.bind();
            server.listen(5);
            auto acceptedSocket = server.accept();

            std::stringstream receivedMessage {acceptedSocket->receive()};

            std::cout << "Received Message: " << receivedMessage.str() << std::endl;
        }
        catch (const std::exception& except)
        {
            DryChem::ErrorMessage error;
            error.programName = "Common-Utilities";
            error.message     = "Exception message: " + std::string {except.what()};

            throw DryChem::FatalException(error);
        }
    }
    catch (const DryChem::FatalException& except)
    {
        except.handleErrorWithMessage();
    }
}
