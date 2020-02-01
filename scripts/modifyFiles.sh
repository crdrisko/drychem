#!/bin/bash
# Copyright (c) 2020 Cody R. Drisko. All rights reserved.
# Licensed under the MIT License. See the LICENSE file in the project root for license information.
#
# Name: modifyFiles.sh - Version 1.0.0
# Author: crdrisko
# Date: 01/31/2020-14:45:36
# Description: Modify a file using a wrapper for sed


### Functions ###
source errorHandling

printHelpMessage()      #@ DESCRIPTION: Print the modifyFiles program's help message
{                       #@ USAGE: printHelpMessage
  printf "\nUSAGE: modifyFiles [-hvf] [-i fileName] [-o oldString] [-n newString]\n\n"
  printf "  -h  Prints help information about the modifyFiles program.\n"
  printf "  -v  Verbose mode. Defaults to false/off.\n"
  printf "  -f  Only replace the first instance of a word. Defaults to false/off.\n\n"
  printf "  -i  REQUIRED: Input file to be changed.\n"
  printf "  -o  REQUIRED: Old string you wish to replace.\n"
  printf "  -n  REQUIRED: New string to replace the old string.\n\n"
  printf "EXAMPLE: modifyFiles -i fileName -o oldString -n newString -f\n\n"
}


### Initial Variables / Default Values ###
firstInstance=0
verbose=0


### Runtime Configuration ###
while getopts i:o:n:fvh opt
do
  case $opt in
    i) fileName=$OPTARG ;;
    o) oldString=$OPTARG ;;
    n) newString=$OPTARG ;;
    f) firstInstance=1 ;;
    v) verbose=1 ;;
    h) printHelpMessage && printFatalErrorMessage 0 ;;
  esac
done


### Main Code ###
if [ $firstInstance -eq 1 ]
then
  sed -e "1s/${oldString?}/${newString?}/;t" -e "1,/${oldString?}/s//${newString?}/"\
      ${fileName?} > tempFile && mv tempFile ${fileName?}
else
  sed "s/${oldString?}/${newString?}/g" ${fileName?} > tempFile && mv tempFile ${fileName?}
fi
