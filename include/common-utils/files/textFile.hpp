// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: textFile.hpp - Version 1.0.0
// Author: cdrisko
// Date: 01/31/2020-15:39:33
// Description: Class definition of a file type containing comments separating metadata from data

#ifndef COMMON_UTILITIES_TEXTFILE_HPP
#define COMMON_UTILITIES_TEXTFILE_HPP

#include <string>
#include <string_view>
#include <vector>

#include "inputFile.hpp"
#include "../strings.hpp"

namespace CommonUtilities::Files
{
    class TextFile : public InputFile
    {
    private:
        std::string comments;
        std::vector<std::string> metaDataKeywords;

        virtual void separateFileData() override
        {
            std::vector<std::string> allDataVector { getFileContents().getContentInFile() };

            for (const auto& line : allDataVector)
            {
                if (metaDataKeywords[0] != "Null Selection" && Strings::stringFinder(comments, line))
                {
                    for (const auto& selection : metaDataKeywords)
                        if ( Strings::stringFinder(selection, line) )
                            metaDataVector.push_back(line);
                }
                else if ( (metaDataKeywords[0] == "Null Selection") && (Strings::stringFinder(comments, line)) )
                    metaDataVector.push_back(line);

                else if ( !Strings::stringFinder(comments, line) )
                    dataVector.push_back(line);
            }
        }

    public:
        explicit TextFile(std::string_view FullFileName, std::string Comments = "#",
            const std::vector<std::string>& MetaDataKeywords = {"Null Selection"})
                : InputFile{FullFileName}, comments{Comments}, metaDataKeywords{MetaDataKeywords}
        {
            separateFileData();
        }
    };
}

#endif
