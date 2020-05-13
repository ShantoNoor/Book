#include <iostream>
// #include <string>
// #include <iomanip>
#include <sstream>
#include <iomanip>
using namespace std;

void printLine(string str)
{
	int dasNumber = 38 - str.size();
	if(dasNumber & 1)
	{
		dasNumber = dasNumber/2;
		for(int i = 0; i < dasNumber; i++)
			printf("-");
		printf("[");
		printf(str.c_str());
		printf("]");
		for(int i = 0; i < dasNumber+1; i++)
			printf("-");
	}
	else
	{
		dasNumber = dasNumber/2;
		for(int i = 0; i < dasNumber; i++)
			printf("-");
		printf("[");
		printf(str.c_str());
		printf("]");
		for(int i = 0; i < dasNumber; i++)
			printf("-");
	}
}

int main() 
{
    string line = "--------------------------------------";

    cout << line.size() << endl;
    printLine(line.c_str());
    printf("\n");
    printLine("shantoNoor");
    printf("\n");
    printLine("shanto Noor");
    printf("\n");

    stringstream ss;
    string s;
    ss << "finished in " << std::fixed << std::setprecision(2) << 112.343535335 << "s" << endl;
    ss << "return " << 10 << endl;
    
    while(getline(ss, s))
    {
    	printLine(s.c_str());
    	printf("\n");
    }


    return 0;
}