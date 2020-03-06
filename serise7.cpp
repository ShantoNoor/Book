#include <iostream>
using namespace std;

int main()
{
    int i, n, sum = 0;
    cin >> n;

    for (i = 1; n != 0; n--, i++)
    {
        sum = sum + i*n;
    }
    
    cout << sum << endl;

    return 0;
}