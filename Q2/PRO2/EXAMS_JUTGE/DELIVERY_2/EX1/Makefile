OPTIONS = -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11 -fno-extended-identifiers
#
G++ = g++-13

main.exe: main.o treeOfSumsOfAncestors.o
	$(G++) -o main.exe main.o treeOfSumsOfAncestors.o $(OPTIONS)
#
main.o: main.cc
	$(G++) -c main.cc $(OPTIONS)
#
treeOfSumsOfAncestors.o: treeOfSumsOfAncestors.cc
	$(G++) -c treeOfSumsOfAncestors.cc $(OPTIONS)
#
clear:
	rm *.o *.exe