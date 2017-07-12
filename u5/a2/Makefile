all: Spaceship.o binary_search.o fastest_of_class.o

Spaceship.o: Spaceship.cpp Spaceship.hpp
	g++ -std=c++11 -c Spaceship.cpp

binary_search.o: Spaceship.o binary_search.cpp binary_search.hpp
	g++ -std=c++11 -c binary_search.cpp

fastest_of_class.o: Spaceship.o binary_search.o fastest_of_class.cpp fastest_of_class.hpp
	g++ -std=c++11 -c fastest_of_class.cpp

tests: tests.exe
	./tests.exe

tests.exe: Spaceship.o binary_search.o fastest_of_class.o tests.o
	g++ -std=c++11 -o tests.exe tests.o Spaceship.o binary_search.o fastest_of_class.o

tests.o: tests.cpp
	g++ -std=c++11 -c tests.cpp

clean:
	rm -f Spaceship.o
	rm -f binary_search.o
	rm -f fastest_of_class.o
	rm -f tests.o
	rm -f tests.exe

