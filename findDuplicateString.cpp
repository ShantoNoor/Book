#include <iostream>

using namespace std;

void findDup(string str)
{
	for (unsigned int i = 0; i < str.size()-1; i++)
	{
		if(str[i] == '0')
			continue;
		int count = 1;
		for (unsigned int j = i+1; j < str.size(); j++)
		{
			if(str[i] == str[j] /*&& str[i] != '0'*/)
			{
				count++;
				str[j] = '0'; //<---Importent
			}
		}
		if(count > 1)
			printf("%c %d\n", str[i], count);
	}
}

void findDuplicateWithHashTable(string str)
{
	int H[26] = {0};
	for (unsigned int i = 0; i < str.size(); i++)
	{
		H[str[i]-97]++;
	}
	for (int i = 0; i < 26; i++)
	{
		if(H[i] > 1)
			printf("%c %d\n", i+97, H[i]);
	}
}

void findDuplicateWithHashTableBitWise(string str)
{
	int H = 0;
	for (unsigned int i = 0; i < str.size(); i++)
	{
		int bit = 1;
		bit = bit << (str[i] - 97);
		if(H&bit)
			printf("%c\n", str[i]);
		else
			H |= bit;
	}
}

bool isAnagram(string str1, string str2)
{
	if(str1.size() != str2.size())
		return false;

	int h[26] = {0};

	for (unsigned int i = 0; i < str1.size(); ++i)
		h[str1[i]-97]++;

	for (unsigned int i = 0; i < str2.size(); i++)
	{
		h[str2[i]-97]--;
		if(h[str2[i]-97] < 0)
			return false;
	}
	return true;
}

int main()
{
	string str1 = "finding";
	string str2 = "indingf";

	cout << isAnagram(str1, str2) << endl;

	return 0;
}