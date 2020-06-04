#include <iostream>

using namespace std;

int main()
{
	for (int i = 1; i < 6; ++i)
	{
		cout << i%4 << " ";
		cout << 4%i << endl;
	}

	return 0;
}