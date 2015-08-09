#!/bin/bash

# Runs a test, outputting results appropriately.
# USAGE: RunTest.sh test_to_run

RED='\033[31m'
GREEN='\033[32m'
BOLD='\033[1m'
RESET='\033[0m'

if [ -z $1 ]; then
	echo "USAGE: run-test.sh test_to_run"
	exit 1;
fi

if [ ! -e $1 ]; then
	echo "$1 does not exist!"
	exit 1;
fi

RETURNED_VALUE=`$1`
IS_FAILURE=`echo ${RETURNED_VALUE} | grep -c Failure` 

COLOR=$RED
if [ 0 -eq $IS_FAILURE ]; then
	COLOR=$GREEN
fi

echo -e ${BOLD} ${COLOR}
echo ${RETURNED_VALUE} 
echo -e ${RESET}
#tput sgr0
