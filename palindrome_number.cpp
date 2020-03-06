#include <iostream>
using namespace std;

#define size 100

int main()
{
    int n = 0, i, x, y, fs, fv;
    int arr[size];

    for(i = 0; n != size; i++)
    {
        if(i >= 0 && i < 9 )
        {
            arr[n] = i+1;
            n++;
        }
        else
        {
            x = i+1;
            fv = x;
            y = 0;
            while(fv != 0)
            {
                fs = fv % 10;
                y = y*10 + fs;
                fv = fv / 10;
            }
            if(x == y)
            {
                arr[n] = x;
                n++;
            }
        }
        
    }

    for(i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout<<endl;
    
    int q; cin >> q;
    cout << endl;
    cout << arr[q-1] << endl;

    return 0;
}