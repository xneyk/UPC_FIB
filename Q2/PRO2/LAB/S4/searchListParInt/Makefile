OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG  -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o LlistaIOParInt.o ParInt.o
	g++ -o program.exe program.o LlistaIOParInt.o ParInt.o

ParInt.o:  ParInt.cc ParInt.hh 
	g++ -c ParInt.cc $(OPCIONS)

LlistaIOParInt.o:  LlistaIOParInt.cc LlistaIOParInt.hh ParInt.hh 
	g++ -c LlistaIOParInt.cc $(OPCIONS)

program.o: program.cc LlistaIOParInt.hh ParInt.hh 
	g++ -c program.cc $(OPCIONS)

tar: program.cc LlistaIOParInt.cc LlistaIOParInt.hh
	tar -cvf program.tar program.cc LlistaIOParInt.cc LlistaIOParInt.hh

clean:
	rm *.o
	rm *.exe

