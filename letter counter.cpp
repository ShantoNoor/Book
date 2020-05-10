#include <iostream>

using namespace std;

struct letterCount
{
	int small;
	int capital;
};

letterCount letterCounter(string x)
{
	letterCount a;
	a.small = 0;
	a.capital = 0;
	for(unsigned int i = 0; i < x.size(); i++)
	{
		if(x[i] >= 'A' && x[i] <= 'Z')
			a.capital++;
		else if(x[i] >= 'a' && x[i] <= 'z')
			a.small++;
	}
	return a;
}

int main()
{
	letterCount word = letterCounter("Shanto Noor");
	cout << word.small << " " << word.capital << endl;
	cout << letterCounter("My Name Is Shanto Noor").small << endl;
	cout << letterCounter("My Name Is Shanto Noor").capital << endl;

	return 0;
}