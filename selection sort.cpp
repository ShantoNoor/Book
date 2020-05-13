#include <iostream>
using namespace std;

void selection_sort(int arr[], int len)
{
	int minIndex;
	for(int i = 0; i < len - 1; i++)
	{
		minIndex = i;
		for(int j = i+1; j < len; j++)
		{
			if(arr[minIndex] > arr[j])
			{
				minIndex = j;
			}
		}
		if(minIndex != i)
		{
			arr[minIndex] ^= arr[i];
			arr[i] ^= arr[minIndex];
			arr[minIndex] ^= arr[i];
		}
	}
}

int main()
{
	int arr[] = {1, 3, 1, 2, 4,32,12,2412,43,434,32,34254,353,656,456,245,32423,3565,76,787,4,2,423,23423,4534,3,0};
	selection_sort(arr, sizeof(arr)/4);
	for(int a : arr)
		cout << a << " ";

	return 0;
}