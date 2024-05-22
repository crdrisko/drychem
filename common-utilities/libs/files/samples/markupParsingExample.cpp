// Copyright (c) 2020-2024 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: markupParsingExample.cpp
// Author: crdrisko
// Date: 01/16/2021-08:39:31
// Description: An example of how to define your own file parser for simple markup-style files

#include <cstddef>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include <common-utils/files.hpp>

namespace fs = std::filesystem;

void createOutputFile(const fs::path& fileName);

class SimpleMarkupStrategy
{
private:
    std::unordered_map<std::string, std::vector<std::string>> fileData;

public:
    auto operator()(const std::string& fileContents_)
    {
        DryChem::AsRows rowParser {};
        std::vector<std::string> rows {rowParser(fileContents_)};

        std::vector<std::string> tags {"meta", "data"};

        for (std::size_t i {}; i < rows.size(); ++i)
        {
            for (const auto& tag : tags)
            {
                if (rows[i] == std::string {"<" + tag + ">"})
                {
                    std::size_t j {i + 1};

                    while (rows[j] != std::string {"</" + tag + ">"})
                        fileData[tag].push_back(rows[j++]);

                    i = j;
                }
            }
        }

        return fileData;
    }
};

int main()
{
    fs::path fileName {"out.csv"};

    createOutputFile(fileName);

    DryChem::FileParser parser {fileName};
    SimpleMarkupStrategy markupParser {};

    auto fileData = parser.parseDataFile(markupParser);

    // Print the meta data
    std::cout << "The meta data portion of the file is as follows:\n";

    std::size_t counter = 1;

    for (const auto& str : fileData["meta"])
        std::cout << counter++ << ") " << str << '\n';

    std::cout << std::endl;

    // Print the actual data
    std::cout << "The data portion of the file is as follows:\n";

    counter = 1;

    for (const auto& str : fileData["data"])
        std::cout << counter++ << ") " << str << '\n';

    std::cout << std::endl;
}

void createOutputFile(const fs::path& fileName)
{
    std::ofstream outFile {fileName};

    outFile << "<meta>\n";
    outFile << "\tThis is an example file for a simple markup-style file.\n";
    outFile << "\tEach of these lines belongs in the <meta> portion of the file.\n";
    outFile << "</meta>\n";

    outFile << "<data>\n";
    outFile << "\tWhile any lines in this section belong to the <data> portion of the file.\n";
    outFile << "</data>\n";
}
