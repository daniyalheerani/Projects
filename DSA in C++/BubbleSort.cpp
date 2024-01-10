#include <iostream>
using namespace std;

void printArray(int *array, int size)
{
	cout << "[";
	for(int i = 0; i < size; i++)
	{
		cout << array[i] << ", ";
	}
	cout << "\b\b]\n";
}

void ascendingBubbleSort(int *array, int size)
{
	for(int i = size-1; i > 0; i--)
	{
		for(int j = 0; j < i; j++)
		{
			if(array[j] > array[j+1])
			{
				int temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}
}


int main()
{
	int array[6] = {42, 3, 100, 56, -1, 0};
	cout << "Before Sorting:\n";
	printArray(array, 6);
	cout << "After Sorting in ascending order:\n";
	ascendingBubbleSort(array, 6);
	printArray(array, 6);
}
