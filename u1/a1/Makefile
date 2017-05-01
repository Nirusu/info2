all: Simple_class.o

Simple_class.o: Simple_class.cpp Simple_class.hpp
	g++ -c Simple_class.cpp

tests: tests.exe
	./tests.exe

tests.exe: Simple_class.o tests.o
	g++ -o tests.exe tests.o Simple_class.o

tests.o: tests.cpp
	g++ -c tests.cpp

clean:
	rm -f Simple_class.o
	rm -f tests.o
	rm -f tests.exe

