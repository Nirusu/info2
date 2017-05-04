all: Linked_list.o

Linked_list.o: Linked_list.cpp Linked_list.hpp
	g++ -c Linked_list.cpp

tests: tests.exe
	./tests.exe

tests.exe: Linked_list.o tests.o
	g++ -o tests.exe tests.o Linked_list.o

tests.o: ../a1/catch.hpp tests.cpp
	g++ -c tests.cpp

clean:
	rm -f Linked_list.o
	rm -f tests.o
	rm -f tests.exe

