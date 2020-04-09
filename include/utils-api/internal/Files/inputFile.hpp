// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: inputFile.hpp - Version 1.0.0
// Author: cdrisko
// Date: 01/31/2020-15:39:06
// Description: An abstract class interface for representing different file types

#ifndef UTILITIES_API_INPUTFILE_HPP
#define UTILITIES_API_INPUTFILE_HPP

#include <fstream>
#include <memory>
#include <string>
#include <string_view>
#include <vector>

#include "fileComponents.hpp"
#include "../../errors.hpp"
#include "../../strings.hpp"

namespace Utilities_API::Files
{
    class InputFile
    {
    private:
        FileName fileName;
        FileContents fileContents;

        std::vector< std::vector<std::string> > splitDataVector(const std::vector<std::string>& dataVector,
            const std::string& separators = " \t\n")
        {
            std::vector< std::vector<std::string> > superVector;

            for (const auto& vec : dataVector)
                superVector.push_back( Strings::splitString(vec, separators) );

            return superVector;
        }

    protected:
        std::vector<std::string> dataVector;
        std::vector<std::string> metaDataVector;

        explicit InputFile(std::string_view FullFileName) : fileName{FullFileName}, fileContents{fileName}
        {
            try
            {
                std::ifstream testFile {fileName.getFullFileName(), std::ifstream::in};

                if (!testFile)
                    throw Errors::FileNotFoundException{"Utilities-API", FullFileName};
            }
            catch (const Errors::Exception& except)
            {
                except.handleErrorWithMessage();
            }
        }

    public:
        virtual ~InputFile() = default;
        virtual void separateFileData() = 0;

        FileName getFileName() const { return fileName; }
        FileContents getFileContents() const { return fileContents; }

        std::vector< std::vector<std::string> > getSuperDataVector(const std::string& separators = " \t\n")
        {
            return splitDataVector(dataVector, separators);
        }

        std::vector< std::vector<std::string> > getSuperMetaDataVector(const std::string& separators = " \t\n")
        {
            return splitDataVector(metaDataVector, separators);
        }
    };

    using InputFilePtr = std::shared_ptr<InputFile>;
}

#endif
