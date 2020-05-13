#include <iostream>
#include <windows.h>

using namespace std;

std::string gppCommand = "g++ -std=c++17 -Wshadow -Wall -O2 -Wno-unused-result";
int compile(std::string str)
{
	str = gppCommand + " " + str + ".cpp -o " + str + ".exe";
	if(system("str") == 0)
		return 0;
	else
		return 1;
}

int main()
{
	std::string str = "pattern5_6";
	str = "\"g++ -std=c++17 -Wshadow -Wall -O2 -Wno-unused-result -O2 -Wno-unused-result \"" + str + ".cpp" + "\"" + " -o " + "\"" + str + ".exe" + "\"" + "\"";
	cout << str << endl;


	return 0;
}