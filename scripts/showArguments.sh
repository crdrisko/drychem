#!/bin/bash
# Copyright (c) 2020 Cody R. Drisko. All rights reserved.
# Licensed under the MIT License. See the LICENSE file in the project root for license information.
#
# Name: showArguments.sh - Version 1.0.0
# Author: crdrisko
# Date: 01/31/2020-14:46:41
# Description: Prints command-line arguments

pre="<"
post=">"

printf "$pre%s$post\n" "$@"
