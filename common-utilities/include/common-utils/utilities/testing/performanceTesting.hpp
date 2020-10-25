// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: performanceTesting.hpp
// Author: crdrisko
// Date: 10/20/2020-12:09:44
// Description: A function that can be used to time other functions

#ifndef COMMON_UTILITIES_PERFORMANCETESTING_HPP
#define COMMON_UTILITIES_PERFORMANCETESTING_HPP

#include <chrono>
#include <functional>
#include <type_traits>
#include <utility>

namespace CppUtils::Testing
{
    // An aggregate structure that can be used as the return type of the timeAndInvoke<>() function template
    template<class F, class... TArgs>
    struct ReturnType
    {
        std::invoke_result_t<F, TArgs...> result;
        std::chrono::microseconds::rep time;
    };


    template<class F, class... TArgs>
    constexpr decltype(auto) timeAndInvoke(F&& f, TArgs&&... args)
    {
        // Need to handle `void f(args...)` case differently from `auto f(args...)` case
        if constexpr (std::is_same_v<std::invoke_result_t<F, TArgs...>, void>)
        {
            auto start = std::chrono::high_resolution_clock::now();
            std::invoke(std::forward<F>(f), std::forward<TArgs>(args)...);
            auto end = std::chrono::high_resolution_clock::now();

            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

            return duration;
        }
        else
        {
            auto start  = std::chrono::high_resolution_clock::now();
            auto result = std::invoke(std::forward<F>(f), std::forward<TArgs>(args)...);
            auto end    = std::chrono::high_resolution_clock::now();

            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

            return ReturnType<F, TArgs...> {result, duration};
        }
    }
}   // namespace CppUtils::Testing

#endif
