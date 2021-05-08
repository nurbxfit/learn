#!/bin/bash



ls *.txt | awk 'BEGIN{print "Begin..."} {print "Main.."} END{print "ENDING"}' 

cat table.txt | awk '{print $2,$3,$4}'

cat table.txt | awk 'BEGIN{print "\n\nSearching for Grindal\n" } /Grindal/ {print $1,$2,$3}'
