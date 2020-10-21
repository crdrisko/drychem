// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: comparableExample.cpp
// Author: crdrisko
// Date: 09/22/2020-09:06:16
// Description: An example of how to use the CompletelyComparable<> class template when comparing fruits

#include <algorithm>
#include <cctype>
#include <cstddef>
#include <functional>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

#include <common-utils/utilities.hpp>

using namespace CppUtils::Operators;

class Fruit : private CompletelyComparable<Fruit>   // Private inheritance for an 'implements a' relationship
{
private:
    std::string name;
    int rank;

public:
    enum class Rankings { Worst, PrettyGood, Great, Best };

    Fruit(std::string_view Name, Rankings Rank) noexcept : name {Name}, rank {static_cast<int>(Rank)} {}

    friend bool operator==(const Fruit& lhs, const Fruit& rhs) noexcept { return lhs.rank == rhs.rank; }
    friend bool operator<(const Fruit& lhs, const Fruit& rhs) noexcept { return lhs.rank < rhs.rank; }

    std::string getName() const { return name; }
};

void printFruitComparisons(const std::vector<Fruit>& commonFruits);

int main()
{
    Fruit apple      {"Apple",      Fruit::Rankings::Great};
    Fruit banana     {"Banana",     Fruit::Rankings::PrettyGood};
    Fruit orange     {"Orange",     Fruit::Rankings::PrettyGood};
    Fruit pear       {"Pear",       Fruit::Rankings::Best};
    Fruit watermelon {"Watermelon", Fruit::Rankings::Worst};

    std::vector<Fruit> commonFruits {apple, banana, orange, pear, watermelon};

    std::sort(commonFruits.begin(), commonFruits.end());
    printFruitComparisons(commonFruits);

    std::cout << std::endl;

    std::sort(commonFruits.begin(), commonFruits.end(), std::greater<Fruit>());
    printFruitComparisons(commonFruits);
}

void printFruitComparisons(const std::vector<Fruit>& commonFruits)
{
    for (std::size_t i {}; i < commonFruits.size(); ++i)
    {
        std::string fruitPrefix;
        Fruit currentFruit = commonFruits[i];

        switch (std::tolower(currentFruit.getName()[0]))
        {
        case 'a': case 'e': case 'i': case 'o': case 'u':
            fruitPrefix = "an";
            break;
        default:
            fruitPrefix = "a";
            break;
        }

        if (i != 0)
        {
            Fruit previousFruit = commonFruits[i - 1];

            if (previousFruit == currentFruit)
                std::cout << " is as good as ";
            else if (previousFruit > currentFruit)
                std::cout << " is better than ";
            else
                std::cout << " is worse than ";

            std::cout << fruitPrefix << ' ';
        }
        else
            std::cout << static_cast<char>(std::toupper(fruitPrefix[0])) << ' ';

        std::cout << currentFruit.getName();

        if (i != 0 && i != commonFruits.size() - 1)
            std::cout << ", which";
    }

    std::cout << std::endl;
}
