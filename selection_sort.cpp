#include <iostream>
using namespace std;

void selection_sort(int arr[], int n)
{
    int i, indexOfSmallest, j;
    for(i = 0; i < n - 1; i++)
    {
        indexOfSmallest = i;
        for(j = i+1; j < n; j++)
        {
            if(arr[indexOfSmallest] > arr[j])
            {
                indexOfSmallest = j;
            }
        }
        if(indexOfSmallest != i)
        {
            arr[indexOfSmallest] = arr[indexOfSmallest] + arr[i];
            arr[i] = arr[indexOfSmallest] - arr[i];
            arr[indexOfSmallest] = arr[indexOfSmallest] - arr[i];
        }
    }
}

int main()
{
    int arr[5] = {3,4,2,1,5};

    for(int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout<<endl;

    selection_sort(arr, sizeof(arr)/4);
    
    for(int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout<<endl;

    return 0;
}