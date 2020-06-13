#include <iostream>

using namespace std;

void printPermute(string str, int k)
{
	static char res[20];
	static int arr[20] = {0};

	if(str[k] == '\0')
	{
		res[k] = '\0';
		cout << res << " ";
		return;
	}

	for (unsigned int i = 0; i < str.size(); i++)
	{
		if(arr[i] == 0)
		{
			res[k] = str[i];
			arr[i] = 1;
			printPermute(str, k+1);
			arr[i] = 0;
		}
	}
}

void printPermute2(string str, int l, int h)
{
	if(l == h)
	{
		cout << str << " ";
		return;
	}
	for (int i = l; i <= h; i++)
	{
		if(l != i)
		{
			char temp = str[l];
			str[l] = str[i];
			str[i] = temp;
		}
		printPermute2(str, l+1, h);
		if(l != i)
		{
			char temp = str[l];
			str[l] = str[i];
			str[i] = temp;
		}
	}
}

int main()
{
	printPermute("abc", 0);
	cout << endl;

	string str = "abc";
	printPermute2(str, 0, str.size()-1);
	cout << endl;

	return 0;
}