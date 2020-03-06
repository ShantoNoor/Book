#include <iostream>
using namespace std;

int main()
{
    int n, i, sum = 0;
    cin >> n;

    for (i = 1; i <= n; i++)
    {
        sum = sum + ( i*(n-i+1) );
    }

    cout << sum << endl;

    return 0;
}