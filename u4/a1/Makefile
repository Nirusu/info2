all: Orange.o reverse_quick_sort.o

Orange.o: Orange.cpp Orange.hpp
	g++ -std=c++11 -c Orange.cpp

reverse_quick_sort.o: Orange.o reverse_quick_sort.cpp reverse_quick_sort.hpp
	g++ -std=c++11 -c reverse_quick_sort.cpp

tests: tests.exe
	./tests.exe

tests.exe: Orange.o reverse_quick_sort.o tests.o
	g++ -std=c++11 -o tests.exe tests.o Orange.o reverse_quick_sort.o

tests.o: tests.cpp
	g++ -std=c++11 -c tests.cpp

clean:
	rm -f Orange.o
	rm -f reverse_quick_sort.o
	rm -f tests.o
	rm -f tests.exe

