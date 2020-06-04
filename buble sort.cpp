#include <iostream>
using namespace std;

void buble_sort(int arr[], int len)
{
	bool is_it;
	for(int i = 0; i < len - 1; i++)
	{
		is_it = false;
		for(int j = i+1; j < len; j++)
		{
			if(arr[i] > arr[j])
			{
				is_it = true;
				arr[i] ^= arr[j];
				arr[j] ^= arr[i];
				arr[i] ^= arr[j];
			}
		}
		if(!is_it)
			i = len;
	}
}

int main()
{
	int arr[] = {1, 3, 1, 2, 4,3,0};
	buble_sort(arr, sizeof(arr)/4);
	for(int a : arr)
		cout << a << endl;
	
	
	return 0;
}