#!/bin/bash
# Copyright (c) 2020 Cody R. Drisko. All rights reserved.
# Licensed under the MIT License. See the LICENSE file in the project root for more information.
#
# Name: compiler.sh - Version 1.0.1
# Author: crdrisko
# Date: 01/31/2020-14:46:06
# Description: Collects the .cpp files in a directory and compiles them using g++


### Functions ###
source errorHandling

printHelpMessage()      #@ DESCRIPTION: Print the compiler program's help message
{                       #@ USAGE: printHelpMessage
    printf "\nUSAGE: compiler [-hvdr] [-o outputFile] [-i inputFile] [-l library] [-V Version]\n\n"
    printf "  -h  Prints help information about the compiler program.\n"
    printf "  -v  Verbose mode. Defaults to false/off.\n"
    printf "  -d  Enter into debug mode. Defaults to false/off.\n"
    printf "  -r  Run the program after compilation. Defaults to false/off.\n\n"
    printf "  -o  REQUIRED: Output file, must be a .out file or error message occurs.\n"
    printf "  -i  OPTIONAL: Input files or directory for additional .cpp files.\n"
    printf "  -l  OPTIONAL: Compiled libraries to include with source code.\n"
    printf "  -V  OPTIONAL: C++ version to run. Defaults to C++17.\n\n"
    printf "EXAMPLE: compiler -i ../example.cpp -o example.out -V 20\n\n"
}

validVersion()		    #@ DESCRIPTION: Checks entered C++ version against released versions
{					    #@ USAGE: validVersion INT
    case $1 in
        98) return 0 ;;  03) return 0 ;;  11) return 0 ;;
        14) return 0 ;;  17) return 0 ;;  20) return 0 ;;
         *) printNonFatalErrorMessage "Invalid version, C++17 used."
            return 1 ;;
    esac
}

compileAndRun()         #@ DESCRIPTION: Compile and run the given C++ source code
{                       #@ USAGE: compileAndRun [ADDITIONAL_ARGUMENTS]
    additionalArguments+=( $1 )

    ## Eliminate possibility for failed compilation to still run old output file ##
    [[ -e $outputFile ]] && rm "$outputFile"

    g++ "${files[@]}" -o "$outputFile" "${libraries[@]}" -std=c++"$version" "${additionalArguments[@]}"

    [[ $run -eq 1 ]] && ./"$outputFile"
}


### Initial Variables / Default Values ###
declare -a inputFiles libraries
version=17
verbose=0
debug=0
run=0


### Runtime Configuration ###
while getopts o:i:l:V:drvh opt
do
    case $opt in
        o) outputFile=$OPTARG ;;
        i) inputFiles+=( $OPTARG ) ;;
        l) libraries+=( "-l"$OPTARG ) ;;
        V) if validVersion "$OPTARG"
           then
               version=$OPTARG
           fi ;;
        d) debug=1 ;;
        r) run=1 ;;
        v) export verbose=1 ;;
        h) printHelpMessage && printFatalErrorMessage 0 ;;
        *) printFatalErrorMessage 1 "Invalid option flag passed to program." ;;
    esac
done


### Main Code ###
declare -a files

## Proper output file specified ##
if [[ ${outputFile:?An output file is required} && ${outputFile#*.} = out ]]
then
    for file in *.cpp
    do
        files+=( "$file" )                      ## All files in current working directory...
    done

    files+=( "${inputFiles[@]}" )               ## ...plus those indicated as input parameters

    ## Threading option required for googletest on linux machines ##
    for library in "${libraries[@]}"
    do
        if [[ ${library##*"-l"} = gtest && $OSTYPE == linux* ]]
        then
            additionalArguments+=( -pthread )
        fi
    done

    ## Raspberry Pi's g++ compiler raises unnecessary warnings by default ##
    [[ $OSTYPE = linux-gnueabihf ]] && additionalArguments+=( -Wno-psabi )

    if [ $debug -eq 0 ]
    then
        ## Normal compilation without debugging ##
        [ $debug -eq 0 ] && compileAndRun && exit
    else
        ## Debug mode - show input files used in compilation ##
        set -x
        compileAndRun -g
        set +x

        read -rsn1 -p "Continue with debugging (y/n)? "
        case $REPLY in
            y|Y) if [[ $OSTYPE == linux* ]]
                 then
                     gdb "$outputFile"		    ## Debugger installed on linux
                 else
                     lldb "$outputFile"		    ## Debugger installed on Mac
                 fi ;;
            n|N) echo && printFatalErrorMessage 2 ;;
              *) printFatalErrorMessage 3 "Sorry, that wasn't one of the options." ;;
        esac
    fi
else
    printFatalErrorMessage 4 "Output file, $outputFile, is invalid."
fi
