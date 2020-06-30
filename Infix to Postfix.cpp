#include <iostream>

using namespace std;

template <typename T, int stack_size>
class Stack
{
    int top = 0;
    T ara[stack_size];
public:
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
    T stackTop()
    {
        if(top == 0)
        {
            cout << "Error: Stack is EMPTY!" << endl;
            exit(1);
        }
        else
        {
            return ara[top-1];
        }
    }
    int getTop()
    {
        return top;
    }
    bool isEmpty()
    {
        return !top;
    }
    bool isFull()
    {
        return top;
    }
    T peek(int i)
    {
        if(top - i > -1)
            return ara[top-i];
        else
        {
            cout << "Invalid Index : ";
            return -1;
            cout << endl;
        }
    }
};
int cstr_len(const char cstr[])
{
	int i;
	for(i = 0; cstr[i] != '\0'; i++);
	return i;
}

bool isOperand(char x)
{
	if(x == '+' || x == '-' || x == '*' || x == '/')
		return 0;
	return 1;
}

int pre(char x)
{
	if(x == '+' || x == '-')
		return 1;
	else if(x == '*' || x == '/')
		return 2;
	return 0;
}

const char *postfix(const char *infix)
{
	int len = cstr_len(infix)+2;
	char *post = new char[len];

	Stack<char, 10> s;
	s.push('#');

	int i = 0, j = 0;
	while(infix[i] != '\0')
	{
		if(isOperand(infix[i]))
		{
			post[j++] = infix[i++];
		}
		else
		{
			if(pre(s.stackTop()) < pre(infix[i]))
				s.push(infix[i++]);
			else
				post[j++] = s.pop();
		}
	}

	while(s.stackTop() != '#')
		post[j++] = s.pop();

	post[j] = '\0';

	return post;
}

double cal(double a, char ch, double b)
{
	if(ch == '+')
		return a+b;
	else if(ch == '-')
		return a-b;
	else if(ch == '*')
		return a*b;
	else if(ch == '/')
		return a/b;
	return 0;
}

double eval(const char* pofix)
{
	Stack<double, 10> s;
	for (int i = 0; pofix[i] != '\0'; i++)
	{
		if(isOperand(pofix[i]))
			s.push(double(pofix[i]-'0'));
		else
		{
			double x2 = s.pop();
			double x1 = s.pop();
			s.push(cal(x1, pofix[i], x2));
		}
	}
	return s.pop();
}

int main()
{
	// const char *infix = "a+b*c-d/e";
	const char *infix = "3*4*6-9-3+8/4+1";//34*6*9-3-204/+1+

	const char *posfix = postfix(infix);

	cout << posfix << endl;
	cout << eval(posfix) << endl;
	

	return 0;
}