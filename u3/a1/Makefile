all: buffy_vampire_slayer.o

buffy_vampire_slayer.o: buffy_vampire_slayer.cpp buffy_vampire_slayer.hpp
	g++ -std=c++11 -c buffy_vampire_slayer.cpp

tests: tests.exe
	./tests.exe

tests.exe: buffy_vampire_slayer.o tests.o
	g++ -std=c++11 -o tests.exe tests.o buffy_vampire_slayer.o

tests.o: tests.cpp
	g++ -std=c++11 -c tests.cpp

clean:
	rm -f buffy_vampire_slayer.o
	rm -f tests.o
	rm -f tests.exe

