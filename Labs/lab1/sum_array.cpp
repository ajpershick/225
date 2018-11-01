#include <iostream>

int sumArray(int arr[], int arrSize)
{
	int sum = 0;

	for (int i = 0; i < arrSize; i++)
	{
		sum = arr[i] + sum;
	}

	return sum;
}

int main()
{
	int arrSize = 0;
	std::cout << "How many numbers are you going to type?" << std::endl;
	std::cin >> arrSize;
	int *arr;
	arr = new int[arrSize];
	for (int i = 0; i < arrSize; i++)
	{
		std::cout << "Please type a number my dudeeee :" << std::endl;
		std::cin >> arr[i];
	}

	int sum = sumArray(arr, arrSize);
	delete [] arr;
	std::cout << "The total is: " << sum << std::endl;
	return sum;
}