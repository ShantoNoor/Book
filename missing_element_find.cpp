#include <iostream>

using namespace std;

int single_missing(int arr[], int len)
{
	int dif = arr[0];
	for (int i = 1; i < len; i++)
	{
		if(arr[i] - i != dif)
		{
			while(dif < arr[i] - i)
			{
				printf("%d ", dif + i);
				dif++;
			}

		}
	}
	return 0;
}

int findSingleMissingElement(int arr[], int len)
{
	int sum = 0;
	for (int i = 0; i < len; i++)
	{
		sum += arr[i];
	}
	len = len*(len+1)/2;
	return len - sum;
}

void printMissingElementOfUnsortedArray(int arr[], int len)
{
	int max = arr[0];
	for (int i = 1; i < len; i++)
	{
		if(max < arr[i])
			max = arr[i];
	}
	max += 1;
	int arra[max] = {0};
	for (int i = 0; i < len; i++)
	{
		arra[arr[i]]++;
	}
	for (int i = 1; i < max; i++)
	{
		if(arra[i] == 0)
			printf("%d ", i);
	}
}

void findDuplicateElements(int arr[], int len)
{
	int prev_dup = -100;
	for (int i = 0; i < len - 1; i++)
	{
		if(arr[i] == arr[i+1] && prev_dup != arr[i])
		{
			int j = i;
			while(arr[i] == arr[j]) j++;
			printf("%d %d\n", arr[i], j-i);
			prev_dup = arr[i];
			i = j - 1; // <---Importent!!
		}
	}
}

void unsortedFindDuplicateElements(int arr[], int len)
{
	for (int i = 0; i < len-1; i++)
	{
		if(arr[i] == -1)
			continue;
		int count = 1;
		for (int j = i+1; j < len; j++)
		{
			if(arr[i] == arr[j])
			{
				count++;
				arr[j] = -1; //<--Importent!!
			}
		}
		if(count > 1)
			printf("%d %d\n", arr[i], count);
	}
}

void findPair(int arr[], int len, int n)
{
	int i = 0;
	int j = len - 1;
	while(i < j)
	{
		if(arr[i]+arr[j] == n)
		{
			printf("%d %d\n", arr[i], arr[j]);
			i++;
			j--;
		} 
		else if(arr[i]+arr[j] < n)
			i++;
		else
			j--;
	}
}

int main()
{
	int ara[10] = {1, 3, 4, 5, 6, 8, 9, 10, 12, 14};

	findPair(ara, 10, 10);

	return 0;
}