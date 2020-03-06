#include <iostream>
#include <stdio.h>
using namespace std;

#define size 2147483648

int main()
{
    long long i, j = 1;

    FILE *fp;
    fp = fopen("a.txt", "w");

    for(i = 0; i < size; i++)
    {
        j = j+i;
        if(j % 3 == 0)
        {
            fprintf(fp, "%lld\n", j);
            cout << j << endl;
        }
    }

    fclose(fp);

    return 0;
}