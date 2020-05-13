#include <iostream>

using namespace std;

void copyStr(string str, char arr[])
{
	unsigned int i;
	for(i = 0; i < str.size(); i++)
		arr[i] = str[i];
	arr[i] = '\0';
}

int cstr_len(const char cstr[])
{
	int i;
	for(i = 0; cstr[i] != '\0'; i++);
	return i;
}

int main()
{
	string str = "shanto";
	char name[str.size()+1];
	copyStr(str, name);

	cout << name << endl;
	cout << str.size() << " " << cstr_len(name) << endl;

	return 0;
}