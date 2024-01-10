#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

struct node
{
	int data;
	node *next;
};

class queue
{
	private:
		node* front;
		node* rear;
		int size;
	
	public:
		queue()
		{
			front = rear = NULL;
			size = 0;
		}
		
		
		void enqueue(int element)
		{
			node* newNode = (node*)malloc(sizeof(node));
			newNode->next = NULL;
			newNode->data = element;
			if(front == NULL)
			{
				front = rear = newNode;
			}
			else
			{
				rear->next = newNode;
				rear = newNode; 
			}
			size++;
		}
		
		void dequeue()
		{
			if(front != NULL)
			{
				node* temp = front->next;
				free(front);
				front = temp;
				size--;
			}
			else
			{
				cout << "Queue is empty!\n";
			}
		}
		
		bool isEmpty()
		{
			if(front == NULL)
			{
				return true;
			}
			return false;
		}
		
		void display()
		{
			if(front != NULL)
			{
				cout << "[";
				node*temp = front;
				for(int i = 0; i < size; i++)
				{
					cout << temp->data << ", ";
					temp = temp->next;
				}
				cout << "\b\b]\n";
			}
		}
		 

};

int main()
{
	queue test;
	test.dequeue();
	for(int i = 1; i < 5; i++)
	{
		test.enqueue(i);
	}
	test.display();
	test.dequeue();
	test.display();
	
}
