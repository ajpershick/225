#pragma once

#include <string>
#include <iostream>
using namespace std;


class Heap {
 public:
	// Create a heap with space for n numbers.
	Heap(int n);
	
	// Insert a value into a heap.
	bool insert(string n);
	// Remove and return the root of the heap.
	string remove();

	// Debugging methods.
	// Print out the contents of the heap.
	void printHeap();

	// Debug method, check the partial ordering property of the heap.
	bool isPartiallyOrdered();

	~Heap();


 private:
	// Array to hold the heap's data.
	string* arr;
	// Capacity of heap, i.e. size of arr.
	int capacity;

	// Number of items in the heap.
	int size;
	
	// Bubble down -- fix the heap from the root to the bottom.
	void bubbleDown(int i);

	// Bubble up -- fix the heap from a leaf to the root.
	void bubbleUp(int i);

	// Recursive helper to print the heap's contents.
	void printHeapRec(int i, int d);

	// Recursive helper to check partial ordering.
	bool isPartiallyOrderedRec(int i);
	
	

};
