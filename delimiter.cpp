#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	string s;
	cin >> s; 
	stringstream ss;
	ss << s;
	int arr[3], i = 0;
	while(getline(ss, s, '/'))
	{
		arr[i] = atoi(s.c_str());
		cout << arr[i] << endl;
		i++;
	}

	cout << arr[0] + arr[1] + arr[2] << endl;

	return 0;
}