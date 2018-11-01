all: heap_test heap_debug

heap_test: heap.o heap_test.cpp
	g++ -Wall heap.o heap_test.cpp -o heap_test

heap_debug: heap.o heap_debug.cpp
	g++ -Wall heap.o heap_debug.cpp -o heap_debug

heap.o: heap.h heap.cpp
	g++ -c heap.cpp


clean:
	rm -f heap_test heap_debug *.o