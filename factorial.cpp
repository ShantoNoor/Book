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

int stack_factorial(int a)
{
    if(a == 1)
        return 1;
    return a*stack_factorial(a-1);
}

int main()
{
    int n = 3;

    cout << factorial(n++) << endl;
    cout << factorial(n++) << endl;
    cout << factorial(n++) << endl;
    cout << factorial(n++) << endl;

    n = 3;

    cout << stack_factorial(n++) << endl;
    cout << stack_factorial(n++) << endl;
    cout << stack_factorial(n++) << endl;
    cout << stack_factorial(n++) << endl;

    return 0;
}