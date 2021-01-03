// Copyright (c) 2020-2021 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: test.cpp
// Author: crdrisko
// Date: 11/21/2020-06:52:54
// Description:

#include <iostream>
#include <string>
#include <tuple>

#include "apply_n.hpp"
#include "select.hpp"

int main()
{
    std::tuple tup {"Hello, World!", 12.3, 6, std::string {"A string"}};

    std::apply([&](auto... elem) { ((std::cout << elem << std::endl), ...); }, tup);

    CppUtils::Tuples::apply_n<2>([&](auto... elem) { ((std::cout << elem << std::endl), ...); }, tup);
}
