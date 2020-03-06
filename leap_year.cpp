#include <iostream>
using namespace std;

int main()
{
    int x; cin >> x;

    // if(x % 400 == 0)
    //     cout << x << " is Leap Year!" << endl;
    // else if(x % 100 == 0)
    //     cout << x << " is NOT Leap Year!" << endl;
    // else if(x % 4 == 0)
    //     cout << x << " is Leap Year!" << endl;
    // else
    //     cout << x << " is NOT Leap Year!" << endl;

    if( (x % 400 == 0) | ( (x % 100 != 0) && (x % 4 == 0) ) )
        cout << x << " is Leap Year!" << endl;
    else
        cout << x << " NOT is Leap Year!" << endl;

    return 0;
}