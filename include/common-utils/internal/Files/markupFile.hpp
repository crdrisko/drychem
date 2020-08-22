// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: markupFile.hpp - Version 1.0.0
// Author: cdrisko
// Date: 01/31/2020-15:39:25
// Description: Class definition of a file type containing html-like tags separating metadata from data

#ifndef COMMON_UTILITIES_MARKUPFILE_HPP
#define COMMON_UTILITIES_MARKUPFILE_HPP

#include <string>
#include <string_view>
#include <vector>

#include "inputFile.hpp"
#include "../../strings.hpp"

namespace CommonUtilities::Files
{
    class MarkupFile : public InputFile
    {
    private:
        std::string dataTag;
        std::string metaTag;

        virtual void separateFileData() override
        {
            std::vector<std::string> allDataVector { getFileContents().getContentInFile() };

            for (std::size_t i {}; i < allDataVector.size(); ++i)
            {
                if ( Strings::stringFinder(metaTag, allDataVector[i]) )
                {
                    std::string endMetaTag {metaTag};
                    endMetaTag.insert(1, "/");

                    for (std::size_t j {i + 1}; j < allDataVector.size(); ++j)
                    {
                        if ( Strings::stringFinder(endMetaTag, allDataVector[j]) )
                            break;
                        else
                            metaDataVector.push_back(allDataVector[j]);
                    }
                }
                else if ( Strings::stringFinder(dataTag, allDataVector[i]) )
                {
                    std::string endDataTag {dataTag};
                    endDataTag.insert(1, "/");

                    for (std::size_t j {i + 1}; j < allDataVector.size(); ++j)
                    {
                        if ( Strings::stringFinder(endDataTag, allDataVector[j]) )
                            break;
                        else
                            dataVector.push_back(allDataVector[j]);
                    }
                }
            }
        }

    public:
        MarkupFile(std::string_view FullFileName, std::string_view DataTag = "<data>",
            std::string_view MetaTag = "<metadata>") : InputFile{FullFileName}, dataTag{DataTag},
                metaTag{MetaTag}
        {
            separateFileData();
        }
    };
}

#endif
