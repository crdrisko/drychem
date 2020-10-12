#!/bin/bash
# Copyright (c) 2020 Cody R. Drisko. All rights reserved.
# Licensed under the MIT License. See the LICENSE file in the project root for more information.
#
# Name: compiler.sh - Version 1.2.1
# Author: crdrisko
# Date: 01/31/2020-14:46:06
# Description: Collects the .cpp files in a directory and compiles them using g++


### Functions ###
source errorHandling
source typeParsing

printHelpMessage()      #@ DESCRIPTION: Print the compiler program's help message
{                       #@ USAGE: printHelpMessage
    printf "\nUSAGE: compiler [-hvr] [-o FILE] [-i ARRAY] [-V INT]\n\n"
    printf "  -h  Prints help information about the compiler program.\n"
    printf "  -v  Verbose mode. Defaults to false/off.\n"
    printf "  -r  Run the program after compilation. Defaults to false/off.\n\n"
    printf "  -o  REQUIRED: Output file, must be a .out file or error message occurs.\n"
    printf "  -i  OPTIONAL: Input files or directory for additional .cpp files.\n"
    printf "  -V  OPTIONAL: C++ version to run. Defaults to C++17.\n\n"
    printf "EXAMPLE: compiler -i ../example.cpp -o example.out -V 20\n\n"
}

validateVersion()       #@ DESCRIPTION: Checks entered C++ version against released versions
{                       #@ USAGE: validateVersion INT
    case $1 in
        98) return 0 ;;  03) return 0 ;;  11) return 0 ;;
        14) return 0 ;;  17) return 0 ;;  20) return 0 ;;
         *) printFatalErrorMessage 1 "Invalid C++ standard specified." ;;
    esac
}

compileAndRun()         #@ DESCRIPTION: Compile and run the given C++ source code
{                       #@ USAGE: compileAndRun
    [[ -e $outputFile ]] && rm "$outputFile"                ## Don't run old output files

    g++ "${files[@]}" -o "$outputFile" -std=c++"$version"

    [[ $run -eq 1 ]] && ./"$outputFile"
}


### Initial Variables / Default Values ###
declare -a inputFiles files
declare outputFile outputDir run verbose version

run=0
verbose=0
version=17


### Runtime Configuration ###
while getopts o:i:V:rvh opt
do
    case $opt in
        o) FILE  output     = "$OPTARG" ;;                  ## Returns outputFile and outputDir variables
        i) ARRAY inputFiles = "$OPTARG" ;;
        V) INT   version    = "$OPTARG" ;;
        r) run=1 ;;
        v) export verbose=1 ;;
        h) printHelpMessage && printFatalErrorMessage 0 ;;
        *) printFatalErrorMessage 1 "Invalid option flag passed to program." ;;
    esac
done


### Main Code ###
if [[ -d "$outputDir" ]]
then
    cd "$outputDir" || printFatalErrorMessage 2 "Could not change into required directory."

    validateVersion $version

    [[ ${outputFile:?An output file is required} ]]

    case ${outputFile#*.} in
        o|out)  for file in *.cpp
                do
                    files+=( "$file" )                      ## All files in output directory...
                done

                files+=( "${inputFiles[@]}" )               ## ...plus those indicated as input parameters

                compileAndRun ;;
            *) printFatalErrorMessage 3 "Output file, $outputFile, is invalid." ;;
    esac
else
    printFatalErrorMessage 4 "Invalid directory."
fi
