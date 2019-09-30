#!/bin/bash

check_test ()
{
	eval $1
	if [ $? -ne 0 ]
	then
		exit 1
	fi
}


check_test './tests/test_md5.sh'

