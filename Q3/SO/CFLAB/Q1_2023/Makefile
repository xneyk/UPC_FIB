all: parser modifier multiparser

parser: parser.c
	gcc -o parser parser.c

modifier: modifier.c
	gcc -o modifier modifier.c

multiparser: multiparser.c
	gcc -o multiparser multiparser.c

clean:
	rm -f parser modifier multiparser