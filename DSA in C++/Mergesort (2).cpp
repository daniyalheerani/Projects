#include <iostream>
using namespace std;

void mergeSort(int* array, int size)
{
	if(size > 1)
	{
        // 1st STEP : dividing the arrays into two
		int left[size/2+(size%2)]; //left array
        int right[size/2]; //right array
        int sizeLeft = size/2+(size%2); //size of left array
        int sizeRight = size/2; //size of right array
        for(int i = 0; i < sizeLeft; i++)
        {
            left[i] = array[i];
            if(i < sizeRight)
            {
                right[i] = array[i+sizeLeft];
            }
        }
		//sort left half
		mergeSort(left, sizeLeft);
		//sort right half
		mergeSort(right, sizeRight);
		//3rd STEP merge the two arrays
		int j = 0, k = 0; //left and right array index    
        for(int i = 0; i < size; i++)
        {
            if(j < sizeLeft && k < sizeRight)
            {
                if(left[j] < right[k])
                {
                    array[i] = left[j++];
                }
                else
                {
                    array[i] = right[k++];
                }
            }
            else if(j >= sizeLeft)
            {
                array[i] = right[k++];
            }	
            else
            {
                array[i] = left[j++];
            }
        }
    }
}

void printArray(int *array, int size)
{
	cout << "[";
	for(int i = 0; i < size; i++)
	{
		cout << array[i] << ", ";
	}
	cout << "\b\b]\n";
}

int main()
{
    int array[6] = {42, 3, 100, 56, -1, 0};
	cout << "Before Sorting:\n";
	printArray(array, 6);
	cout << "After using merge sort in ascending order:\n";
	mergeSort(array, 6);
	printArray(array, 6);
}