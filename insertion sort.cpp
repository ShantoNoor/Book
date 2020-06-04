#include <iostream>

using namespace std;

#define size 5

void insertionSort(int arr[], int len)
{
	int i, j, temp;
	for(i = 1; i < len; i++)
	{
		j = i-1;
		temp = arr[i];
		while(arr[j] > temp && j >= 0)
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = temp;
	}
}

int main()
{
	
	int i, arr[size];

	for(i = 0; i < size; i++) cin >> arr[i];
	for(i = 0; i < size; i++) cout << arr[i] << " "; cout << endl;

	insertionSort(arr, size);

	for(i = 0; i < size; i++) cout << arr[i] << " "; cout << endl;

	return 0;
}