all: insertion_string.o

insertion_string.o: insertion_string.cpp insertion_string.hpp
	g++ -std=c++11 -c insertion_string.cpp

tests: tests.exe
	./tests.exe

tests.exe: insertion_string.o tests.o
	g++ -std=c++11 -o tests.exe tests.o insertion_string.o

tests.o: tests.cpp
	g++ -std=c++11 -c tests.cpp

clean:
	rm -f insertion_string.o
	rm -f tests.o
	rm -f tests.exe

