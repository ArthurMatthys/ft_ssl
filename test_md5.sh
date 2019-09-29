#!/bin/bash

MD5_PERSO="./ft_ssl md5"
MD5_ORIGIN="md5"

COL=$(tput cols)
RES_POS=$(($COL - 4))
MOVE_TO_COL="printf \\033[${RES_POS}G"
RED=$(tput setaf 1)
GREEN=$(tput setaf 2)
NORMAL=$(tput sgr0)
RES=0


test_md5 ()
{
	printf "MD5 -> %s" "$1"
	if [ -z $3 ]
	then
#		test "$(${MD5_PERSO} $2)" = "$(${MD5_ORIGIN} $2)"
		(eval ${MD5_PERSO} $2) > my_hash.output
		(eval ${MD5_ORIGIN} $2) > origin_hash.output
	fi
	diff my_hash.output origin_hash.output
	if [ $? -eq 0 ]
	then
		$MOVE_TO_COL
		printf "%s" "${GREEN}[OK]${NORMAL}" $'\n'
	else
		$MOVE_TO_COL
		printf "%s" "${RED}[KO]${NORMAL}" $'\n'
		RES=1
	fi
	rm my_hash.output
	rm origin_hash.output
}

test_md5 'simple string 0', '-s "easy"'
test_md5 'simple string 1', '-s "This test contain 48 bytes, so I made it biggerr"' 
test_md5 'simple string 2', '-s "Hello"'
test_md5 'simple string 3', '-s "Hello Darkness"' 
test_md5 'simple string 4', '-s "Hello Darkness my old friend"' 


test_md5 'quite string 0', '-q -s "easy"' 
test_md5 'quite string 1', '-q -s "This test contain 48 bytes, so I made it biggerr"' 
test_md5 'quite string 2', '-q -s "Hello"' 
test_md5 'quite string 3', '-q -s "Hello Darkness"' 


test_md5 'quite reverse string 0', '-q -r -s "Hello Darkness my old friend"' 

test_md5 'quite strings 0', '-q -s "Hello" -s "My friend"' 
test_md5 'quite strings 1', '-q -s "Hello" -s "Darkness my old friend"' 
test_md5 'quite strings 2', '-q -s "Hello Darkness" -s "my old friend"' 

test_md5 'multiple string 0', '-s Hello -s My' 
test_md5 'multiple string 1', '-s My -s old -s Friend' 
test_md5 'multiple string 2', '-s Hello -s "This test contain 48 bytes, so I made it biggerr"' 
test_md5 'multiple string 3', '-s I -s Dont -s know -s what -s I -s should -s -test' 


exit ${RES}
