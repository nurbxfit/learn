#!/bin/bash
#simple script store result of ls in array
#then loop through it.

FILES=($(ls *.txt))
COUNT=0

for FILE in ${FILES[@]}
do
	echo  $FILE
done
