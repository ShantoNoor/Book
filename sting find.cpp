#include <iostream>
#include <string>
#include <sstream>
using namespace std;


int findPosition(std::string str, char x, int ipos)
{
    for(int i = ipos; str[i] != '\0'; i++)
        if(str[i] == x)
            return i;
    return 0;
}

int findLastPosition(string str, char x)
{
    int pos = -1;
    for(unsigned int i = 0; i < str.size(); i++)
        if(str[i] == x)
            pos = i;
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

int findStr(string str, string str2)
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
                {
                    temp++;
                    return i;
                }
                else
                    break;
            }
        }
    }
    return 0;
}

void print(const char* str)
{
	printf("%s\n", str);
}

int main()
{
	// string str = "bangladesh"; 
 //    string str1 = "desh";
    // cin >> str >> str1;

    // size_t found = str.find(str1); 
    // if (found != string::npos) 
    //     cout << "First occurrence is " << found << endl; 

    // char arr[] = "desh"; 
    // found = str.find(arr, found+1); 
    // if (found != string::npos) 
    //     cout << "Next occurrence is " << found << endl; 

    
    // cout << findStrCount(str, str1) << endl;
    // print(str.c_str());

    // cout << findLastPosition("shan\\to no\\or", '\\') << endl;

    // str = "pattern5_6.cpp -ida";
    // int x = findLastPosition(str, '.');
    // cout << str.substr(x+1, 3) << endl;
    // cout << str.substr(0, x) << endl;
    // x = findLastPosition(str, '-');
    // cout << str.substr(x+1, str.size()-x) << endl;

    // cout << str.size() << " " << str.capacity() << endl;
    // str.erase(0, x+1);
    // cout << str << endl;
    // str.shrink_to_fit();
    // cout << str.size() << " " << str.capacity() << endl;

    std::string filename;
    std::string filetype; 
    std::string das; 
    std::string inputname;
    std::string outputname;

    std::string str = "nCr.exe" -f -"<"input 1.txt" >"output 1.txt""";
    int dasCount = findStrCount(str, "-");
    cout << str << endl;

    int ipos = findPosition(str, '.', 0); // pointing at dot
    filename = str.substr(0, ipos);
    int lpos = findPosition(str, '-', ipos); // pointing at das after dot || 1st das
    if(lpos) // 1st das is presentt
    {
        filetype = str.substr(ipos+1, lpos-ipos-1);

        ipos = lpos;
        lpos = findPosition(str, '-', ipos+1); // pointing at 2nd dast
        if(lpos) // 2nd das is present
        {
            das = str.substr(ipos+1, lpos-ipos-1);
            ipos = findPosition(str, '\"', lpos);
            lpos = findLastPosition(str, '\"');
            inputname = str.substr(ipos+1, lpos-ipos-1);
        }
        else //2nd das is not present
            das = str.substr(ipos+1, str.size()-ipos);
    }
    else 
        filetype = str.substr(ipos+1, str.size()-ipos);
    


    cout << findLastPosition(str, '<') << endl;
    cout << findLastPosition(str, '>') << endl;





    // ipos = lpos;
    // lpos = findPosition(str, '-', ++ipos);
    // inputname = str.substr(ipos, lpos-ipos-1);
    // outputname = str.substr(lpos+2, str.size()-lpos-1);

    // ipos = lpos;
    // lpos = findPosition(str, '-', ++ipos);

    // if(dasCount == 4)
    // {
    //     inputname = str.substr(ipos, lpos-ipos-1);
    //     outputname = str.substr(lpos+2, str.size()-lpos-1);
    // }
    // else if(dasCount == 2)
    //     inputname = str.substr(ipos, str.size()-ipos);
    // else if(dasCount == 3)
    //     outputname = str.substr(ipos+1, str.size()-ipos-1);



    

    cout << str << endl;
    cout << filename << endl;
    cout << filetype << endl;
    cout << das << endl;
    cout << "in : " << inputname << endl;
    cout << "out : " << outputname << endl;


    return 0;
}