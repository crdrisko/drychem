// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: markupFile.hpp - Version 1.0.0
// Author: cdrisko
// Date: 01/31/2020-15:39:25
// Description: Class definition of a file type containing html-like tags separating metadata from data

#ifndef UTILITIES_API_MARKUPFILE_HPP
#define UTILITIES_API_MARKUPFILE_HPP

#include <string>
#include <string_view>

#include "inputFile.hpp"

namespace Utilities_API::Files
{
    class MarkupFile : public InputFile
    {
    private:
        std::string dataTag;
        std::string metaTag;

        virtual void separateFileData() override;

    public:
        MarkupFile(std::string_view FullFileName, std::string_view DataTag = "<data>",
            std::string_view MetaTag = "<metadata>");
    };
}

#endif
