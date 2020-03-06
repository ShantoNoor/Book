#include <iostream>
#include <math.h>
using namespace std;

double angle(double a, double b, double c)
{
    return acos( ( b*b + c*c - a*a ) / ( 2*b*c ) );
}

double radian_to_degree(double a)
{
    return ( a*( 180 / acos(-1) ) );
}

void print_all_angles(double a, double b, double c)
{
    cout << radian_to_degree(angle(a, b, c)) << endl;
    cout << radian_to_degree(angle(b, c, a)) << endl;
    cout << radian_to_degree(angle(c, a, b)) << endl;
}

int main()
{
    double a, b, c;
    cin >> a >> b >> c;

    print_all_angles(a, b, c);

    return 0;
}