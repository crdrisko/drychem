// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: file.hpp - Version 1.0.0
// Author: cdrisko
// Date: 01/31/2020-15:39:06
// Description: An abstract class interface for representing different file types

#ifndef UTILITIES_API_FILE_HPP
#define UTILITIES_API_FILE_HPP

#include "fileComponents.hpp"
#include "../Strings/stringUtilities.hpp"

namespace Utilities_API::Files
{
    class File
    {
    private:
        FileNamePtr fileName;
        FileContentsPtr fileContents;

        std::vector< std::vector<std::string> > splitDataVector(const std::vector<std::string>& dataVector,
            std::string separators = " \t\n")
        {
            std::vector< std::vector<std::string> > superVector;

            for (const auto& vec : dataVector)
                superVector.push_back(Strings::splitString(vec, separators));

            return superVector;
        }

    protected:
        std::vector<std::string> dataVector;
        std::vector<std::string> metaDataVector;

    public:
        explicit File(std::string_view FullFileName) : fileName{std::make_shared<FileName>(FullFileName)},
            fileContents{std::make_unique<FileContents>(fileName)} {}

        virtual ~File() = default;
        virtual void separateFileData() = 0;

        FileNamePtr getFileName() const { return this->fileName; }
        FileContentsPtr getFileContents() const { return this->fileContents; }

        std::vector< std::vector<std::string> > getSuperDataVector(std::string separators = " \t\n")
        {
            return splitDataVector(dataVector, separators);
        }

        std::vector< std::vector<std::string> > getSuperMetaDataVector(std::string separators = " \t\n")
        {
            return splitDataVector(metaDataVector, separators);
        }
    };

    using FilePtr = std::shared_ptr<File>;
}

#endif
