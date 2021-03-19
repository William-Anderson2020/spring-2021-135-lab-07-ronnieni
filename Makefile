main: main.o funcs.o
	g++ -o main main.o unindent.o indent.o

tests: tests.o funcs.o
	g++ -o tests tests.o unindent.o indent.o


unindent.o: unindent.cpp unindent.h

indent.o: indent.cpp indent.h

main.o: main.cpp unindent.h indent.h

tests.o: tests.cpp doctest.h unindent.h indent.h

clean:
	rm -f main.o tests.o unindent.o indent.o
