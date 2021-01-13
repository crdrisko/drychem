// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: clientExample.cpp
// Author: crdrisko
// Date: 10/14/2020-10:17:35
// Description: An example of how to create a TCP client using the Berkeley Sockets API wrapper

#include <exception>
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
            std::string address {"127.0.0.1"};

            DryChem::TCPClient client {port, address};

            client.connect();

            std::string message {"Sending data over a network!"};
            std::stringstream sentMessage;

            sentMessage << message;

            client.send(std::move(sentMessage));
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
