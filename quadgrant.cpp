#include <iostream>
using namespace std;

int main()
{
    int x, y;
    cin >> x >> y;

    if(x >= 0 && y >= 0)
    {
        cout << "First!" << endl;
    }
    else if(x >= 0 && y < 0)
    {
        cout << "Fourth!" << endl;
    }
    else if(x < 0 && y >= 0)
    {
        cout << "Secound!" << endl;
    }
    else if(x < 0 && y < 0)
    {
        cout << "Third!" << endl;
    }

    return 0;
}