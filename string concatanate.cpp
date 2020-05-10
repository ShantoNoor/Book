#include <iostream>
#include <cstring>

using namespace std;


void concatenateCstr(char cstr1[], char cstr2[])
{
	int cstr1_len = strlen(cstr1);
	for(int i = 0; cstr2[i] != '\0'; i++)
	{
		cstr1[cstr1_len] = cstr2[i];
		cstr1_len++;
	}
	cstr1[cstr1_len] = '\0';
}

void concatenateCstrCopy(char cstr1[], char cstr2[], char cstr3[])
{
	int i;
	for(i = 0; cstr1[i] != '\0'; i++)
	{
		cstr3[i] = cstr1[i];
	}
	for(int j = 0; cstr2[j] != '\0'; i++, j++)
	{
		cstr3[i] = cstr2[j];
	}
	cstr3[i] = '\0';
}

int main()
{
	// string str1 = "water";
	// string str2 = "melon";
	// string str3 = str1+str2;

	char cstr1[15] = "water";
	char cstr2[15] = "melon";
	char cstr3[15];
	// strcpy(cstr3, cstr1);
	// strcat(cstr3, cstr2);

	//concatenateCstr(cstr1, cstr2);
	concatenateCstrCopy(cstr1, cstr2, cstr3);


	cout << cstr1 << endl;
	cout << cstr3 << endl;

	return 0;
}