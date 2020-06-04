#include <iostream>

using namespace std;

#define size 10

struct stack
{
	int top = 0;
	int arr[size];
	void push(int x)
	{
		if(top < size)
			arr[top++] = x;
		else 
			cout << "Stack is full!..." << endl;
	}
	int pop()
	{
		if(top > 0)
			return arr[--top];
		else
			cout << "Stack is empty!..." << endl;
		return 0;
	}
};

int main()
{
	stack s;

	s.push(2);
	s.push(1);
	s.push(6);
	s.push(4);
	s.push(3);
	s.push(7);
	s.push(0);
	s.push(65);
	s.push(434);
	s.push(43);
	s.push(40);

	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;


	return 0;
}