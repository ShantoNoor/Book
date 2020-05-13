#include <iostream>
#include <string>
using namespace std;

int findLastPosition(string str, char x)
{
    int pos = -1;
    for(unsigned int i = 0; i < str.size(); i++)
    {
        if(str[i] == x)
            pos = i;
    }
    return pos;
}

int findStrCount(string str, string str2)
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
                    //i += str2.size() - 1; /*Time Save*/
                    break;
                }
                if(str[k] == str2[j])
                    temp++;
                else
                    break;
            }
        }
    }
    return count;
}

void print(const char* str)
{
	printf("%s\n", str);
}

int main()
{
	string str = "bangladesh"; 
    string str1 = "desh";
    // cin >> str >> str1;

    // size_t found = str.find(str1); 
    // if (found != string::npos) 
    //     cout << "First occurrence is " << found << endl; 

    // char arr[] = "desh"; 
    // found = str.find(arr, found+1); 
    // if (found != string::npos) 
    //     cout << "Next occurrence is " << found << endl; 

    
    cout << findStrCount(str, str1) << endl;
    print(str.c_str());

    // cout << findLastPosition("shan\\to no\\or", '\\') << endl;

    str = "pattern5_6.cpp -ida";
    int x = findLastPosition(str, '.');
    cout << str.substr(x+1, 3) << endl;
    cout << str.substr(0, x) << endl;
    x = findLastPosition(str, '-');
    cout << str.substr(x+1, str.size()-x) << endl;

    // cout << str.size() << " " << str.capacity() << endl;
    // str.erase(0, x+1);
    // cout << str << endl;
    // str.shrink_to_fit();
    // cout << str.size() << " " << str.capacity() << endl;




    return 0;
}