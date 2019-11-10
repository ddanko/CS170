
#To run, put this file together with lexer.h, and lexer.c
#in the same directory. Run "make". Then the executable
#is "schemer," which just takes a line of input and
#breaks it up into tokens.

scheme: scheme.o lexer.o parser.o
	gcc -o scheme scheme.o lexer.o parser.o

scheme.o: scheme.c
	gcc -c scheme.c

lexer.o: lexer.c
	gcc -c lexer.c

parser.o: parser.c
	gcc -c parser.c

clean:
	rm -f *~ *.o *.a scheme

#^^^^^^This space must be a TAB!!.
