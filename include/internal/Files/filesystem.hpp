// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: filesystem.hpp - Version 1.0.0
// Author: cdrisko
// Date: 02/13/2020-09:54:34
// Description: Use the STL filesystem libraries if the compiler supports them

#ifndef UTILITIES_API_FILESYSTEM_HPP
#define UTILITIES_API_FILESYSTEM_HPP

#include <fstream>

#ifdef __cpp_lib_filesystem
    #define HAS_STD_FILESYSTEM_SUPPORT 1
    #include <filesystem>

    namespace fs = std::filesystem;

#elif __cpp_lib_experimental_filesystem
    #define HAS_STD_FILESYSTEM_SUPPORT 1
    #include <experimental/filesystem>

    namespace fs = std::experimental::filesystem;
#else
    #define HAS_STD_FILESYSTEM_SUPPORT 0

    namespace fs 
    {
        bool is_regular_file(const std::string& fullFileName)
        {
            std::ifstream testFile { fullFileName };

            if ( testFile.is_open() )
            {
                testFile.close();
                return true;
            }

            return false;
        }
    }
#endif

#endif
