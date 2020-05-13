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

int nPr(int n, int r)
{
    return ( factorial(n) / factorial(n - r) );
}

int main()
{
	cout << nPr(3, 2) << endl;

	return 0;
}