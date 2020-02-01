#!/bin/bash
# Copyright (c) 2020 Cody R. Drisko. All rights reserved.
# Licensed under the MIT License. See the LICENSE file in the project root for license information.
#
# Name: getVersions.sh - Version 1.0.0
# Author: cdrisko
# Date: 02/01/2020-11:52:58
# Description: Print versions of the compiler, operating systems, and cmake during build


## Compiler Version Information ##
printf "Compiler Information: (Compiler used is shown during build with cmake) \n"
if which g++ &>/dev/null
then
  printf "  - g++ Version:\n"
  g++ -v
fi

if which clang++ &>/dev/null
then
  printf "\n  - clang++ Version:\n"
  clang++ -v
fi


## CMake Version Information ##
cmake=( $( cmake --version | grep version ) )

printf "\nCMake Information:\n"
printf "\tCMake Version: %s\n" "${cmake[2]}"


## Operating System Version Information ##
kernalName=$( uname -s )
kernalRelease=$( uname -r )
machineHardware=$( uname -m )
architecture=$( arch )

printf "\nOperating System Information:\n"
printf "\tKernal Name: %s\n" "$kernalName"
printf "\tKernal Release: %s\n" "$kernalRelease"
printf "\tMachine Hardware: %s\n" "$machineHardware"
printf "\tProcessor: %s\n" "$architecture"
