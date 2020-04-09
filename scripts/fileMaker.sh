#!/bin/bash
# Copyright (c) 2020 Cody R. Drisko. All rights reserved.
# Licensed under the MIT License. See the LICENSE file in the project root for license information.
#
# Name: fileMaker.sh - Version 1.0.0
# Author: cdrisko
# Date: 01/31/2020-14:45:20
# Description: Creates new files based off simple, pre-defined templates


### Functions ###
source errorHandling

printHelpMessage()      #@ DESCRIPTION: Print the fileMaker program's help message
{                       #@ USAGE: printHelpMessage
    printf "\nUSAGE: fileMaker [-hvc] [-i inputFile]\n\n"
    printf "  -h  Prints help information about the fileMaker program.\n"
    printf "  -v  Verbose mode. Defaults to false/off.\n"
    printf "  -c  Print copyright header in source code. Defaults to false/off.\n\n"
    printf "  -i  REQUIRED: Either a .cpp, .cu, .hpp, .php, .py, or .sh input file.\n\n"
    printf "EXAMPLE: fileMaker -i exampleFile.cpp -c\n\n"
}

generateCopyrightHeader()   #@ DESCRIPTION: Search for LICENSCE file and print copyright header if found
{                           #@ USAGE: generateCopyrightHeader
    previousDirectory="$PWD"

    while ! [ -f "LICENSE" ]
    do
        cd ../
        licenseDirectory="$PWD"

        if [ "$licenseDirectory" == '/' ]
        then
            printNonFatalErrorMessage "LICENSE file not found."
            cd "$previousDirectory"
            return
        fi
    done

    cd "$previousDirectory"

    copyright=$( grep Copyright\ \(c\) "${licenseDirectory:=\"$PWD\"}"/LICENSE )
    licenseType=$( head -n 1 "$licenseDirectory"/LICENSE )

    printf "%s %s. All rights reserved.\n" "$commentType" "$copyright"
    printf "%s Licensed under the %s." "$commentType" "$licenseType"
    printf " See the LICENSE file in the project root for license information.\n"
    printf "%s\n" "$commentType"
}


### Initial Variables / Default Values ###
verbose=0
copyright=0
directory="$PWD"
commentType="//"


### Runtime Configuration ###
while getopts i:cvh opt
do
    case $opt in
        i) fileName="${OPTARG##*/}"
           if [ "$fileName" != "${OPTARG%/*}" ]
           then
               directory="${OPTARG%/*}"
           fi ;;
        c) copyright=1 ;;
        v) verbose=1 ;;
        h) printHelpMessage && printFatalErrorMessage 0 ;;
    esac
done


### Main Code ###
[ -d "$directory" ] && cd "$directory" || printFatalErrorMessage 1 "Invalid directory."

[ -e ${fileName:?Input file is required} ] && printFatalErrorMessage 2 "Sorry that file already exists."

## Switch on file extension ##
case $fileName in
    *".cpp")
        printf -v firstLine "%s Name: %s - Version 1.0.0" "$commentType" "$fileName"

        printf -v additionalLines\
            "\n#include <iostream>\n#include <string>\n#include <vector>\n\nint main()\n{\n\n}" ;;

    *".hpp")
        upperCaseFileName=$(changeCase -u -w ${fileName%.*})

        printf -v firstLine "%s Name: %s - Version 1.0.0" "$commentType" "$fileName"

        printf -v additionalLines\
            "\n#ifndef %s_HPP\n#define %s_HPP\n\n// Place Code Here\n\n#endif"\
            $upperCaseFileName $upperCaseFileName ;;

    *".php")
        chapterNumber="${PWD:$(( ${#PWD} - 2 )):2}"
        printf "<?php\n" > $fileName

        printf -v firstLine "%s Name: %s - Version 1.0.0" "$commentType" "$fileName"

        printf -v additionalLines\
            "// Website: http://localhost:80%s/%s\n?>" "$chapterNumber" "$fileName" ;;

    *".sh")
        commentType="#"
        printf "#!/bin/bash\n" > $fileName

        printf -v firstLine "%s Name: %s - Version 1.0.0" "$commentType" "$fileName"

        printf -v additionalLines\
            "\n\n### Functions ###\
            \nsource errorHandling\
            \n\nprintHelpMessage()      #@ DESCRIPTION: Print the %s program's help message\
            \n{                       #@ USAGE: printHelpMessage\
            \n    printf \"\\\nUSAGE: %s [-hv] [-r required] [-o optional]\\\n\\\n\"\
            \n    printf \"  -h  Prints help information about the %s program.\\\n\"\
            \n    printf \"  -v  Verbose mode. Defaults to false/off.\\\n\\\n\"\
            \n    printf \"  -r  REQUIRED: Description of required input parameter.\\\n\"\
            \n    printf \"  -o  OPTIONAL: Description of optional input parameter.\\\n\\\n\"\
            \n    printf \"EXAMPLE: %s -r required -v\\\n\\\n\"\
            \n}\
            \n\n\n### Initial Variables / Default Values ###\
            \nverbose=0\
            \n\n\n### Runtime Configuration ###\
            \nwhile getopts r:o:vh opt\
            \ndo\
            \n    case \$opt in\
            \n        r) requiredArgument=\$OPTARG ;;\
            \n        o) optionalArgument=\$OPTARG ;;\
            \n        v) verbose=1 ;;\
            \n        h) printHelpMessage && printFatalErrorMessage 0 ;;\
            \n    esac\
            \ndone\
            \n\n\n### Main Code ###\n" ${fileName%.*} ${fileName%.*} ${fileName%.*} ${fileName%.*} ;;

    *".py")
        commentType="#"
        printf "#!/usr/bin/env python3\n# -*- coding: utf-8 -*-\n" > $fileName

        printf -v firstLine "%s Name: %s - Version 1.0.0" "$commentType" "$fileName"

        printf -v additionalLines\
            "\nimport numpy as np\nimport matplotlib.pyplot as plt" ;;

    *".cu")
        printf -v firstLine "%s Name: %s - Version 1.0.0" "$commentType" "$fileName"

        printf -v additionalLines\
            "\n#include <stdio.h>\n#include <driver_types.h>\n#include \"cuda_runtime.h\"\
            \n#include \"device_launch_parameters.h\"\n\nint main( void )\n{\n\n}" ;;

    *) printFatalErrorMessage 3 "Unknown file extension provided." ;;
esac

## Append the standard template to file ##
[ ${copyright:-0} -eq 1 ] && generateCopyrightHeader >> $fileName

printf "%s\n\
%s Author: %s\n\
%s Date: mm/dd/yyyy-hh:mm:ss\n\
%s Description: \n\
%s\n" "$firstLine" "$commentType" "${USER:-cdrisko}" "$commentType"\
  "$commentType" "$additionalLines" | sed 's/ *$//g' >> $fileName

## Modify the date template with current date-time ##
modifyFiles -i $fileName -o "mm\/dd\/yyyy-hh:mm:ss" -n $(date '+%m\/%d\/%Y-%T') -f
