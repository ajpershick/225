all: test

test: test.o linkedlist.o node.o
	g++ -Wall test.o linkedlist.o node.o -o test

test.o: test.cpp linkedlist.h
	g++ -Wall -c test.cpp

linkedlist.o: linkedlist.h linkedlist.cpp node.h
	g++ -Wall -c linkedlist.cpp

node.o: node.h node.cpp
	g++ -Wall -c node.cpp

clean:
	rm -f test *.o