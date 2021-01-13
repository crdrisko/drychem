// Copyright (c) 2020-2021 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: passphraseGen.hpp
// Author: crdrisko
// Date: 01/08/2021-09:04:44
// Description: The function declarations used in the generation of a passphrase

#ifndef DRYCHEM_COMMON_UTILITIES_SRC_APPLICATIONS_PASSPHRASE_PASSPHRASEGEN_HPP
#define DRYCHEM_COMMON_UTILITIES_SRC_APPLICATIONS_PASSPHRASE_PASSPHRASEGEN_HPP

#include <cstddef>
#include <filesystem>
#include <string>
#include <unordered_map>

namespace Passphrase
{
    using WordMap = std::unordered_map<std::string, std::string>;

    namespace details
    {
        struct InputResult
        {
            std::filesystem::path fileName;
            std::size_t numberOfRolls;
        };

        struct ParseResult
        {
            WordMap words;
            std::size_t numDice;
        };
    }   // namespace details

    details::InputResult validateInput(int sys_argc, char* sys_argv[]);

    details::ParseResult parseInputFile(const std::filesystem::path& fileName);

    std::string rollDice(std::size_t numDice);

    std::string constructPassphrase(const WordMap& words, std::size_t numDice, std::size_t numRolls);
}   // namespace Passphrase

#endif
