#include <iostream>

using namespace std;

int nToDec(int n, int b)
{
	int res = 0;
	int desgit;
	int power = 0;
	while(n != 0)
	{
		desgit = n % 10;
		for (int i = 0; i < power; i++)
			desgit *= b;
		res += desgit;
		n = n/10;
		power++;
	}
	return res;
}

int main()
{
	

	return 0;
}