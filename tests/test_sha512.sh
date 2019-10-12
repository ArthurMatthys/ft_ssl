#/!bin/bash
SHA512_PERSO="./ft_ssl sha512 "
SHA512_ORIGIN="shasum -a 512 | cut -d' ' -f 1 "

COL=$(tput cols)
RES_POS=$(($COL - 4))
MOVE_TO_COL="printf \\033[${RES_POS}G"
RED=$(tput setaf 1)
GREEN=$(tput setaf 2)
NORMAL=$(tput sgr0)
RES=0


test_sha512 ()
{
	printf "SHA512 -> %s" "$1"
	if [ -z $3 ]
	then
		(eval ${SHA512_PERSO} $2) > my_hash.output
		(eval ${SHA512_ORIGIN} $2) > origin_hash.output
	else
		(eval $3 "$4" | eval ${SHA512_PERSO} $2) > my_hash.output
		(eval $3 "$4" | eval ${SHA512_ORIGIN} $2) > origin_hash.output 
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

test_sha512 'empty input 0' '' 'echo ' ''

test_sha512 'simple input 0' '' 'echo ' 'Bonjour'

test_sha512 'long input 0' '' 'echo ' 'dailleurs clcreuso je suis dsol mais mes entrainjdssssssssssssssssssssssssssssgfdshhhhhhhhhhhhhhhgfddddddddddddddddddddddddddjjjjjjjjjjjjjjjhgddjhfgjjjjjjjjjj'

test_sha512 'file 0' '' 'cat ' 'auteur'
test_sha512 'file 1' '' 'cat ' 'Makefile'
test_sha512 'file 2' '' 'cat ' 'ft_ssl'

exit ${RES}
