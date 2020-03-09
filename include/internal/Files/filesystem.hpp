// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: filesystem.hpp - Version 1.0.0
// Author: cdrisko
// Date: 02/13/2020-09:54:34
// Description: Use the Standard Library filesystem libraries if the compiler supports them

#ifndef UTILITIES_API_FILESYSTEM_HPP
#define UTILITIES_API_FILESYSTEM_HPP

#ifdef __cpp_lib_filesystem
    #include <filesystem>

    namespace fs = std::filesystem;

#elif __cpp_lib_experimental_filesystem
    #include <experimental/filesystem>

    namespace fs = std::experimental::filesystem;

#else
    #include <fstream>
    #include <string_view>

    namespace fs
    {
        inline bool is_regular_file(std::string_view fullFileName)
        {
            std::ifstream testFile { fullFileName };

            return (testFile) ? true : false;
        }
    }
#endif

#endif
