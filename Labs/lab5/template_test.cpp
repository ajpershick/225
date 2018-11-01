#include "LinkedList.h"
#include <string>
#include <iostream>
using namespace std;

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	
	LinkedList<int> list;
	list.add(14);
	list.add(20);
	list.add(26);

	list.printList(cout);
	cout << endl;

	LinkedList<int> l2(list);
	l2.printList(cout);
	cout << endl;

	LinkedList<string> list2;
	list2.add("Hey");
	list2.add("What's up");

	list2.printList(cout);
	cout << endl;

	list2.remove("Hey");

	list2.printList(cout);
	cout << endl;

	return 0;
}
