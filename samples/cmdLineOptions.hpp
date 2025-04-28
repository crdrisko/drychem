// Copyright (c) 2020-2025 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: cmdLineOptions.hpp
// Author: crdrisko
// Date: 11/18/2020-10:26:33
// Description:

#ifndef CMDLINEOPTIONS_HPP
#define CMDLINEOPTIONS_HPP

#include <filesystem>
#include <iostream>
#include <sstream>
#include <string>
#include <typeindex>
#include <typeinfo>
#include <unordered_map>
#include <vector>

namespace GetOpts
{
    namespace fs = std::filesystem;

    // clang-format off
    static inline std::unordered_map<std::type_index, std::string> type_names 
    {
        {std::type_index(typeid(std::vector<double>)),      "ARRAY<DOUBLE>"},
        {std::type_index(typeid(std::vector<fs::path>)),    "ARRAY<FILE>"},
        {std::type_index(typeid(std::vector<int>)),         "ARRAY<INT>"},
        {std::type_index(typeid(std::vector<std::string>)), "ARRAY<STRING>"},
        {std::type_index(typeid(double)),                   "DOUBLE"},
        {std::type_index(typeid(fs::path)),                 "FILE"},
        {std::type_index(typeid(int)),                      "INT"},
        {std::type_index(typeid(std::string)),              "STRING"}
    };
    // clang-format on

    template<template<typename> class... Mixins>
    struct CommandLineOption : Mixins<CommandLineOption<Mixins...>>...
    {
        char flag;
        std::string helpMessageLine;

        CommandLineOption(char Flag, const std::string& HelpMessageLine)
            : Mixins<CommandLineOption>()..., flag {Flag}, helpMessageLine {HelpMessageLine}
        {
        }
    };

    template<typename Derived>
    class Required
    {
    private:
        const Derived* pDerived {static_cast<const Derived*>(this)};

    public:
        std::string getHelpMessage() const
        {
            std::stringstream strm;
            strm << "  -" << pDerived->flag << (Derived::usePrefix ? "  REQUIRED: " : "  ") << pDerived->helpMessageLine;

            return strm.str();
        }
    };

    template<typename Derived>
    class Optional
    {
    private:
        const Derived* pDerived {static_cast<const Derived*>(this)};

    public:
        std::string getHelpMessage() const
        {
            std::stringstream strm;
            strm << "  -" << pDerived->flag << (Derived::usePrefix ? "  OPTIONAL: " : "  ") << pDerived->helpMessageLine;

            return strm.str();
        }
    };

    template<typename Derived>
    class WithoutArgument
    {
    private:
        const Derived* pDerived {static_cast<const Derived*>(this)};

    public:
        static inline constexpr bool usePrefix = false;
        std::string generateUsage() const { return std::string {pDerived->flag}; }
    };

    template<typename T, typename Derived>
    class WithArgument
    {
    private:
        T var;
        const Derived* pDerived {static_cast<const Derived*>(this)};

    public:
        static inline constexpr bool usePrefix = true;

        std::string generateUsage() const
        {
            std::stringstream strm;
            strm << "[-" << pDerived->flag << " " << type_names[std::type_index(typeid(var))] << "]";

            return strm.str();
        }
    };


    // Convinence aliases for possible input types
    template<typename Derived>
    using WithDoubleArgument = WithArgument<double, Derived>;

    template<typename Derived>
    using WithFileArgument = WithArgument<fs::path, Derived>;

    template<typename Derived>
    using WithIntegerArgument = WithArgument<int, Derived>;

    template<typename Derived>
    using WithStringArgument = WithArgument<std::string, Derived>;


    // Possible Command-Line Options
    using OptionalFlag            = CommandLineOption<Optional, WithoutArgument>;
    using OptionalFlagWithDouble  = CommandLineOption<Optional, WithDoubleArgument>;
    using OptionalFlagWithFile    = CommandLineOption<Optional, WithFileArgument>;
    using OptionalFlagWithInteger = CommandLineOption<Optional, WithIntegerArgument>;
    using OptionalFlagWithString  = CommandLineOption<Optional, WithStringArgument>;

    using RequiredFlag            = CommandLineOption<Required, WithoutArgument>;
    using RequiredFlagWithDouble  = CommandLineOption<Required, WithDoubleArgument>;
    using RequiredFlagWithFile    = CommandLineOption<Required, WithFileArgument>;
    using RequiredFlagWithInteger = CommandLineOption<Required, WithIntegerArgument>;
    using RequiredFlagWithString  = CommandLineOption<Required, WithStringArgument>;
}   // namespace GetOpts

#endif
