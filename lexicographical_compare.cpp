#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int lexicographicalCompare(string str, string str2)
{
	if(str == str2)
		return 0;
	else if(str < str2)
		return 1;
	else
		return -1;
}

int lexicographicalCompareCstr(const char str[], const char* str2)
{
	int i;
	for(i = 0; str[i] != '\0' && str2[i] != 0; i++)
	{
		if(str[i] != str2[i])
		{
			if(str[i] < str2[i])
				return 1;
			else
				return -1;
		}
	}
	if(str[i] == '\0' && str2[i] == '\0')
		return 0;
	else if(str[i] == '\0' && str2[i] != '\0')
		return 1;
	else
		return -1;
}

int main()
{
	string str = "abcf";
	string str2 = "abce";

	string::iterator it = str.begin();
	string::iterator it2 = str2.begin();

	cout << lexicographical_compare(it, it+6, it2, it2+str2.size()) << endl;

	cout << lexicographicalCompare(str, str2) << endl;

	cout << lexicographicalCompareCstr(str.c_str(), str2.c_str()) << endl;

	return 0;
}