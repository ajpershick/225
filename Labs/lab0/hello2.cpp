#include <iostream>
#include <fstream>
using namespace std;

int main (void) 
{
	ifstream input("3.in");
	int x = 0;
	input >> x;

	ofstream output("3.out");
	if (x == 42)
	{
		output << "Shh!";
	}
	else
	{
		output << "Hello world!";
	}
	output.close();
    return 0;
}