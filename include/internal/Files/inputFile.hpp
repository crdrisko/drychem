// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: inputFile.hpp - Version 1.0.0
// Author: cdrisko
// Date: 01/31/2020-15:39:06
// Description: An abstract class interface for representing different file types

#ifndef UTILITIES_API_INPUTFILE_HPP
#define UTILITIES_API_INPUTFILE_HPP

#include <memory>
#include <string>
#include <string_view>
#include <vector>

#include "fileComponents.hpp"
#include "../Errors/errorUtilities.hpp"
#include "../Strings/stringUtilities.hpp"

namespace Utilities_API::Files
{
    class InputFile
    {
    private:
        FileName fileName;
        FileContents fileContents;
        Errors::ErrorMessagePtr errorMessage;

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
        explicit InputFile(std::string_view FullFileName) : fileName{FullFileName}, fileContents{fileName}
        {
            std::ifstream testFile { fileName.getFullFileName() };

            if (testFile)
            {
                errorMessage = std::make_shared<Errors::FatalErrorMessage>("Utilities-API", 2);
                errorMessage->printErrorMessage("File name provided is not a valid file.");
            }
        }

        virtual ~InputFile() = default;
        virtual void separateFileData() = 0;

        FileName getFileName() const { return fileName; }
        FileContents getFileContents() const { return fileContents; }

        std::vector< std::vector<std::string> > getSuperDataVector(std::string separators = " \t\n")
        {
            return splitDataVector(dataVector, separators);
        }

        std::vector< std::vector<std::string> > getSuperMetaDataVector(std::string separators = " \t\n")
        {
            return splitDataVector(metaDataVector, separators);
        }
    };

    using InputFilePtr = std::shared_ptr<InputFile>;
}

#endif
