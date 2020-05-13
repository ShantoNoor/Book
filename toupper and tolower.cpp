#include <iostream>

using namespace std;

string tolower(string str)
{
	for(unsigned int i = 0; i < str.size(); i++)
	{
		if(str[i] >= 'A' && str[i] <= 'Z')
			str[i] |= 32; 
	}
	return str;
}

string toupper(string str)
{
	for(unsigned int i = 0; i < str.size(); i++)
	{
		if(str[i] >= 'a' && str[i] <= 'z')
			str[i] &= -33; 
	}
	return str;
}


int main()
{
	cout << tolower("SHANTO") << endl;
	cout << toupper("shanto") << endl;

	return 0;
}