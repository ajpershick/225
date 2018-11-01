#include <iostream>
#include "heap.h"
using namespace std;

#define HEAP_SIZE 200

int main (void) {

	Heap h(HEAP_SIZE);

	int n_insert;

	// Get number of words to be inserted.
	cin >> n_insert;

	string word;
	for (int i=0; i<n_insert; i++) {
		cin >> word;
		// Attempt to insert word.  If heap is full, exit program with return code 1.
		if (!h.insert(word))
			return 1;
	}

	for (int i=0; i<n_insert; i++) {
		cout << h.remove() << endl;
	}

	return 0;
}
