#include <iostream>
using namespace std;

void buble_sort(int arr[], int n)
{
    int i, j;
    bool itreted;
    for(i = 0; i < n - 1; i++)
    {
        itreted = false;
        for(j = 0; j+1 < n-i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                itreted = true;
                arr[j] = arr[j] + arr[j+1];
                arr[j+1] = arr[j] - arr[j+1];
                arr[j] = arr[j] - arr[j+1];
            }
        }
        if(!itreted)
        {
            i = n;
        }
    }
}

int main()
{
    int arr[5] = {3,2,5,1,4};

    for(int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout<<endl;
    
    buble_sort(arr, sizeof(arr)/4);

    for(int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout<<endl;
    int x;

    return 0;
}