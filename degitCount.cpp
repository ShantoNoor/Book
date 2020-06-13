#include <iostream>

using namespace std;

int desgitCount(int n)
{
	if(n == 0)
		return 1;
	int count = 0;
	while(n != 0)
	{
		n = n/10;
		count++;
	}
	return count;
}s

int main()
{
	

	return 0;
}