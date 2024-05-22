// Copyright (c) 2020-2024 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: columnStrategy.hpp
// Author: crdrisko
// Date: 01/01/2021-14:15:57
// Description: An implementations of file parser for parsing data as columns

#ifndef DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_FILES_FILEPARSING_PARSERSTRATEGIES_COLUMNSTRATEGY_HPP
#define DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_FILES_FILEPARSING_PARSERSTRATEGIES_COLUMNSTRATEGY_HPP

#include <algorithm>
#include <cstddef>
#include <optional>
#include <string>
#include <vector>

#include "common-utils/strings/utils/tokenizer.hpp"

namespace CppUtils::Files
{
    class AsColumns
    {
    private:
        mutable std::vector<std::string> columnCache;

        void resetColumnsOnNewLine(std::size_t tokenIndex_, std::size_t& columnIndex_) const
        {
            // We only need to resize the vector once after we know the number of columns
            if (tokenIndex_ == columnIndex_)
                columnCache.resize(tokenIndex_);

            columnIndex_ = 0;
        }

        void trimTrainingSeparators() const
        {
            // clang-format off
            std::transform(columnCache.begin(), columnCache.end(), columnCache.begin(),
                [](const std::string& column) { return column.substr(0, column.size() - 1); });
            //clang-format on
        }

    public:
        /*!
         * A file parser strategy used for splitting the data in a text file into columns.
         *
         * \param   fileContents - The content of a file read in to a std::string
         * \param fieldSeparator - The separator between data fields in the file (optional)
         *
         * \returns A \c std::vector<std::string> where each element of the vector is a column from the file.
         */
        auto operator()(
            const std::string& fileContents_, const std::optional<std::string>& fieldSeparator_ = std::nullopt) const
        {
            if (columnCache.empty())
            {
                std::string delimiters = fieldSeparator_.value_or("") + " \t\n";

                Strings::Tokenizer tok {fileContents_, delimiters, "\n"};

                auto tokens = tok.split();
                columnCache.resize(tokens.size());

                for (std::size_t i {}, j {}; i < tokens.size(); ++i)
                {
                    if (tokens[i] == "\n")
                    {
                        this->resetColumnsOnNewLine(i, j);
                        continue;
                    }

                    columnCache[j++].append(tokens[i]).append(fieldSeparator_.value_or("\t"));
                }

                this->trimTrainingSeparators();
            }

            return columnCache;
        }
    };
}   // namespace CppUtils::Files


#endif
