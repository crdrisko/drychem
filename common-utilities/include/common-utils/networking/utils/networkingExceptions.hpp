// Copyright (c) 2020-2021 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: networkingExceptions.hpp
// Author: crdrisko
// Date: 01/10/2021-11:39:53
// Description: Exception classes specifically made for errors that could arrise in networking-related functions

#ifndef DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_NETWORKING_UTILS_NETWORKINGEXCEPTIONS_HPP
#define DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_NETWORKING_UTILS_NETWORKINGEXCEPTIONS_HPP

#include <cstddef>
#include <string>

#include "common-utils/errors/exceptions/fatalException.hpp"
#include "common-utils/errors/utils/errorTypes.hpp"

namespace CppUtils::Networking
{
    /*!
     * An exception class used specifically for the networking libraries when one of the basic
     *  networking operations (open, close, send, etc.) fails.
     */
    class BasicNetworkingFailure : public Errors::FatalException
    {
    public:
        BasicNetworkingFailure(const std::string& basicOperationName_, const std::string& fileName_, std::size_t lineNumber_)
            : Errors::FatalException { Errors::ErrorMessage {"Common-Utilities", basicOperationName_ + "() failed.",
                fileName_, lineNumber_}}
        {
        }
    };

    /*!
     * An exception class used specifically for the networking libraries when a state specific operation
     *  of a network socket is called and the socket is already in that state.
     */
    class AlreadyInNetworkState : public Errors::FatalException
    {
    public:
        AlreadyInNetworkState(const std::string& stateName_, const std::string fileName_, std::size_t lineNumber_)
            : Errors::FatalException {Errors::ErrorMessage {"Common-Utilities", "Socket is already in the " + stateName_ + " state.",
                fileName_, lineNumber_}}
        {
        }
    };
}   // namespace CppUtils::Networking

#endif
