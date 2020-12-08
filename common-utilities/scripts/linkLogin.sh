#!/bin/bash
# Copyright (c) 2020 Cody R. Drisko. All rights reserved.
# Licensed under the MIT License. See the LICENSE file in the project root for more information.
#
# Name: linkLogin.sh - Version 1.0.1
# Author: cdrisko
# Date: 01/31/2020-14:45:27
# Description: Create login scripts from the configuration files in the current working directory


### Functions ###
source errorHandling

printHelpMessage()      #@ DESCRIPTION: Print the linkLogin program's help message
{                       #@ USAGE: printHelpMessage
    printf "\nUSAGE: [sudo] linkLogin [-h] [--help]\n\n"
    printf "The linkLogin program will search for all .config files in the current working\n"
    printf "  directory. The configuration files should be formatted in the manner shown\n"
    printf "  below. The comments are unnecessary, but the keywords are case sensitive. The\n"
    printf "  name of the configuration file will be what you call to login to the specified\n"
    printf "  host. Example: If the filename is TEST.config, the command to log on to the\n"
    printf "  host contained in TEST.config would be TEST.\n\n"
    printf "hostname=           ## REQUIRED: Domain/host name of the host machine.\n"
    printf "username=           ## REQUIRED: Username of the profile on host machine.\n"
    printf "port=               ## Port number of the host machine. Defaults to port 22.\n"
    printf "hostchain=          ## Host to log on to prior to the desired ssh host.\n"
    printf "openNewTerminal=    ## Whether or not to open new a new terminal window. Defaults to true.\n"
    printf "profile=            ## Name of the profile to use in the new terminal window.\n"
    printf "fontsize=           ## Font size to use in the new terminal window.\n\n"
    printf "Run the following code to generate a properly formated configuration file:\n"
    printf "  linkLogin -h | tail -n 11 | head -n 7 > TEST.config\n\n"
}


### Main Code ###
if [[ -n $1 && ($1 == -h || $1 == --help) ]]
then
    printHelpMessage && printFatalErrorMessage 0
fi

for configurationFile in *.config
do
    IFS=$'\n'
    settings=( $( < "$configurationFile" ) )          ## Read configuration file into settings array
    eval "${settings[@]%%#*}"                         ## Evaluate the assignments in the configuration file

    [[ -n ${hostchain:=""} ]] && username="-J $hostchain ${username:?}"

    ## Options for the ssh login from terminal app on MacOS ##
    if [[ $OSTYPE == darwin* && ${openNewTerminal:-true} == true ]]
    then
        printf -v sshScript "osascript -e 'tell application \"Terminal\"\
        \n  do script \"\"\
        \n  do script \"slogin %s@%s -p %s -Y\" in first window\
        \n  tell application \"Terminal\" to set current settings of first window to settings set \"%s\"\
        \n  tell application \"Terminal\" to set font size of first window to %s\
        \nend tell'" "${username:?}" "${hostname:?}" "${port:-22}" "${profile:-Pro}" "${fontsize:-11}"

    ## Options for ssh login from gnome-terminal ##
    elif which gnome-terminal &>/dev/null && [[ ${openNewTerminal:-true} == true ]]
    then
        [[ -n $profile ]] && profile="--window-with-profile=$profile "

        printf -v sshScript "gnome-terminal %s-- slogin %s@%s -p %s -Y & disown"\
            "$profile" "${username:?}" "${hostname:?}" "${port:-22}"

    ## Options for standard ssh login ##
    else
        printf -v sshScript "slogin %s@%s -p %s" "${username:?}" "${hostname:?}" "${port:-22}"
    fi

    installDirectory=@CMAKE_INSTALL_PREFIX@/bin
    ! [[ -d $installDirectory ]] && printFatalErrorMessage 1 "Invalid installation directory."

    printf '#!/bin/bash\n%s\n' "$sshScript" > "$installDirectory/${configurationFile%%.*}"
    chmod +x "$installDirectory/${configurationFile%%.*}"

    unset hostname username port hostchain openNewTerminal profile fontsize
done
