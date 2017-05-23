all: Weekday_statistics.o count_13th.o

Weekday_statistics.o: Weekday_statistics.cpp Weekday_statistics.hpp
	g++ -std=c++11 -c Weekday_statistics.cpp

count_13th.o: count_13th.cpp count_13th.cpp
	g++ -std=c++11 -c count_13th.cpp

tests: tests.exe
	./tests.exe

tests.exe: Weekday_statistics.o count_13th.o tests.o
	g++ -std=c++11 -o tests.exe tests.o Weekday_statistics.o count_13th.o

tests.o: tests.cpp
	g++ -std=c++11 -c tests.cpp

clean:
	rm -f Weekday_statistics.o count_13th.o
	rm -f tests.o
	rm -f tests.exe

