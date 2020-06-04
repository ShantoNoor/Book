#include <iostream>
#include <cmath>

using namespace std;

float path(float x1, float y1, float x2, float y2)
{
	return sqrt(pow(x1-x2, 2)+pow(y1-y2, 2));
}

int main()
{
	cout << path(0.5, 0.5, 2.5, 0.5) << endl;
	cout << path(2.5, 0.5, 2.5, 2.5) << endl;
	cout << path(2.5, 2.5, 0.5, 2.5) << endl;
	cout << path(0.5, 2.5, 0.5, 0.5) << endl;

	return 0;
}