all: Apple.o Binary_heap.o

Apple.o: Apple.cpp Apple.hpp
	g++ -std=c++11 -c Apple.cpp

Binary_heap.o: Apple.o Binary_heap.cpp Binary_heap.hpp
	g++ -std=c++11 -c Binary_heap.cpp

tests: tests.exe
	./tests.exe

tests.exe: Apple.o Binary_heap.o tests.o
	g++ -std=c++11 -o tests.exe tests.o Apple.o Binary_heap.o

tests.o: tests.cpp
	g++ -std=c++11 -c tests.cpp

clean:
	rm -f Apple.o
	rm -f Binary_heap.o
	rm -f tests.o
	rm -f tests.exe

