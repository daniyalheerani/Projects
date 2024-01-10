#include <iostream>
#include <stdlib.h>
using namespace std;

struct node
{
	int data;
	node *next;
};


class stack
{
	private:
		node* top;
		int size;
		
	public:
		
		stack()
		{
			top = NULL;
			size = 0;
		}
		
		void push(int val)
		{
			node* newNode = (node*)malloc(sizeof(node));
			newNode->data = val;
			newNode->next = top;
			top = newNode;
			size++;
		}
		
		void pop()
		{
			if(size == 0)
			{
				cout << "Stack is empty\n";
				return;
			}
			else
			{
				node* toDelete = top;
				top = top->next;
				free(toDelete);
			}
			size--;
		}
		
		void display()
		{
			if(size != 0)
			{
				cout << "[";
				node* temp = top;
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
	stack test;
	test.pop();
	test.push(1);
	test.push(2);
	test.push(3);
	test.display();
	test.pop();
	test.display();
	
	
}
