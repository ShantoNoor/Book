#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    long n = 0, i, x, y, fs, fv;
    long size; cin >> size;

    ofstream fp;
    fp.open("Palindrome.txt");

    for(i = 0; n != size; i++)
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
                cout << x << " ";
                fp << x << " ";
                if(n % 10 == 0)
                {
                    cout << endl;
                    fp << endl;
                }
                n++;
            }
    }

    fp.close();

    return 0;
}