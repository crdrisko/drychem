// Copyright (c) 2020-2021 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: rowStrategy.hpp
// Author: crdrisko
// Date: 01/01/2021-14:15:47
// Description: An implementations of file parser for parsing data as rows

#ifndef DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_FILES_FILEPARSING_PARSERSTRATEGIES_ROWSTRATEGY_HPP
#define DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_FILES_FILEPARSING_PARSERSTRATEGIES_ROWSTRATEGY_HPP

#include <string>
#include <vector>

#include "common-utils/strings/utils/tokenizer.hpp"

namespace CppUtils::Files
{
    class AsRows
    {
    private:
        mutable std::vector<std::string> rowCache;

    public:
        /*!
         * A file parser strategy used for splitting the data in a text file into rows.
         * 
         * \param fileContents - The content of a file read in to a std::string
         * 
         * \returns A \c std::vector<std::string> where each element of the vector is a line from the file.
         */
        auto operator()(const std::string& fileContents_) const
        {
            if (rowCache.empty())
            {
                Strings::Tokenizer tok {fileContents_, "\n"};
                rowCache = tok.split();
            }

            return rowCache;
        }
    };
}   // namespace CppUtils::Files


#endif
