// Copyright (c) 2020-2025 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: performanceTesting.hpp
// Author: crdrisko
// Date: 10/20/2020-12:09:44
// Description: A function that can be used to time other functions

#ifndef DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_UTILITIES_TESTING_PERFORMANCETESTING_HPP
#define DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_UTILITIES_TESTING_PERFORMANCETESTING_HPP

#include <chrono>
#include <functional>
#include <type_traits>
#include <utility>

namespace CppUtils::Testing
{
    namespace details
    {
        /*! 
         * An aggregate structure that can be used as the return type of the \c timeAndInvoke<>() 
         *  function template.
         * 
         * \tparam        F - The type of the function we are calling
         * \tparam ...TArgs - The types of the arguments passed to the function f
         * 
         * \note We hide the return type in the \c details namespace so the user is encouraged to use
         *       structured binding as the way to return from \c timeAndInvoke<>().
         */
        template<typename F, typename... TArgs>
        struct ReturnType
        {
            std::invoke_result_t<F, TArgs...> result;
            std::chrono::microseconds::rep time;
        };
    }   // namespace details

    /*!
     * A function that invokes another function and times how long it took to invoke said function.
     *
     * \tparam        F - The type of the function we are calling
     * \tparam ...TArgs - The types of the arguments passed to the function f
     *
     * \param    f - The function to invoke
     * \param args - The parameters of the function we are invoking
     *
     * \returns Because we have two different pieces of information to return, the result of the invoked
     *          function (unless it is a void function) and the time it took to invoke the function, we
     *          return an object of the \c detatils::ReturnType struct. The preferred way to collect this information
     *          is through structured binding.
     */
    template<typename F, typename... TArgs>
    constexpr decltype(auto) timeAndInvoke(F&& f, TArgs&&... args)
    {
        //! Need to handle `void f(args...)` case differently from `auto f(args...)` case
        if constexpr (std::is_void_v<std::invoke_result_t<F, TArgs...>>)
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

            return details::ReturnType<F, TArgs...> {result, duration};
        }
    }
}   // namespace CppUtils::Testing

#endif
