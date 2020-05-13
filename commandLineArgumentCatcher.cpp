#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	std::string str = argv[1];
	for(int i = 2; i < argc; i++)
	{
		str += " ";
		str += argv[i];
	}

	std::cout << str << std::endl;

	return 0;
}