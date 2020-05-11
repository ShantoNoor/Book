#include <iostream>
using namespace std;

int main()
{
    int n, i, j, c;
    cin >> n;

    for(i = 0; i < n; i++)
    {
        c = 1;
        for(j = 0; j < n-i-1; j++)
        {
            cout << ".";
        }
        for(j = 0; j < i*2+1; j++)
        {
            if(c > 9)
                c = 1;
            cout << c;
            c++;
            if(c > i+1)
            {
                c = 1;
            }
        }
        for(j = 0; j < n-i-1; j++)
        {
            cout << ".";
        }
        cout << endl;
    }

    for(i = 1; i < n; i++)
    {
        c = 1;
        for(j = 0; j < i; j++)
        {
            cout << ".";
        }
        for(j = i; j < n*2-1-i; j++)
        {
            if(c > 9)
                c = 1;
            cout << c;
            c++;
            if(c > n-i)
            {
                c = 1;
            }
        }
        for(j = 0; j < i; j++)
        {
            cout << ".";
        }
        cout << endl;
    }

    return 0;
}