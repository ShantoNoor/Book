#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int x, y, z, temp, counter = 0;
	int n, sum = 1;

	for(n = 1; n <= 27; n++)
	{
		for (x = 0; x < 10; x++)
		{
			for (y = 0; y < 10; y++)
			{
				for (z = 0; z < 10; z++)
				{
					temp = x + y + z;
					if(temp == n) counter++;
				}
			}
		}
		sum += counter*counter;
		cout << setw(2) << n << " " << setw(2) << counter << endl;
		counter = 0;
	}

	std::cout << sum << std::endl;

	return 0;
}