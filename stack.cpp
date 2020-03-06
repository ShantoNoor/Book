#include <iostream>
using namespace std;

#define stack_size 10

class Stack
{
    int i = 0;
    int ara[stack_size];
public:
    void push(int a)
    {
        if(i >= stack_size)
        {
            cout << "Error: Stack is FULL!" << endl;
            exit(1);
        }
        else
        {
            ara[i] = a;
            i++;
        }
        
    }
    int pop()
    {
        if(i == 0)
        {
            cout << "Error: Stack is EMPTY!" << endl;
            exit(1);
        }
        else
        {
            i--;
            return ara[i];
        }
    }
};

int main()
{
    Stack s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;

    s.push(6);
    s.push(7);

    cout << s.pop() << endl;
    cout << s.pop() << endl;

    return 0;
}