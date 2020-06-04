#include <iostream>
using namespace std;

bool compare(int x, int y)
{
    return x > y;
}

void insertion_sort(int ara[], int ara_size)
{
    int i, j, item;
    for(i = 1; i < ara_size; i++)
    {
        j = i - 1;
        item = ara[i];
        while(compare(ara[j], item) && j >= 0)
        {
            ara[j+1] = ara[j];
            j--;
        }
        ara[j+1] = item;
    }
}

int main()
{
    int arr[5] = {5, 3, 4, 2, 1};

    insertion_sort(arr, 5);

    for(int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    

    return 0;
}