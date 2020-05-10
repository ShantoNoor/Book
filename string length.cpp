#include <iostream>
// #include <string>

using namespace std;

int stringSize(string str)
{
	int count  = 0;
	for(int i = 0; str[i] != '\0'; i++)
		count++;
	return count;
}

int cstr_len(const char cstr[])
{
	int i;
	for(i = 0; cstr[i] != '\0'; i++);
	return i;
}

int main()
{
	string name = "shanto noor";
	cout << stringSize(name) << endl;
	cout << name.size() << endl;
	cout << name.length() << endl;
	cout << name.capacity() << endl;

	cout << cstr_len("shantoNoor") << endl;

	return 0;
}