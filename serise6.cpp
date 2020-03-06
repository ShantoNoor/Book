#include <iostream>
using namespace std;

int main()
{
    int i, j, k, c = 1, sum = 0, temp;
    int n; cin >> n;

    for(i = 1; i <= n; i++)
    {
        sum = sum + c;
        c++;
        for(k = 1; k < i; k++)
        {                  
            temp = c;
            for(j = 1; j <= k; j++)
            {
                c++;
                temp = temp * c;  
            }
            sum = sum + temp;
            c++;
        }
    }

    cout << sum << endl;

    return 0;
}