#!/usr/bin/bash

# this command will add new user
# we make use of useradd
# just a simple stupid scripts.

# first check uid of current user.
# check if the user have permission as root; else exit

function createUser {
    local USR=$1
    local PSWD=$2

    echo "Creating user: ${USR}"
    #create new user
    useradd -m ${USR}

    if [[ ${?} -ne 0 ]];
    then
        echo "Unable to create user"
        exit 1
    fi
    
    #else, set new password for user
    echo "${USR}:${PSWD}" | chpasswd && echo "user created successfully!"

}


#our program start here

if [[ "${UID}" -ne 0 ]];
then
    echo "Please run this script as root!"
    exit 1
fi

# else we continue
# -s means we don't want echo back our password to screen
read -p "Username to create: " USERNAME
read -s -p "Password for ${USERNAME}: " PASSWORD
echo
read -s -p "Confirm password: " CPASSWORD
echo 
if [[ "${PASSWORD}" = "${CPASSWORD}" ]];
then
    #calling our function and pass two params
    createUser $USERNAME $PASSWORD
else
    echo "Unmatched Password!"
    exit 1
fi