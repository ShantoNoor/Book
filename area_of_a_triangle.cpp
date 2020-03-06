#include <iostream>
#include <math.h>
using namespace std;

double tri_area_with_cordinates(double arrx[3], double arry[3])
{
    return ( ( ( arrx[0]*arry[1] + arrx[1]*arry[2] + arrx[2]*arry[0] ) - ( arry[0]*arrx[1] + arry[1]*arrx[2] + arry[2]*arrx[0] ) ) / 2 );
}

double triangle_area(double a, double b, double c)
{
    double s;
    s = (a+b+c)/2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

int main()
{
    cout << triangle_area(3, 4, 5) << endl;

    return 0;
}