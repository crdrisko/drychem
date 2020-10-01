#!/bin/bash
# Copyright (c) 2020 Cody R. Drisko. All rights reserved.
# Licensed under the MIT License. See the LICENSE file in the project root for more information.
#
# Name: showOpts.sh - Version 1.0.0
# Author: crdrisko
# Date: 01/31/2020-14:46:34
# Description: Print the options of parameter expansion for $1 around $2

bar="----------------------"
bar=$bar$bar$bar$bar
bar=${bar:0:80}

printf "\n    Input: %s\n" "$1"
printf "Delimiter: <%s>\n" "${2:-space}"
printf "%s\n" "$bar"
printf "    First: \${1%%%%\$2*} ==> %s\n" "${1%%${2:-\ }*}"
printf "     Last: \${1##*\$2} ==> %s\n" "${1##*${2:-\ }}"
printf "Not First: \${1#*\$2}  ==> %s\n" "${1#*${2:-\ }}"
printf " Not Last: \${1%%\$2*}  ==> %s\n\n" "${1%${2:-\ }*}"
