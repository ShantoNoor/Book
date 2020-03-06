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

int power(int a, int b)
{
    int i, result = 1;
    for(i = 0; i < b; i++)
    {
        result = result * a;
    }
    return result;
}

double maCosX(int x, int n)
{
    int i;
    double result = 1, temp, temp1, temp2;
    bool notMinus = true; //minus checker
    for(i = 1; i < n; i++)
    {
        temp1 = power(x, i*2); 
        temp2 = factorial(i*2);
        temp = temp1 / temp2;
        if(notMinus)
        {
            notMinus = false;
            result -= temp;
        }
        else
        {
            notMinus = true;
            result += temp;
        }
    }
    return result;
}

int main()
{
    //int x, n;
    //cin >> x >> n;
    //x = 1, n = 3;

    cout << maCosX(1,17) << endl;

    return 0;
}