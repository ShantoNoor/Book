#include <iostream>
using namespace std;

int main()
{
    int i, n, sum = 0;
    cin >> n;

    for(i = 1; i <= n; i++)
    {
        if(i%2)
        {
            sum += i;
        }
        else
        {
            sum -= i;
        }
    }

    cout << sum << endl;

    return 0;
}