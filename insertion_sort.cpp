#include <iostream>
using namespace std;

void insertion_sort(int ara[], int ara_size)
{
    int i, j, temp;
    for(i = 1; i < ara_size; i++)
    {
        j = i - 1;
        while(ara[j] > ara[j+1] && j >= 0)
        {
            temp = ara[j];
            ara[j] = ara[j+1];
            ara[j+1] = temp;
            j--;
        }
    }
}

int main()
{
    int arr[5] = {5,3,4,2,1};

    insertion_sort(arr, 5);

    for(int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout<< 7.2e-8 <<endl;
    
    printf("%lf\n", 7.2e-8);

    return 0;
}