#!/bin/bash
# Copyright (c) 2020 Cody R. Drisko. All rights reserved.
# Licensed under the MIT License. See the LICENSE file in the project root for more information.
#
# Name: errorHandling.sh - Version 1.0.1
# Author: cdrisko
# Date: 01/31/2020-14:46:26
# Description: Error handling functions to be sourced where needed


### Functions ###
printNonFatalErrorMessage()     #@ DESCRIPTION: Print message to standard error
{                               #@ USAGE: printNonFatalErrorMessage MESSAGE
    errorMessage="${1:?An error message is required}"

    if [[ -n "$errorMessage" ]]
    then
        printf "%s\n" "$errorMessage" >&2
    fi
}

printFatalErrorMessage()        #@ DESCRIPTION: Exit the program with optional message
{                               #@ USAGE: printFatalErrorMessage INT [MESSAGE]
    if [[ ${verbose:=0} -eq 1 && ${1:?An exit code is required} -eq 0 ]]
    then
        printf "Program terminated normally.\n"
    elif [[ $verbose -eq 1 && $1 -ne 0 ]]
    then
        printf "Program terminated abnormally with exit code %d.\n" "$1"
    fi

    [[ -n "$2" ]] && printNonFatalErrorMessage "$2"

    exit "$1"
}
