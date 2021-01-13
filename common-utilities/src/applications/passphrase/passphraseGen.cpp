// Copyright (c) 2020-2021 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: passphraseGen.cpp
// Author: crdrisko
// Date: 12/15/2020-07:54:38
// Description: The function definitions used in the generation of a passphrase

#include "passphraseGen.hpp"

#include <algorithm>
#include <cstddef>
#include <cstring>
#include <filesystem>
#include <random>
#include <sstream>
#include <string>
#include <unordered_map>
#include <utility>

#include <common-utils/errors.hpp>
#include <common-utils/files.hpp>
#include <common-utils/strings.hpp>

namespace Passphrase
{
    details::InputResult validateInput(int sys_argc, char* sys_argv[])
    {
        details::InputResult result;

        int requiredInputCount {1};
        int currentInputCount {};

        for (int option {1}; option < sys_argc; ++option)
        {
            if ('-' == sys_argv[option][0] && std::strlen(sys_argv[option]) == 2)
            {
                switch (sys_argv[option][1])
                {
                case 'i':
                    ++option;
                    if (sys_argv[option] != NULL)
                    {
                        result.fileName = sys_argv[option];
                        ++currentInputCount;
                    }
                    break;
                case 'r':
                    ++option;
                    result.numberOfRolls = std::stoul(sys_argv[option]);
                    break;
                default:
                    --currentInputCount;
                    break;
                }
            }
        }

        if (currentInputCount != requiredInputCount)
        {
            std::stringstream strm;
            strm << "Usage: " << sys_argv[0] << " -i FILE [-r INT]\n";

            throw DryChem::FatalException {DryChem::ErrorMessage {"PassphraseGen", strm.str(), __FILE__, __LINE__}};
        }

        return result;
    }

    details::ParseResult parseInputFile(const std::filesystem::path& fileName)
    {
        details::ParseResult result;

        DryChem::FileParser parser {fileName};

        parser.parseDataFile([&result](const std::string& fileContents) {
            DryChem::Tokenizer tok {fileContents};
            auto split = tok.split();

            result.numDice = split[0].length();

            for (std::size_t i {}; i < split.size(); i += 2)
                result.words[split[i]] = split[i + 1];
        });

        return result;
    }

    std::string rollDice(std::size_t numDice)
    {
        static std::random_device seed;
        static std::mt19937_64 generator {seed()};
        static std::uniform_int_distribution<> distribution {1, 6};

        std::string diceRoll {};

        for (std::size_t dice {}; dice < numDice; ++dice)
            diceRoll.append(std::to_string(distribution(generator)));

        return diceRoll;
    }

    std::string constructPassphrase(const WordMap& words, std::size_t numDice, std::size_t numRolls)
    {
        std::string passphrase {};

        for (std::size_t roll {}; roll < numRolls; ++roll)
        {
            std::string diceRoll = rollDice(numDice);

            passphrase.append(words.at(diceRoll)).append(" ");
        }

        return passphrase;
    }
}   // namespace Passphrase
