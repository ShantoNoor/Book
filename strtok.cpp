#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	char arr[11] = "01/02/2001";
	char* a = strtok(arr, "/");

	//while(a)
	{
		cout << a << endl; a++;
		cout << a << endl;
	}

	return 0;
}