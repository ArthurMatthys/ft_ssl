#/!bin/bash
SHA384_PERSO="./ft_ssl sha384 -q "
SHA384_ORIGIN="shasum -a 384"

COL=$(tput cols)
RES_POS=$(($COL - 4))
MOVE_TO_COL="printf \\033[${RES_POS}G"
RED=$(tput setaf 1)
GREEN=$(tput setaf 2)
NORMAL=$(tput sgr0)
RES=0


test_sha384 ()
{
	printf "SHA384 -> %s" "$1"
	if [ -z $3 ]
	then
		(eval ${SHA384_PERSO} $2) > my_hash
		(eval ${SHA384_ORIGIN} $2 | cut -d' ' -f 1 ) > origin_hash
	else
		(eval $3 "$4" | eval ${SHA384_PERSO} $2) > my_hash
		(eval $3 "$4" | eval ${SHA384_ORIGIN} $2) | cut -d' ' -f 1  > origin_hash 
	fi

	diff my_hash origin_hash
	if [ $? -eq 0 ]
	then
		$MOVE_TO_COL
		printf "%s" "${GREEN}[OK]${NORMAL}" $'\n'
	else
		$MOVE_TO_COL
		printf "%s" "${RED}[KO]${NORMAL}" $'\n'
		RES=1
	fi
	rm my_hash
	rm origin_hash
}

test_sha384 'empty input 0' '' 'echo ' ''

test_sha384 'simple input 0' '' 'echo ' 'Bonjour'

test_sha384 'long input 0' '' 'echo ' 'dailleurs clcreuso je suis dsol mais mes entrainjdssssssssssssssssssssssssssssgfdshhhhhhhhhhhhhhhgfddddddddddddddddddddddddddjjjjjjjjjjjjjjjhgddjhfgjjjjjjjjjj'

test_sha384 'file 0' '' 'cat ' 'auteur'
test_sha384 'file 1' '' 'cat ' 'Makefile'
test_sha384 'file 2' 'ft_ssl'
test_sha384 'no flag 0' '/bin/*' 

exit ${RES}
