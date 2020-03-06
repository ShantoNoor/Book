#include <iostream>
using namespace std;

int factorial(int a)
{
    int i, result = 1;
    for(i = a; i > 0; i--)
    {
        result = result*i;
    }
    return result;
}

int nCr(int n, int r)
{
    return ( factorial(n) / ( factorial(r) * factorial(n-r) ) );
}

int main()
{
    int n = 6, r = 0;

    cout << nCr(n, r) << endl;
    r++;
    cout << nCr(n, r) << endl;
    r++;
    cout << nCr(n, r) << endl;
    r++;
    cout << nCr(n, r) << endl;
    r++;
    cout << nCr(n, r) << endl;
    r++;
    cout << nCr(n, r) << endl;
    r++;
    cout << nCr(n, r) << endl;
    r++;

    return 0;
}