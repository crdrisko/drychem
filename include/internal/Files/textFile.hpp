// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: textFile.hpp - Version 1.0.0
// Author: cdrisko
// Date: 01/31/2020-15:39:33
// Description: Class definition of a file type containing comments separating metadata from data

#ifndef UTILITIES_API_TEXTFILE_HPP
#define UTILITIES_API_TEXTFILE_HPP

#include "file.hpp"

namespace Utilities_API::Files
{
    class TextFile : public File
    {
    private:
        std::string comments;
        std::vector<std::string> metaDataKeywords;

        virtual void separateFileData() override;

    public:
        TextFile(std::string_view FullFileName, std::string Comments = "#",
            std::vector<std::string> MetaDataKeywords = {"Null Selection"});
    };
}

#endif
