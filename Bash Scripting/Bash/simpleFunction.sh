#!/bin/bash

function addFunc {
local A=$1 #assign first aregument to A
local B=$2 #assign second argument to B
let C=A+B
echo "TOTAL:${C}"
}

echo -n "First number: "
read TEST1
echo -n "Second number: "
read TEST2
addFunc $TEST1 $TEST2

