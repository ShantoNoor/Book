#include <iostream>

using namespace std;

template <typename T, int stack_size>
class Stack
{
    T ara[stack_size];
public:
    int top = 0;
    void push(T a)
    {
        if(top >= stack_size)
        {
            cout << "Error: Stack is FULL!" << endl;
            exit(1);
        }
        else
        {
            ara[top] = a;
            top++;
        }
        
    }
    T pop()
    {
        if(top == 0)
        {
            cout << "Error: Stack is EMPTY!" << endl;
            exit(1);
        }
        else
        {
            top--;
            return ara[top];
        }
    }
};

bool isBalanced(char exp[])
{
	Stack<char, 10> s;
	for (int i = 0; exp[i] != '\0'; i++)
	{
		if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
			s.push(exp[i]);
		else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
		{
			if(s.top == 0) return false;
			char b = s.pop();
			if(b == '(' && exp[i] != ')') return false;
			else if(b == '{' && exp[i] != '}') return false;
			else if(b == '[' && exp[i] != ']') return false;
		}
	}
	if(s.top == 0) return true;
	else return false;
}

int main()
{
	char exp[] = "[{(a+b)*(a-b)}/10]*20";

	cout << isBalanced(exp) << endl;

	return 0;
}