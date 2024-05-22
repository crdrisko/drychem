// Copyright (c) 2020-2024 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: fileDetails.hpp
// Author: crdrisko
// Date: 12/30/2020-08:58:21
// Description: Details to be used with the testing of the files library

#ifndef DRYCHEM_COMMON_UTILITIES_LIBS_FILES_TESTS_DETAILS_FILEDETAILS_HPP
#define DRYCHEM_COMMON_UTILITIES_LIBS_FILES_TESTS_DETAILS_FILEDETAILS_HPP

#include <cstddef>
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

namespace CppUtils::Files::details::testing
{
    void createOutputFile(const fs::path& fileName, char separator)
    {
        std::ofstream outFile {fileName};

        for (std::size_t i {1}; i < 13; ++i)
        {
            outFile << i;

            if (i % 3 == 0)
                outFile << '\n';
            else
                outFile << separator;
        }
    }
}   // namespace CppUtils::Files::details::testing

#endif
