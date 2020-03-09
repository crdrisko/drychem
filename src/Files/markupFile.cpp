// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: markupFile.cpp - Version 1.0.0
// Author: cdrisko
// Date: 01/31/2020-15:21:46
// Description: Constructors and non-inline functions from the MarkupFile class

#include <string>
#include <string_view>
#include <vector>

#include "../../include/internal/Files/markupFile.hpp"
#include "../../include/internal/Strings/stringUtilities.hpp"

namespace Utilities_API::Files
{
    MarkupFile::MarkupFile(std::string_view FullFileName, std::string_view DataTag, std::string_view MetaTag)
        : InputFile{FullFileName}, dataTag{DataTag}, metaTag{MetaTag}
    {
        separateFileData();
    }

    void MarkupFile::separateFileData()
    {
        std::vector<std::string> allDataVector { getFileContents().getContentInFile() };

        for (size_t i {}; i < allDataVector.size(); ++i)
        {
            if (Strings::stringFinder(metaTag, allDataVector[i]))
            {
                std::string endMetaTag {metaTag};
                endMetaTag.insert(1, "/");

                for (size_t j {i + 1}; j < allDataVector.size(); ++j)
                {
                    if (Strings::stringFinder(endMetaTag, allDataVector[j]))
                        break;
                    else
                        metaDataVector.push_back(allDataVector[j]);
                }
            }
            else if (Strings::stringFinder(dataTag, allDataVector[i]))
            {
                std::string endDataTag {dataTag};
                endDataTag.insert(1, "/");

                for (size_t j {i + 1}; j < allDataVector.size(); ++j)
                {
                    if (Strings::stringFinder(endDataTag, allDataVector[j]))
                        break;
                    else
                        dataVector.push_back(allDataVector[j]);
                }
            }
        }
    }
}
