#include "heap.h"
#include <cmath>


// Create a heap with space for n numbers.
Heap::Heap(int n) {
	arr = new string[n];
	capacity = n;
	size = 0;
}

Heap::~Heap() {
	delete[] arr;
}

// Insert a value into a heap.
// TO DO:: You need to write this.
bool Heap::insert(string n) 
{
	if (size == capacity)
	{
		return false;
	}
	else
	{
		size++;
		arr[size-1] = n;
		bubbleUp(size-1);
	}
	return true;
}

// Bubble up -- fix heap from a node up to the top.
void Heap::bubbleUp(int i) 
{
	if (i == 0)
	{
		return;
	}

	int parent = std::floor((i-1)/2);
	
	if (arr[parent] > arr[i])
	{
		string tmp = arr[i];
		arr[i] = arr[parent];
		arr[parent] = tmp;
		bubbleUp(parent);
	}	
}


// Remove and return the root of the heap.
string Heap::remove() {
	// Make sure the heap has something in it.
	if (size==0) {
		return "";
	}
	// Get the item to return.
	string rtn_string = arr[0];
		
	// Copy rightmost leaf into 0 position.
	arr[0] = arr[size-1];
	size--;
		
	// Bubble down the first element into its correct position.
	bubbleDown(0);
		
	return rtn_string;
}
	
// Bubble down -- fix the heap from the root to the bottom.
void Heap::bubbleDown(int i) {
	// Find smaller of children.
	int lchild = 2*i+1;
	int rchild = 2*i+2;
	int swap = i;
		
	// No children, stop.
	if (lchild > size-1) {
		return;
	}
		
	if (arr[i] > arr[lchild]) {
		swap = lchild;
	}
	// Check if there is a right child.
	if (rchild < size) {
		if (arr[swap] > arr[rchild]) {
			swap = rchild;
		}
	}
		
	// Swap arr[i] with smaller of children.
	if (swap != i) {
		string tmp = arr[i];
		arr[i] = arr[swap];
		arr[swap] = tmp;
		
		// Rinse and repeat.
		bubbleDown(swap);
	}
}
	



// Debugging methods.

// Print out the contents of the heap.
void Heap::printHeap() {
	printHeapRec(0,0);
}


// Recursive helper to print the heap's contents.
void Heap::printHeapRec(int i, int d) {
	if (i < size) {
		// Perform post-order traversal.
		// Print the right subtree
		printHeapRec(2*i+2,d+1);

		// Then print node at index i at its correct depth.
		//			int level = (int) Math.floor(Math.log(i+1)/Math.log(2));
		int level = d;
		for (int l=0; l<level; l++) cout << "  ";
		cout << "--";
		cout << arr[i] << endl;

		// Then print the left subtree.
		printHeapRec(2*i+1,d+1);
	}
}


// Debug method, check the partial ordering property of the heap.
bool Heap::isPartiallyOrdered() {
	return isPartiallyOrderedRec(0);
}

	
bool Heap::isPartiallyOrderedRec(int i) {
	if (2*i+1 > size-1) {
		// If i has no children.
		return true;
	} else if (2*i+2 > size-1) {
		// Check a node with only a left child.
		return arr[i] < arr[2*i+1];
	} else {
		// If i has two children.
		if ((arr[i] < arr[2*i+1]) && (arr[i] < arr[2*i+2])) {
			return isPartiallyOrderedRec(2*i+1) && isPartiallyOrderedRec(2*i+2); 
		} else {
			return false;
		}
	}
}
