// Copyright (c) 2020-2024 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: getOptsExample.cpp
// Author: crdrisko
// Date: 11/18/2020-10:26:33
// Description:

#include <filesystem>
#include <iostream>
#include <memory>
#include <typeindex>
#include <typeinfo>
#include <unordered_map>
#include <vector>

#include <common-utils/meta.hpp>

#include "cmdLineOptions.hpp"
#include "commandLineParser.hpp"

using namespace GetOpts;

int main(int argc, const char* argv[])
{
    OptionalFlag uppercase {'u', "Change word/letter to uppercase. Defaults to false/off."};
    RequiredFlag lowercase {'l', "Change word/letter to lowercase. Defaults to false/off."};
    OptionalFlag first_letter {'f', "Change only the first letter to selected case. Defaults to false/off."};
    RequiredFlagWithString word {'w', "Word to change case of."};

    std::string exampleUsage {"changeCase -f -l -w LOWERCASE"};

    CommandLineParser cmdLine {uppercase, lowercase, first_letter, word};

    cmdLine.setCommandLineOptions(argc, argv);
    cmdLine.printHelpMessage(exampleUsage);
}
