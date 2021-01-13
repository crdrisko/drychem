// Copyright (c) 2020-2021 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: passphrase.cpp
// Author: crdrisko
// Date: 01/09/2021-08:07:38
// Description: Generating a random passphrase through the simulation of rolling dice

#include <exception>
#include <iostream>
#include <string>

#include <common-utils/errors.hpp>

#include "passphraseGen.hpp"

int main(int argc, char* argv[])
{
    std::string passphrase {};

    try
    {
        try
        {
            auto [fileName, numRolls] = Passphrase::validateInput(argc, argv);
            auto [words, numDice]     = Passphrase::parseInputFile(fileName);

            passphrase = Passphrase::constructPassphrase(words, numDice, numRolls);
        }
        catch (const std::exception& except)
        {
            // Toss the exception back up for program termination and a more verbose message
            DryChem::ErrorMessage error;
            error.programName = "Passphrase";
            error.message     = "An exception was thrown from " + std::string {except.what()};

            throw DryChem::FatalException(error);
        }
    }
    catch (const DryChem::FatalException& except)
    {
        except.handleErrorWithMessage();
    }

    std::cout << "Passphrase: " << passphrase << std::endl;
}
