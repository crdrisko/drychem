#!/bin/bash
# Copyright (c) 2020 Cody R. Drisko. All rights reserved.
# Licensed under the MIT License. See the LICENSE file in the project root for more information.
#
# Name: remover.sh - Version 1.1.0
# Author: crdrisko
# Date: 01/31/2020-14:45:40
# Description: Remove all files containing the same fileName or extension


### Functions ###
source errorHandling
source typeParsing

printHelpMessage()      #@ DESCRIPTION: Print the remover program's help message
{                       #@ USAGE: printHelpMessage
    printf "\nUSAGE: remover [-hvse] [-w STRING]\n\n"
    printf "  -h  Prints help information about the remover program.\n"
    printf "  -v  Verbose mode. Defaults to false/off.\n"
    printf "  -s  Indicates the word to remove is the filename.\n"
    printf "  -e  Indicates the word to remove is the file extension.\n\n"
    printf "  -w  REQUIRED: Word to remove at start or end of the filename.\n\n"
    printf "EXAMPLE: remover -e -w txt\n\n"
}

rmStart()               #@ DESCRIPTION: Remove all files starting with $1
{                       #@ USAGE: rmStart word
    printf "CONFIRM: Delete all files starting with %s? (y/n) " "$1"
    read -rsn1
    case $REPLY in
        y|Y) printf "Confirmed.\n"
             for file in "${1?}"*
             do
                 rm "$file"
             done ;;
        n|N) printFatalErrorMessage 2 "Exiting." ;;
          *) printFatalErrorMessage 3 "Not a valid option." ;;
    esac
}

rmEnd()                 #@ DESCRIPTION: Remove all files ending with $1
{                       #@ USAGE: rmEnd word
    printf "CONFIRM: Delete all files ending with %s? (y/n) " "$1"
    read -rsn1
    case $REPLY in
        y|Y) printf "Confirmed.\n"
             for file in *"${1?}"
             do
                 rm "$file"
             done ;;
        n|N) printFatalErrorMessage 2 "Exiting." ;;
          *) printFatalErrorMessage 3 "Not a valid option." ;;
    esac
}


### Initial Variables / Default Values ###
declare end start verbose word

start=0
end=0
verbose=0


### Runtime Configuration ###
while getopts w:sevh opt
do
    case $opt in
        w) STRING word = "$OPTARG" ;;
        s) start=1 ;;
        e) end=1 ;;
        v) export verbose=1 ;;
        h) printHelpMessage && printFatalErrorMessage 0 ;;
        *) printFatalErrorMessage 1 "Invalid option flag passed to program." ;;
    esac
done


### Main Code ###
if [[ $start -eq 1 && $end -eq 0 ]]
then
    rmStart "${word:?Word must be set}"
elif [[ $end -eq 1 && $start -eq 0 ]]
then
    rmEnd "${word:?Word must be set}"
else
    printFatalErrorMessage 4 "One and only one start/end option must be set.\n"
fi
