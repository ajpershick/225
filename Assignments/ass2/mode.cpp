#include <iostream>
#include <fstream>
using namespace std;

// Here I've left the code as I found it, to show you
// a contrasting (and in my opinion, nowhere near as clear)
// style.  Many C++ coders have this style.


// Find the mode of an array.
//
// Parameters:
//  arr is an integer array with n elements
// Return value:
//  return the mode
//

// Input is the tmp of elements, followed by that many integers.
// Writes mode of elements to file specified as first command-line argument.

void printFunction(long *array, int n);
void quickSort(long *array, int left, int right, int n);
int partition(long *array, int left, int right);
long mode (long *array, int n);


int main (int argc,  char* argv[]) 
{

	// ofstream for writing result.
	ofstream outputfile;

	// Parse command-line arguments.
	if (argc != 2) {
		// Note that the program name is the first argument, so argc==1 if there are no additional arguments.
		cerr << "Expected one argument." << endl;
		cerr << "  Usage: " << argv[0] << " output_filename" << endl;
		return 1;
	} else {
		// Open the filename specified for input.
		outputfile.open (argv[1]);
	}


	// Read a set of elements into an array.
	int n;
	long *arr;

	// Get the tmp of elements
	cout << "Enter the tmp of elements:" << endl;
	cin >> n;

	// Create array in dynamic memory.
	arr = new long[n];

	for (int i=0; i<n; i++) {
		cout << "Enter a tmp:" << endl;
		cin >> arr[i];
	}

	long m = mode(arr,n);

	cout << "The mode is " << m << endl;

	outputfile << m << endl;
	outputfile.close();

	// Free up memory.  Note use of delete [], since this is an array.
	delete [] arr;

	return 0;
}


void printFunction(long *array, int n)
{
    int i = 0;

    while(i < n)
    {
        cout << array[i] << ",";
        i++;
    }

    cout << "\n";
}

int partition(long *array, int left, int right) 
{
    int mid = left + (right-left) / 2;
    int pivot = array[mid];

    // moves mid to front of the array
    swap(array[mid],array[left]);
    int i = left+1;
    int j = right;

    while (i <= j) 
    {

        while(array[i] <= pivot && i <= j) 
        {
            i++;
        }

        while(array[j] > pivot && i <= j) 
        {
            j--;
        }

        if (i < j) 
        {
            swap(array[j], array[i]);
        }
    }

    swap(array[j], array[i-1]);
    return i-1;
}

void quickSort(long *array, int left, int right, int n)
{

    if (left >= right) 
    {
        return;
    }

    int part = partition(array, left, right);
    printFunction(array, n);
    quickSort(array, left, part-1, n);
    quickSort(array, part+1, right, n);
}

long mode (long *array, int n) 
{
  // TO DO:: Fill in this function.


	quickSort(array, 0, n-1, n); // Sort the array first
	printFunction(array, n);

	int i = 1;
	int counter = 1;
	int modeCount = 1;
	int tmp = array[0];
	int mode = tmp;
	

	while( i < n)
	{
	    if (array[i] == tmp) 
	    {
	        counter++;
	    }
	      
	    else
	    {
	      	if (counter > modeCount) 
	        {
	              modeCount = counter;
	              mode = tmp;
	        }

	       	counter = 1;
	       	tmp = array[i];
		}	
		
		i++;
	}

	if (counter > modeCount) 
    {
          modeCount = counter;
          mode = tmp;
    }

  	return mode;
}

