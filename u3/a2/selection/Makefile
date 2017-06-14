all: selection_string.o

selection_string.o: selection_string.cpp selection_string.hpp
	g++ -std=c++11 -c selection_string.cpp

tests: tests.exe
	./tests.exe

tests.exe: selection_string.o tests.o
	g++ -std=c++11 -o tests.exe tests.o selection_string.o

tests.o: tests.cpp
	g++ -std=c++11 -c tests.cpp

clean:
	rm -f selection_string.o
	rm -f tests.o
	rm -f tests.exe

