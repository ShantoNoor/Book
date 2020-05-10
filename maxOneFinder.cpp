#include <iostream>

using namespace std;

int maxOneCount(string str)
{
	int count = 0;
	int temp = 0;
	for(unsigned int i = 0; i < str.size(); i++)
	{
		if(str[i] == '1')
			temp++;
		else if(str[i] != '1' && count < temp)
		{
			count = temp;
			temp = 0;
		}
		else
			temp = 0;
	}
	return count;
}

int main()
{
	cout << maxOneCount("1000100111001010111111111100001") << endl;

	return 0;
}