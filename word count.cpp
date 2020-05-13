#include <iostream>

using namespace std;

int wordCount(string str)
{
	int count = 0;
	bool isWord = true;

	if(str[0] == ' ') 
		isWord = false;

	for(int i = 0; str[i] != '\0'; i++)
	{
		if(str[i] != ' ' && isWord)
		{
			count++;
			isWord = false;
		}
		else if(str[i] == ' ' && !isWord)
			isWord = true;
	}
	return count;
}

int main()
{
	string str;
	getline(cin, str);

	cout << str << endl;
	cout << wordCount(str) << endl;


	return 0;
}