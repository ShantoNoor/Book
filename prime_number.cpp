#include <iostream>
using namespace std;

bool isPrire(int a)
{
    if(a == 1)
        return 0;
    else if(a == 2 || a == 3)
        return 1;
    else
    {
        for(int i = 2; i < a; i++)
        {
            if(a % i == 0)
            {
                return 0;
            }
        }
        return 1;
    }
}

int main()
{
    int n;
    cin >> n;

    if(isPrire(1))
        cout << "Prime!" << endl;
    else
        cout << "Not Prime!" << endl;
    if(isPrire(n))
        cout << "Prime!" << endl;
    else
        cout << "Not Prime!" << endl;

    return 0;
}