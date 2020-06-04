#include <iostream>

using namespace std;

class list
{
private:
	struct node
	{
		int data;
		node* next;
	};
	node* head;
public:
	node* create_node(int item, node* next)
	{
		node temp;
		temp.data = item;
		temp.next = next;
		return temp;
	}
};

int main()
{
	

	return 0;
}