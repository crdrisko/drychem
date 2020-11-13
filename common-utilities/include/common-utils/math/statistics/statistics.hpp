// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: statistics.hpp
// Author: cdrisko
// Date: 02/03/2020-08:22:29
// Description: Common mathematical functions relating to statistics

#ifndef DRYCHEM_COMMON_UTILITIES_STATISTICS_HPP
#define DRYCHEM_COMMON_UTILITIES_STATISTICS_HPP

#include <algorithm>
#include <cmath>
#include <cstddef>
#include <iterator>
#include <numeric>
#include <type_traits>
#include <vector>

namespace CppUtils::Math
{
    /*!
     * Finds the order of magnitude of a given arithmetic value.
     *
     * \tparam T The type of the parameter \c value, must be an arithmetic type
     *
     * \param value The value we are trying to find the order of magnitude of
     */
    template<typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
    constexpr int findOrderOfMagnitude(T value) noexcept
    {
        return std::floor(std::log10(value));
    }


    /*!
     * Computes the absolute error in an expected value up to a certain amount of
     *  know significant digits.
     *
     * \tparam T The type of the parameter \c expectedValue, must be an arithmetic type
     *
     * \param expectedValue      The value we want to know the absolute error of
     * \param significantFigures The number of digits we know to be precise in \c expectedValue
     */
    template<typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
    constexpr long double findAbsoluteError(T expectedValue, std::size_t significantFigures) noexcept
    {
        return std::pow(10, findOrderOfMagnitude(expectedValue) - (significantFigures - 1));
    }


    /*!
     * Computes the average of a range of values specified by input iterators.
     *
     * \tparam Iterator The input iterator for the container we are iterating over
     * \tparam T        The type of the value the iterator points to, must be default constructible
     *
     * \param x_begin The beginning of the range we are iterating over
     * \param x_end   The end of the range we are iterating over
     */
    template<typename Iterator, typename T = typename std::iterator_traits<Iterator>::value_type,
             typename = std::enable_if_t<std::is_default_constructible_v<T>>>
    constexpr T calculateAverage(Iterator x_begin, Iterator x_end)
    {
        T init {};
        T result {std::accumulate(x_begin, x_end, init) / (x_end - x_begin)};

        return result;
    }


    /*!
     * Computes the variance from a range of values specified by input iterators from the
     *  following equation:
     *      \f$ \sigma^2 = \frac{1}{N - 1} \displaystyle \sum_{i = 0}^{N} (x_i - \bar x)^2.\f$
     *
     * \tparam Iterator The input iterator for the container we are iterating over
     * \tparam T        The type of the value the iterator points to, must be default constructible
     *
     * \param x_begin The beginning of the range we are iterating over
     * \param x_end   The end of the range we are iterating over
     */
    template<typename Iterator, typename T = typename std::iterator_traits<Iterator>::value_type,
             typename = std::enable_if_t<std::is_default_constructible_v<T>>>
    constexpr decltype(auto) calculateVariance(Iterator x_begin, Iterator x_end)
    {
        using Txx = decltype(*x_begin * *x_begin);

        std::ptrdiff_t x_size {x_end - x_begin};

        const Txx init {};
        T average {calculateAverage(x_begin, x_end)};

        std::vector<Txx> averageCorrectedValues(x_size);

        std::transform(x_begin, x_end, averageCorrectedValues.begin(),
            [&](auto x) { return (x - average) * (x - average); });

        Txx result = std::accumulate(averageCorrectedValues.begin(), averageCorrectedValues.end(), init) / (x_size - 1);

        return result;
    }
}   // namespace CppUtils::Math

#endif
