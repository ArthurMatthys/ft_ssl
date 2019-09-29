import os
import difflib


MY_MD5='./ft_ssl md5 '
ORIGIN_MD5='md5 '

class bcolors:
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'


def test_md5(test_request : str, test_string : str, cmd = None, bonus_arg = None):
    global ret
    print("MD5 => {0:<50}".format(test_request), end='')
    if cmd:
        mycmd = cmd + ' ' + bonus_arg + ' | ' + MY_MD5 + test_string
        origincmd = cmd + ' ' + bonus_arg + ' | ' + ORIGIN_MD5 + test_string
        my_md5 = os.popen(mycmd).read()
        origin_md5 = os.popen(origincmd).read()
    else:
        mycmd = MY_MD5 + test_string
        origincmd = ORIGIN_MD5 + test_string
        my_md5 = os.popen(mycmd).read()
        origin_md5 = os.popen(origincmd).read()
    output_list = [li for li in difflib.ndiff(my_md5, origin_md5) if li[0] != ' ']
    if not len(output_list):
        print(bcolors.OKGREEN + "[OK]" + bcolors.ENDC)
    else:
        print(mycmd)
        print(my_md5)
        print(origin_md5)
        print(bcolors.FAIL + "[KO]" + bcolors.ENDC)
        ret = 1


def run_test():
    global ret
    ret = 0

    test_md5("simple string 0", "-s 'easy'")
    test_md5("simple string 1", "-s 'This test contain 48 bytes, so I made it biggerr'")
    test_md5("simple string 2", "-s 'Hello'")
    test_md5("simple string 3", "-s 'Hello Darkness'")
    test_md5("simple string 4", "-s 'Hello Darkness my old friend'")


    test_md5("quite string 0", "-q -s 'easy'")
    test_md5("quite string 1", "-q -s 'This test contain 48 bytes, so I made it biggerr'")
    test_md5("quite string 2", "-q -s 'Hello'")
    test_md5("quite string 3", "-q -s 'Hello Darkness'")
    test_md5("quite string 4", "-q -s 'Hello Darkness my old friend'")

    test_md5("multiple string 0", "-s Hello -s My")
    test_md5("multiple string 1", "-s My -s old -s Friend")
    test_md5("multiple string 2", "-s Hello -s 'This test contain 48 bytes, so I made it biggerr'")
    test_md5("multiple string 3", "-s I -s Dont -s know -s what -s I -s should -s -test")

#    test_md5("multiple string with mistake 0", "-s I -s Dont -s know -s what -s I -should")
#    test_md5("multiple string with mistake 1", "-s I -s Dont -s know -s what -s I -rshould")

    test_md5("empty string", "-s ''")

#    test_md5("existing directory", "src")
#    test_md5("not existing directory", "srcs")

    return (ret)

if __name__== "__main__":
    run_test()

