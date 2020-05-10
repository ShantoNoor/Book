#include <iostream>
using namespace std;


int main()
{
	int size;
	cin >> size;

	int arr[size], arr2[size];

	int temp = 0;
	for(int i = 0; i < size; i++)
	{
		cin >> arr[i];
		temp += arr[i];
		arr2[i] = temp;
	}

	int i, j;
	cin >> i >> j;
	if(i == 1)
		cout << "Sum Of " << i << " to " << j << " is : " << arr2[j-1] << endl;
	else
		cout << "Sum Of " << i << " to " << j << " is : " << arr2[j-1] - arr2[i-2] << endl;

	return 0;
}