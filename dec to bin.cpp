#include <iostream>
#include <string>
#include <algorithm>
#include <bitset>
#include <iomanip>

using namespace std;

string decToBin(int x)
{
	string str;
	while(x != 0)
	{
		if(x&2)
			str.push_back('1');
		else
			str.push_back('0');
		x = x/2;
	}
	reverse(str.begin(), str.end());
	return str;
}

// bitset<8> decTbin(int x)
// {
// 	return bitset<26>(x);
// }

int main()
{
	cout << decToBin(1994897);

	return 0;
}