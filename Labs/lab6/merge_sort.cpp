#include <iostream>
using namespace std;

void mergeSort(int arr[], int low, int high);
void merge(int arr[], int low, int mid, int high);


// Perform mergeSort to sort an array of integers.
// Inputs:
//   arr is the input array of arrSize integers.
//   low and high are the indices to sort to/from, e.g. 0 arrSize-1 to sort entire array
// Postcondition:
//   arr[low] ... arr[high] will contain the original values, sorted in increasing order.
void mergeSort(int arr[], int low, int high) 
{
// TO DO:: Fill in this code.
	int mid;

	if (low < high)	// base case
	{
	      
		mid = (low + high) / 2;
		mergeSort(arr, low, mid);
		mergeSort(arr, mid + 1, high);
		merge(arr, low, mid, high);
	}
	
}


// Perform a merge of two sorted sub-arrays.
// Inputs:
//   arr is the input array on which to perform a merge.
//   low-mid and (mid+1)-high are the two sub-arrays to merge.
// Precondition:
//   arr[low]...arr[mid] is sorted in increasing order.
//   arr[mid+1]...arr[high] is sorted in increasing order.
//   These should be disjoint, contiguous sub-arrays too.
// Postcondition:
//   arr[low]...arr[high] is sorted in increasing order.
void merge(int arr[], int low, int mid, int high) 
{
// TO DO:: Fill in this code.

	int i = 0;
	int j = 0;
	int k = 0;
    int start1 = mid - low + 1;
    int start2 =  high - mid;
 
    // create temporary arrays 
    int tempLeft[start1], tempRight[start2];
 
    // Copy data to temp arrays L[] and R[] 
    for (i = 0; i < start1; i++)
        tempLeft[i] = arr[low + i];
    for (j = 0; j < start2; j++)
        tempRight[j] = arr[mid + 1 + j];
 
    // Merge the temp arrays back into arr[l..r]
    i = 0; 
    j = 0; 
    k = low; 
    while (i < start1 && j < start2)
    {
        if (tempLeft[i] <= tempRight[j])
        {
            arr[k] = tempLeft[i];
            i++;
            k++;
        }
        
        else
        {
            arr[k] = tempRight[j];
            j++;
            k++;
        }
       
    }
 
    // Copy remaining elements of tempLeft[] 
    while (i < start1)
    {
        arr[k] = tempLeft[i];
        i++;
        k++;
    }
 
    // Copy remaining elements of tempRight[]
    while (j < start2)
    {
        arr[k] = tempRight[j];
        j++;
        k++;
    }

}


// A driver program to test mergeSort.
// Reads in a number of integers (number, then sequence of values).
// Sorts using mergeSort.
// Prints the values in sorted order.
int main (void) {
	int n;

	// Get the number of values.
	//	cout << "Enter the number of values to be sorted:" << endl;
	cin >> n;

	// Create array in dynamic memory.
	int *values;
	values = new int[n];

	for (int i=0; i<n; i++) {
		// cout << "Enter a number:" << endl;
		cin >> values[i];
	}

	// Call mergeSort to sort entire array.
	mergeSort(values,0,n-1);

	// Print values, should be sorted.
	for (int i=0; i<n; i++) {
		cout << values[i] << " ";
	}
	cout << endl;


	// Free the dynamic memory we allocated.
	// Note use of delete [], since this is an array.
	delete [] values;

	return 0;
}
