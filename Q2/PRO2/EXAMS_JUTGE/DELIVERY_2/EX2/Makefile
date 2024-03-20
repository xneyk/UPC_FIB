OPTIONS = -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11 -fno-extended-identifiers
#
G++ = g++-13

main.exe: main.o execute.o
	$(G++) -o main.exe main.o execute.o $(OPTIONS)
#
main.o: main.cc
	$(G++) -c main.cc $(OPTIONS)
#
execute.o: execute.cc
	$(G++) -c execute.cc $(OPTIONS)
#
clear:
	rm *.o *.exe