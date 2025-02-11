// Copyright (c) 2020-2025 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: commandLineParser.hpp
// Author: crdrisko
// Date: 11/19/2020-14:13:01
// Description:

#ifndef COMMANDLINEPARSER_HPP
#define COMMANDLINEPARSER_HPP

#include <filesystem>
#include <tuple>
#include <utility>

#include <common-utils/meta.hpp>

#include "cmdLineOptions.hpp"

namespace GetOpts
{
    namespace fs = std::filesystem;

    template<typename... TArgs>
    class CommandLineParser
    {
    private:
        fs::path programName;

        std::tuple<TArgs...> options;

        std::string generateUsage() const
        {
            std::string usageMessage;

            usageMessage += "\nUSAGE: " + programName.stem().string() + " [-hv";

            DryChem::apply_n<3>([&](auto... elem) { ((usageMessage += elem.generateUsage()), ...); }, options);

            usageMessage += "] ";

            DryChem::apply_n<1>(
                [&](auto... elem) { ((usageMessage += elem.generateUsage() + " "), ...); }, DryChem::reverse(options));

            return usageMessage;
        }

    public:
        CommandLineParser(const TArgs&... Options) : options {Options...} {}

        void setCommandLineOptions(int, const char** argv) { programName = std::string {argv[0]}; }

        void printHelpMessage(const std::string& exampleUsage) const
        {
            std::cout << generateUsage() << "\n\n";
            std::cout << "  -h  Prints help information about the " << programName.stem() << " program.\n";
            std::cout << "  -v  Verbose mode. Defaults to false/off.\n";

            DryChem::apply_n<3>([&](auto... elem) { ((std::cout << elem.getHelpMessage() << std::endl), ...); }, options);

            std::cout << '\n';

            DryChem::apply_n<1>(
                [&](auto... elem) { ((std::cout << elem.getHelpMessage() << std::endl), ...); }, DryChem::reverse(options));

            std::cout << "\nEXAMPLE: " << exampleUsage << "\n\n";
        }
    };
}   // namespace GetOpts

#endif
