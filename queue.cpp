#include <iostream>

using namespace std;

#define size 10

 class queue
 {
 	int head = 0;
 	int tail = 0;
 public:
 	int arr[size+1];
 	void enque(int x)
 	{
 		if(head == (tail+1)%(size+1))
 			cout << "Queue is full!..." << endl;
 		else
 		{
 			arr[tail] = x;
 			tail = (tail+1)%(size+1);
 		}
 	}
 	int deque()
 	{
 		int ret = 0;
 		if(head == tail)
 			cout << "Queue is Empty!..." << endl;
 		else
 		{
 			ret = arr[head];
 			arr[head] = -1;
			head = (head+1) % (size+1);
 		}
 		return ret;
 	}
 };

int main()
{
	queue q;

	cout << "START ENQUE" << endl;
	for (int i = 0; i < 13; i++)
	{
		q.enque(i*2);
	}

	cout << "START DEQUE" << endl;
	for (int i = 0; i < 13; i++)
	{
		cout << q.deque() << endl;
	}

	q.enque(90);
	q.enque(8);
	q.enque(8);
	q.enque(8);
	q.enque(8);
	q.enque(8);
	q.enque(8);
	q.enque(8);
	q.enque(8);
	q.enque(8);

	cout << "PRINT ARRAY" << endl;
	for (int i = 0; i < size+1; i++)
	{
		cout << q.arr[i] << " ";
	}
	cout << endl;


	return 0;
}