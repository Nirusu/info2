all: string_hash.o Hash_table.o

string_hash.o: string_hash.cpp string_hash.hpp
	g++ -std=c++11 -c string_hash.cpp

Hash_table.o: string_hash.o Hash_table.cpp Hash_table.hpp
	g++ -std=c++11 -c Hash_table.cpp

tests: tests.exe
	./tests.exe

tests.exe: string_hash.o Hash_table.o tests.o
	g++ -std=c++11 -o tests.exe tests.o string_hash.o Hash_table.o

tests.o: tests.cpp
	g++ -std=c++11 -c tests.cpp

clean:
	rm -f string_hash.o
	rm -f Hash_table.o
	rm -f tests.o
	rm -f tests.exe

