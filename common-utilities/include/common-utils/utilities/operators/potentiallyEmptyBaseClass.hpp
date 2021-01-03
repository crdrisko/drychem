// Copyright (c) 2020-2021 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: potentiallyEmptyBaseClass.hpp
// Author: crdrisko
// Date: 09/18/2020-08:53:09
// Description: An empty base class to be used with other operators and/or operations

#ifndef DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_UTILITIES_OPERATORS_POTENTIALLYEMPTYBASECLASS_HPP
#define DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_UTILITIES_OPERATORS_POTENTIALLYEMPTYBASECLASS_HPP

namespace CppUtils::Operators
{
    /*!
     * An empty class we can use with our other operators or traits so we don't inhibit the EBCO.
     *
     * \tparam (unnamed) A template parameter that allows us to make use of the curiously recurring
     *                   template pattern (CRTP) with our operators
     *
     * \note If we happen to inherit one of our operator classes but the required conditions aren't satisfied, or
     *  the class is SFINAE'd away, we don't want to be left holding the (non-empty) bag. Thus, we can make use
     *  of the Empty Base Class Optimization (EBCO) in all our operator classes to avoid these issues.
     */
    template<typename>
    class PotentiallyEmptyBaseClass
    {
    };
}   // namespace CppUtils::Operators

#endif
