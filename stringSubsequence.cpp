#include <iostream>

using namespace std;

bool findStrCount(string str, string str2)
{
    unsigned int count = 0;
    for(unsigned int i = 0; i < str.size(); i++)
    {
        if(str[i] == str2[0])
        {
            unsigned int temp = 1;
            for(unsigned int j = 1, k = i+1; /*No Condition Needed*/; j++, k++) 
            {
                if(temp == str2.size())
                {
                    count++;
                    return true;
                }
                if(str[k] == str2[j])
                    temp++;
                else
                    break;
            }
        }
    }
    return false;
}

bool isSubsequence(string str, string str2)
{
	if(findStrCount(str, str2) || str.size() < str2.size())
		return false;
	else
	{
		unsigned int i, j, count = 0;
		for(i = 0, j = 0; i < str.size(); i++)
		{
			if(str[i] == str2[j])
			{
				count++;
				j++;
				if(count == str2.size())
					return true;
			}
		}
	}
	return false;
}

int main()
{
	cout << isSubsequence("bangladesh", "desh") << endl;
	cout << isSubsequence("bangladesh", "besh") << endl;
	cout << isSubsequence("bangladesh", "bglades") << endl;
	cout << isSubsequence("benglabangladesh", "bangladesh") << endl;
	cout << isSubsequence("bangladesh", "ebsh") << endl;

	return 0;
}