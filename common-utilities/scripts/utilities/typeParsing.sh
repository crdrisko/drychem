#!/bin/bash
# Copyright (c) 2020-2024 Cody R. Drisko. All rights reserved.
# Licensed under the MIT License. See the LICENSE file in the project root for more information.
#
# Name: typeParsing.sh - Version 1.1.0
# Author: crdrisko
# Date: 10/08/2020-09:43:53
# Description: Type-parsing functions to be sourced where needed, enhancing bash's type safety


### Functions ###
source errorHandling

ARRAY()         #@ DESCRIPTION: Parse an command line option as an array and return the variable
{               #@ USAGE: ARRAY VAR ['='] "$OPTARG"
    local __var=$1

    case $2 in
        '=') local __option="$3" ;;
          *) local __option="$2" ;;
    esac

    eval "$__var"+="( '$__option' )"
}

FILE()          #@ DESCRIPTION: Parse an command line option as a fileName and return the fileName and directory variables
{               #@ USAGE: FILE VARPREFIX ['='] "$OPTARG"
    local __filevar=${1}File
    local __dirvar=${1}Dir

    case $2 in
        '=') local __option="$3" ;;
          *) local __option="$2" ;;
    esac

    printf -v "$__filevar" "%s" "${__option##*/}"

    if [[ "${__option##*/}" != "${__option%/*}" ]]
    then
        printf -v "$__dirvar"  "%s" "${__option%/*}"
    else
        printf -v "$__dirvar" "%s" "$PWD"
    fi
}

INT()           #@ DESCRIPTION: Parse an command line option as an integer and return the variable
{               #@ USAGE: INT VAR ['='] "$OPTARG"
    local __var=$1

    case $2 in
        '=') local __option="$3" ;;
          *) local __option="$2" ;;
    esac

    case $__option in
        *[!0-9]*) printFatalErrorMessage 2 "Option passed to the $__var variable must be an integer." ;;
               *) printf -v "$__var" "%d" "$__option" ;;
    esac
}

STRING()        #@ DESCRIPTION: Parse an command line option as an string and return the variable
{               #@ USAGE: STRING VAR ['='] "$OPTARG"
    local __var=$1

    case $2 in
        '=') local __option="$3" ;;
          *) local __option="$2" ;;
    esac

    printf -v "$__var" "%s" "$__option"
}
