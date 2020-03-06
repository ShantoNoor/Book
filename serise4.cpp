#include <iostream>
using namespace std;

int main()
{
    int i, j, k = 1, sum = 0, n;
    cin >> n;

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= i; j++)
        {
            sum = sum + k;
            k++;
        }
    }

    cout << sum << endl;

    return 0;
}