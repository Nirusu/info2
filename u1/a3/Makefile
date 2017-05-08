all: Linked_list.o Queue.o

Linked_list.o:
	g++ -c ../a2/Linked_list.cpp

Queue.o: Linked_list.o Queue.cpp Queue.hpp
	g++ -c Queue.cpp

tests: tests.exe
	./tests.exe

tests.exe: Linked_list.o Queue.o tests.o
	g++ -o tests.exe tests.o Queue.o Linked_list.o

tests.o: ../a1/catch.hpp tests.cpp
	g++ -c tests.cpp

clean:
	rm -f Linked_list.o
	rm -f Linked_list.cpp
	rm -f Linked_list.hpp
	rm -f Queue.o
	rm -f tests.o
	rm -f tests.exe
