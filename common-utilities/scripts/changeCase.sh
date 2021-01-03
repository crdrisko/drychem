#!/bin/bash
# Copyright (c) 2020-2021 Cody R. Drisko. All rights reserved.
# Licensed under the MIT License. See the LICENSE file in the project root for more information.
#
# Name: changeCase.sh - Version 1.1.0
# Author: crdrisko
# Date: 01/31/2020-14:45:49
# Description: Script to change the case of an input string


### Functions ###
source errorHandling
source typeParsing

printHelpMessage()      #@ DESCRIPTION: Print the changeCase program's help message
{                       #@ USAGE: printHelpMessage
    printf "\nUSAGE: changeCase [-hvulf] [-w STRING]\n\n"
    printf "  -h  Prints help information about the changeCase program.\n"
    printf "  -v  Verbose mode. Defaults to false/off.\n"
    printf "  -u  Change word/letter to uppercase. Defaults to false/off.\n"
    printf "  -l  Change word/letter to lowercase. Defaults to false/off.\n"
    printf "  -f  Change only the first letter to selected case. Defaults to false/off.\n\n"
    printf "  -w  REQUIRED: Word to change case of.\n\n"
    printf "EXAMPLE: changeCase -f -l -w LOWERCASE\n\n"
}

to_upper()              #@ DESCRIPTION: Convert the first letter of a word to uppercase
{                       #@ USAGE: to_upper sTRING
    unset _UPR
    unset UPWORD

    if [[ ${BASH_VERSINFO[0]} -ge 4 ]]
    then
        UPWORD=${1^}
    else
        case $1 in
            a*) _UPR=A ;; b*) _UPR=B ;; c*) _UPR=C ;; d*) _UPR=D ;;
            e*) _UPR=E ;; f*) _UPR=F ;; g*) _UPR=G ;; h*) _UPR=H ;;
            i*) _UPR=I ;; j*) _UPR=J ;; k*) _UPR=K ;; l*) _UPR=L ;;
            m*) _UPR=M ;; n*) _UPR=N ;; o*) _UPR=O ;; p*) _UPR=P ;;
            q*) _UPR=Q ;; r*) _UPR=R ;; s*) _UPR=S ;; t*) _UPR=T ;;
            u*) _UPR=U ;; v*) _UPR=V ;; w*) _UPR=W ;; x*) _UPR=X ;;
            y*) _UPR=Y ;; z*) _UPR=Z ;;  *) _UPR=${1%${1#?}} ;;
        esac
        UPWORD=$_UPR${1:1:${#1}}
    fi
}

upword()                #@ DESCRIPTION: Convert the entire word to uppercase
{                       #@ USAGE: upword string
    unset _UPWORD
    unset UPWORD
    local Word=$1

    if [[ ${BASH_VERSINFO[0]} -ge 4 ]]
    then
        UPWORD=${Word^^}
    else
        while [ -n "$Word" ]
        do
            to_upper "$Word"
            _UPWORD=$_UPWORD$_UPR
            Word=${Word#?}
        done
        UPWORD=$_UPWORD
    fi
}

to_lower()              #@ DESCRIPTION: Convert the first letter of a word to lowercase
{                       #@ USAGE: to_lower String
    unset _LWR
    unset LOWWORD

    if [[ ${BASH_VERSINFO[0]} -ge 4 ]]
    then
        LOWWORD=${1,}
    else
        case $1 in
            A*) _LWR=a ;; B*) _LWR=b ;; C*) _LWR=c ;; D*) _LWR=d ;;
            E*) _LWR=e ;; F*) _LWR=f ;; G*) _LWR=g ;; H*) _LWR=h ;;
            I*) _LWR=i ;; J*) _LWR=j ;; K*) _LWR=k ;; L*) _LWR=l ;;
            M*) _LWR=m ;; N*) _LWR=n ;; O*) _LWR=o ;; P*) _LWR=p ;;
            Q*) _LWR=q ;; R*) _LWR=r ;; S*) _LWR=s ;; T*) _LWR=t ;;
            U*) _LWR=u ;; V*) _LWR=v ;; W*) _LWR=w ;; X*) _LWR=x ;;
            Y*) _LWR=y ;; Z*) _LWR=z ;;  *) _LWR=${1%${1#?}} ;;
        esac
        LOWWORD=$_LWR${1:1:${#1}}
    fi
}

lowword()               #@ DESCRIPTION: Convert the entire word to lowercase
{                       #@ USAGE: lowword STRING
    unset _LOWWORD
    unset LOWWORD
    local Word=$1

    if [[ ${BASH_VERSINFO[0]} -ge 4 ]]
    then
        LOWWORD=${Word,,}
    else
        while [ -n "$Word" ]
        do
            to_lower "$Word"
            _LOWWORD=$_LOWWORD$_LWR
            Word=${Word#?}
        done
        LOWWORD=$_LOWWORD
    fi
}


### Initial Variables / Default Values ###
declare first lower upper verbose word

upper=0
lower=0
first=0
verbose=0


### Runtime Configuration ###
while getopts w:fluvh opt
do
    case $opt in
        w) STRING word = "$OPTARG" ;;
        f) first=1 ;;
        l) lower=1 ;;
        u) upper=1 ;;
        v) export verbose=1 ;;
        h) printHelpMessage && printFatalErrorMessage 0 ;;
        *) printFatalErrorMessage 1 "Invalid option flag passed to program." ;;
    esac
done


### Main Code ###
if [[ $upper -eq 1 && $lower -eq 1 ]]
then
    printFatalErrorMessage 2 "Only one of the options: -u or -l can be selected."
elif [[ $upper -eq 1 && $lower -eq 0 ]]
then
    if [[ ${first:-0} -eq 1 ]]
    then
        to_upper "${word:?You must supply a word}"
    else
        upword "${word:?You must supply a word}"
    fi

    printf "%s\n" "$UPWORD"

elif [[ $upper -eq 0 && $lower -eq 1 ]]
then
    if [[ ${first:-0} -eq 1 ]]
    then
        to_lower "${word:?You must supply a word}"
    else
        lowword "${word:?You must supply a word}"
    fi

    printf "%s\n" "$LOWWORD"

else
    printFatalErrorMessage 3 "Either the upper or lower option must be selected."
fi
