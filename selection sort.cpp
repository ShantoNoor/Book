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
	int arr[] = {1, 3, 1, 2, 4,3,0};
	selection_sort(arr, sizeof(arr)/4);
	for(int a : arr)
		cout << a << endl;

	return 0;
}