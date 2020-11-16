// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: ciTokenizerExample.cpp
// Author: crdrisko
// Date: 11/14/2020-07:35:01
// Description: An example of how to use the strings library when sorting a string without regard to case

#include <cstddef>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include <common-utils/strings.hpp>

// Function prototypes
std::map<DryChem::ci_string, std::size_t> ci_sort(const std::vector<std::string>& words, std::size_t& lengthLongestWord);
void printWords(const std::map<DryChem::ci_string, std::size_t>& ci_words, std::size_t lengthLongestWord);

int main()
{
    std::string input, punctuation {"-.,?!'\":; \t\n"};
    std::cout << "Enter some text to be parsed terminated by the '*' character: \n";
    std::getline(std::cin, input, '*');

    DryChem::Tokenizer tok {input, punctuation};

    std::size_t lengthLongestWord {};
    auto ci_words = ci_sort(tok.split(), lengthLongestWord);

    printWords(ci_words, lengthLongestWord);
}

// Function definitions
std::map<DryChem::ci_string, std::size_t> ci_sort(const std::vector<std::string>& words, std::size_t& lengthLongestWord)
{
    std::map<DryChem::ci_string, std::size_t> ci_wordMap;

    for (const auto& word : words)
    {
        if (word.length() > lengthLongestWord)
            lengthLongestWord = word.length();

        ++ci_wordMap[DryChem::traits_cast<DryChem::ci_char_traits>(word)];
    }

    return ci_wordMap;
}

void printWords(const std::map<DryChem::ci_string, std::size_t>& ci_words, std::size_t lengthLongestWord)
{
    int counter {};

    std::cout << "The words you entered in (case-insensitive) sorted order are: \n";

    for (const auto& [word, count] : ci_words)
    {
        std::string temp = DryChem::traits_cast<std::char_traits<char>>(word)
                           + std::string {(count > 1 ? " (x" + std::to_string(count) + ")" : "")};

        std::cout << std::setw(lengthLongestWord + 5) << std::move(temp);

        if (++counter % 5 == 0)
        {
            std::cout << std::endl;
            counter = 0;
        }
    }

    std::cout << std::endl;
}
