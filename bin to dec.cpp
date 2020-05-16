#include <iostream>
using namespace std;

int binToDec(string str)
{
	int result = 0;
	int temp = 0;
	for(int i = str.size() - 1, k = 0; i >= 0; i--, k++)
	{
		temp = 0;
		if(str[i] == '1')
		{
			temp = 1;
			for(int j = 0; j < k; j++)  
				temp *= 2; 
		}
		result += temp;
	}
	return result;
}

int main()
{
	cout << binToDec("1010") << endl;
	cout << binToDec("111") << endl;
	cout << binToDec("10000") << endl;
	cout << binToDec("10101") << endl;

	int o;

	return 0;
}