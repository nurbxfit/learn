#!/usr/bin/bash

#this is a comment
#but the thing on top is called shebang


# Assign Value to Variable
MYSTR='Hello World'
EXMP="help"
#make sure there is not space between var=value
#OUR Variable cannot start with digit
#we can start with underscore or letter


#simple display to console
echo "this is $MYSTR!"
#alternatively we can use ${}
echo "I am ${EXMP}ing"

#type show what kind of file
type echo

# we use help to show help information for shell buildin command.
#help echo

#for non sheell buildin we use `man` eg: `man nmap`, 
#in linux help information [val], the bracket means optional, so we dont have to use that variable

# more user variable we can view with `man bash`
# navigate man using vim command `/Shell Variables` to search for shell variables
#display local variable
echo "Bash: ${BASH} location"
echo "Goup id of current User: ${GROUPS}"
echo "UID: ${UID}, is the owner user id"
echo "EUID: ${EUID}, is the execute user id"

#we execute command using $(command)
#alternatively we can use backtick `command`
#display username
USERNAME=$(id -un) #we stored command output into variable
echo "username: ${USERNAME}"
echo "$(ls)"

#check if user is root or not
# a root user have a UID of 0., so we simply check the id

#please put space between double bracket and our condition
# alternatively we can use single bracket instead of double
# double bracket is a shell expression command, we can view using help [[ or man bash and search for expression
if [[ "${UID}" -eq 0 ]]; #-eq is test command operator, we can view using `help test` 
then
    echo "I am g root!"

elif [[ "${UID}" -eq 1000 ]]; #semicolon is command seperator for new line
then #dont forget this then
    echo "I am Jun"
else
    echo "I am noobs"
fi #remember to close our if statement using fi


# there are 3 I/O type, stdin,stdout, stderr
# we take user input using read command. use help read for more info.
# read: read [-ers] [-a array] [-d delim] [-i text] [-n nchars] [-N nchars] [-p prompt] [-t timeout] [-u fd] [name ...]
read -p "Enter min number: " MINNUM
echo "You entered ${MINNUM}"
read  -p "Enter max number: " MAXNUM
echo "You entered ${MAXNUM}"

# Looping
# example for range looping 
for i in {1,2,5,6};
do 
    echo  -n "${i}" #the -n options is for no new line
done
echo 
for i in {1..5}
do
    echo -n "${i}"
done
echo



#exit status 0: success, nonzero: failed
# NOTE: ${?}, the question mark, means the exit status of recent program. 
# we can use it to check if our command executed successfully or not.

#alternative variable declaration
# instead of declare using MYVAR=10
# we can use `declare -i MYVAR=10`

# Bash Array Syntax
# arr=()	Create an empty array
# arr=(1 2 3)	Initialize array
# ${arr[2]}	Retrieve third element
# ${arr[@]}	Retrieve all elements
# ${!arr[@]}	Retrieve array indices
# ${#arr[@]}	Calculate array size
# arr[0]=3	Overwrite 1st element
# arr+=(4)	Append value(s)
# str=$(ls)	Save ls output as a string
# arr=( $(ls) )	Save ls output as an array of files
# ${arr[@]:s:n}	Retrieve n elements starting at index s
