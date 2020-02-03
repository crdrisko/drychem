// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: fileComponents.hpp - Version 1.0.0
// Author: cdrisko
// Date: 01/31/2020-15:39:15
// Description: Classes representing the contents of a file and the file's name

#ifndef UTILITIES_API_FILECOMPONENTS_HPP
#define UTILITIES_API_FILECOMPONENTS_HPP

#include <vector>
#include <memory>
#include <string>
#include <fstream>
#include <string_view>
#include "../Errors/errorUtilities.hpp"

namespace Utilities_API::Files
{
    class FileName
    {
    private:
        std::string baseFileName;
        std::string relativePathToFile {""};
        std::string fileExtension {""};

        void splitFileName(std::string_view fullFileName)
        {
            size_t pathLocation {fullFileName.find_last_of("/")};
            size_t extensionLocation {fullFileName.find_last_of(".")};

            if (pathLocation == std::string::npos)
            {
                baseFileName = fullFileName;

                if (extensionLocation != std::string::npos)
                    fileExtension = fullFileName.substr(extensionLocation + 1);
            }
            else
            {
                relativePathToFile = fullFileName.substr(0, pathLocation);
                baseFileName = fullFileName.substr(pathLocation + 1);
                fileExtension = fullFileName.substr(extensionLocation + 1);
            }
        }

    public:
        explicit FileName(std::string_view FullFileName) { this->splitFileName(FullFileName); }

        std::string getBaseFileName() const { return baseFileName; }
        std::string getRelativePathToFile() const { return relativePathToFile; }
        std::string getFileExtension() const { return fileExtension; }
    };

    using FileNamePtr = std::shared_ptr<FileName>;


    class FileContents
    {
    private:
        std::vector<std::string> contentInFile;

        void setContentInFile(FileNamePtr FileName)
        {
            std::string fileName {FileName->getBaseFileName()};
            std::string relativePath {FileName->getRelativePathToFile()};

            std::ifstream inputFile { ((relativePath != "") ? relativePath + "/" : relativePath)
                + fileName };

            std::string line;

            if (inputFile.is_open())
            {
                while (getline(inputFile, line))
                    if (!line.empty())
                        contentInFile.push_back(line);

                inputFile.close();
            }
            else
                Errors::printFatalErrorMessage(1, "Unable to open file " + fileName);
        }

    public:
        explicit FileContents(FileNamePtr FileName) { this->setContentInFile(FileName); }

        std::vector<std::string> getContentInFile() { return contentInFile; }
    };

    using FileContentsPtr = std::shared_ptr<FileContents>;
}

#endif
