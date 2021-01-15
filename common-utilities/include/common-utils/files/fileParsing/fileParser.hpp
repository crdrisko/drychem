// Copyright (c) 2020-2021 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: fileParser.hpp
// Author: crdrisko
// Date: 11/18/2020-07:08:47
// Description: The context class in the Strategy implementation of a file parser

#ifndef DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_FILES_FILEPARSING_FILEPARSER_HPP
#define DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_FILES_FILEPARSING_FILEPARSER_HPP

#include <filesystem>
#include <fstream>
#include <functional>
#include <iterator>
#include <string>
#include <type_traits>
#include <utility>

#include "common-utils/files/utils/fileExceptions.hpp"

namespace CppUtils::Files
{
    class FileParser
    {
    private:
        const std::filesystem::path fileName;
        mutable std::string fileContentCache;

        /*!
         * A function to read the contents of a file and assign them to the appropriate cache.
         * 
         * \exception CppUtils::Files::FileNotFound If the file isn't a regular file, we will throw an exception
         */
        void readFileContent() const
        {
            if (std::filesystem::is_regular_file(fileName))
            {
                std::ifstream inputFile {fileName};

                fileContentCache.assign(std::istreambuf_iterator<char>(inputFile), std::istreambuf_iterator<char>());
            }
            else
                throw FileNotFound {"Common-Utilities", __FILE__, __LINE__};
        }

    public:
        explicit FileParser(const std::filesystem::path& fileName_) noexcept : fileName {fileName_} {}

        std::filesystem::path getFileName() const noexcept { return fileName; }

        /*!
         * A wrapper to move the parsing of a given input file to the client.
         * 
         * \tparam F        The type of the function we are calling
         * \tparam ...TArgs The types of the arguments passed to the function f
         * 
         * \param f    The function to invoke
         * \param args The parameters of the function we are invoking
         * 
         * \returns Here we return whatever the function, f, returns even if that is a void function.
         * 
         * \warning The function must take the file contents as a \c std::string by constant-reference in 
         *          it's first argument. This requirement disqualifies all member functions but allows for 
         *          a simpler syntax for those callable types we do support.
         */
        template<typename F, typename... TArgs>
        constexpr decltype(auto) parseDataFile(F&& f_, TArgs&&... args_) const
        {
            if (fileContentCache.empty())
                this->readFileContent();

            // Need to handle `void f(args...)` case differently from `auto f(args...)` case
            if constexpr (std::is_void_v<std::invoke_result_t<F, std::string, TArgs...>>)
                std::invoke(std::forward<F>(f_), std::cref(fileContentCache), std::forward<TArgs>(args_)...);
            else
                return std::invoke(std::forward<F>(f_), std::cref(fileContentCache), std::forward<TArgs>(args_)...);
        }
    };
}   // namespace CppUtils::Files

#endif
