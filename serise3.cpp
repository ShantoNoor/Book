#include <iostream>
using namespace std;

int main()
{
    int n; cin >> n;
    int sum = 0;
    int i, j;
    int temp;

    for (i = 1; i <= n; i++)
    {
        temp = 1;
        for(j = 1; j <= i; j++)
        {
            temp = temp*i;
        }
        sum = sum + temp;
    }

    cout << sum << endl;

    return 0;
}