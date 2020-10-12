#!/bin/bash
# Copyright (c) 2020 Cody R. Drisko. All rights reserved.
# Licensed under the MIT License. See the LICENSE file in the project root for more information.
#
# Name: fileMaker.sh - Version 1.2.0
# Author: cdrisko
# Date: 01/31/2020-14:45:20
# Description: Creates new files based off simple, pre-defined templates


### Functions ###
source errorHandling
source typeParsing

printHelpMessage()          #@ DESCRIPTION: Print the fileMaker program's help message
{                           #@ USAGE: printHelpMessage
    printf "\nUSAGE: fileMaker [-hvc] [-i FILE]\n\n"
    printf "  -h  Prints help information about the fileMaker program.\n"
    printf "  -v  Verbose mode. Defaults to false/off.\n"
    printf "  -c  Print copyright header in source code. Defaults to false/off.\n\n"
    printf "  -i  REQUIRED: Either a .cpp, .hpp, .py, or .sh input file.\n\n"
    printf "EXAMPLE: fileMaker -i exampleFile.cpp -c\n\n"
}

generateCopyrightHeader()   #@ DESCRIPTION: Search for LICENSCE file and print copyright header if found
{                           #@ USAGE: generateCopyrightHeader
    licenseDirectory="$PWD"
    previousDirectory="$PWD"

    while ! [ -f "LICENSE" ]
    do
        cd ../
        licenseDirectory="$PWD"

        if [ "$licenseDirectory" == '/' ]
        then
            printNonFatalErrorMessage "LICENSE file not found."
            cd "$previousDirectory" || printFatalErrorMessage 2 "Could not change into required directory."
            return
        fi
    done

    cd "$previousDirectory" || printFatalErrorMessage 2 "Could not change into required directory."

    copyright=$( grep Copyright\ \(c\) "$licenseDirectory"/LICENSE )
    rights=$( grep -i rights\ reserved "$licenseDirectory"/LICENSE )
    licenseType=$( grep -w License "$licenseDirectory"/LICENSE )

    if [[ "$licenseType" == "$rights" ]]
    then
        rights="${licenseType##*', '}"
        licenseType="${licenseType%%', '*}"
    fi

    printf "%s %s. %s.\n" "$commentType" "$copyright" "${rights:-All rights reserved}"

    if [[ -z $licenseType ]]
    then
        printf "%s" "$commentType"
    else
        printf "%s Licensed under the %s License." "$commentType" "${licenseType%%\ License*}"
    fi

    printf " See the LICENSE file in the project root for more information.\n"
    printf "%s\n" "$commentType"
}


### Initial Variables / Default Values ###
declare commentType copyright inputDir inputFile verbose

commentType="//"
copyright=0
verbose=0


### Runtime Configuration ###
while getopts i:cvh opt
do
    case $opt in
        i) FILE input = "${OPTARG}" ;;                      ## Returns inputFile and inputDir variables
        c) copyright=1 ;;
        v) export verbose=1 ;;
        h) printHelpMessage && printFatalErrorMessage 0 ;;
        *) printFatalErrorMessage 1 "Invalid option flag passed to program." ;;
    esac
done


### Main Code ###
if [[ -d "$inputDir" ]]
then
    cd "$inputDir" || printFatalErrorMessage 2 "Could not change into required directory."

    [[ -e ${inputFile:?Input file is required} ]] && printFatalErrorMessage 3 "Sorry that file already exists."

    ## Switch on file extension ##
    case $inputFile in
        *".cpp")
            printf -v firstLine "%s Name: %s" "$commentType" "$inputFile"

            printf -v additionalLines\
                "\n#include <iostream>\n#include <string>\n#include <vector>\n\nint main()\n{\n\n}" ;;

        *".hpp")
            upperCaseFileName=$(changeCase -u -w "${inputFile%.*}")

            printf -v firstLine "%s Name: %s" "$commentType" "$inputFile"

            printf -v additionalLines\
                "\n#ifndef %s_HPP\n#define %s_HPP\n\n// Place Code Here\n\n#endif"\
                "$upperCaseFileName" "$upperCaseFileName" ;;

        *".sh")
            commentType="#"
            printf "#!/bin/bash\n" > "$inputFile"

            printf -v firstLine "%s Name: %s - Version 1.0.0" "$commentType" "$inputFile"

            printf -v additionalLines\
                "\n\n### Functions ###\
                \nsource errorHandling\
                \nsource typeParsing\
                \n\nprintHelpMessage()      #@ DESCRIPTION: Print the %s program's help message\
                \n{                       #@ USAGE: printHelpMessage\
                \n    printf \"\\\nUSAGE: %s [-hv] [-r STRING] [-o STRING]\\\n\\\n\"\
                \n    printf \"  -h  Prints help information about the %s program.\\\n\"\
                \n    printf \"  -v  Verbose mode. Defaults to false/off.\\\n\\\n\"\
                \n    printf \"  -r  REQUIRED: Description of required input parameter.\\\n\"\
                \n    printf \"  -o  OPTIONAL: Description of optional input parameter.\\\n\\\n\"\
                \n    printf \"EXAMPLE: %s -r required -v\\\n\\\n\"\
                \n}\
                \n\n\n### Initial Variables / Default Values ###\
                \ndeclare optionalArgument requiredArgument verbose\
                \n\nverbose=0\
                \n\n\n### Runtime Configuration ###\
                \nwhile getopts r:o:vh opt\
                \ndo\
                \n    case \$opt in\
                \n        r) STRING requiredArgument = \"\$OPTARG\" ;;\
                \n        o) STRING optionalArgument = \"\$OPTARG\" ;;\
                \n        v) export verbose=1 ;;\
                \n        h) printHelpMessage && printFatalErrorMessage 0 ;;\
                \n        *) printFatalErrorMessage 1 \"Invalid option flag passed to program.\" ;;\
                \n    esac\
                \ndone\
                \n\n\n### Main Code ###" "${inputFile%.*}" "${inputFile%.*}" "${inputFile%.*}" "${inputFile%.*}" ;;

        *".py")
            commentType="#"
            printf "#!/usr/bin/env python3\n# -*- coding: utf-8 -*-\n" > "$inputFile"

            printf -v firstLine "%s Name: %s - Version 1.0.0" "$commentType" "$inputFile"

            printf -v additionalLines\
                "\nimport numpy as np\nimport matplotlib.pyplot as plt" ;;

        *) printFatalErrorMessage 4 "Unknown file extension provided." ;;
    esac

    ## Append the standard template to file ##
    [[ ${copyright:-0} -eq 1 ]] && generateCopyrightHeader >> "$inputFile"

    printf "%s\
    \n%s Author: %s\
    \n%s Date: mm/dd/yyyy-hh:mm:ss\
    \n%s Description: \
    \n%s\n" "$firstLine" "$commentType" "${USER:-crdrisko}" "$commentType"\
    "$commentType" "$additionalLines" | sed 's/ *$//g' >> "$inputFile"

    ## Modify the date template with current date-time ##
    modifyFiles -i "$inputFile" -o "mm\/dd\/yyyy-hh:mm:ss" -n "$(date '+%m\/%d\/%Y-%T')" -f
else
    printFatalErrorMessage 5 "Invalid directory."
fi
