#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

struct node
{
	int data;
	node *next;
};

class list
{
	private:
		node *head;
		node *tail;
		int size;
		
		void helperDelete(node *temp, int val)
		{
			if(temp->next == NULL)
			{
				cout << "Element not found\n";
			}
			else if (temp->next->data == val)
			{
				node *toDelete = temp->next;
				temp->next = toDelete->next;
				free(toDelete);
				size--;
			}
			else
			{
				helperDelete(temp->next, val);
			}
		}
	
	public:
		
		list()
		{
			head = tail = NULL;
			size = 0;
		}
		
		list(int size, int val = 0)
		: size(size)
		{
			head = (node*)malloc(sizeof(node));
			head->next = NULL;
			head->data = val;
			node *temp = head;
			for(int i = 1; i < size; i++)
			{
				node *newNode = (node*)malloc(sizeof(node));
				newNode->next = NULL;
				newNode->data = val;
				temp->next = newNode;
				temp = newNode;
			}
			tail = temp;
		}
		
		void insertAtBegining(int val)
		{
			node *newNode = (node*)malloc(sizeof(node));
			newNode->next = head;
			newNode->data = val;
			if(head == NULL)
			{
				tail = newNode;
			}
			head = newNode;
			size++;
		}
		
		void insertAtEnd(int val)
		{
			node *newNode = (node*)malloc(sizeof(node));
			newNode->next = NULL;
			newNode->data = val;
			if(head == NULL)
			{
				head = newNode;
			}
			else
			{
				tail->next = newNode;
			}
			tail = newNode;
			size++;
		}
		
		void insertAtPosition(int position, int val)
		{
			if(position > 1 && position < size)
			{
				node* temp = head;
				for(int i = 1; i < position-1; i++)
				{
					temp = temp->next;
				}
				node *newNode = (node*)malloc(sizeof(node));
				newNode->next = temp->next;
				newNode->data = val;
				temp->next = newNode;
				size++;
			}
			else
			{
				cout << "Invalid position\n";  
			}
			
		}
		
		
		void deleteFromBegining()
		{
			if(size == 0)
			{
				cout << "List is empty!\n";
				return;
			}
			else if(size == 1)
			{
				free(head);
				head = tail = NULL;
			}
			else 
			{
				node * temp = head->next;
				free(head);
				head = temp;
				
			}
			size--;
			
		}
		
		void deleteFromEnd()
		{
			if(size == 0)
			{
				cout << "List is empty!\n";
				return;
			}
			else if(size == 1)
			{
				free(tail);
				head = tail = NULL;
			}
			else
			{
				node * temp = head;
				for(int i = 1; i < size-1; i++)
				{
					temp = temp->next;
				}
				free(tail);
				tail = temp;
				tail->next = NULL;
			}
			size--;
		}
		
		void deleteAtPosition(int position)
		{
			if(position > 1 && position < size)
			{
				node* temp = head;
				for(int i = 1; i < position-1; i++)
				{
					temp = temp->next;
				}
				node *toDelete = temp->next;
				temp->next = toDelete->next;
				free(toDelete);
				size--;
			}
			else
			{
				cout << "Invalid position\n";  
			}
		}
		
		void deleteElement(int val)
		{
			if(head == NULL)
			{
				cout << "EMPTY!!\n";
				return;
			}
			else if(head->data == val)
			{
				node *temp = head->next;
				free(head);
				head = temp;
			}
			else
			{
				helperDelete(head, val);
			}
		}
		
		int getSize()
		{
			return size;
		}
		
		
		void displayForward()
		{
			node * temp=head;
			cout << "[";
			for(int i = 0; i < size; i++)
			{
				cout << temp->data <<  ", ";
				temp = temp->next;
			}
			cout << "\b\b]\n";
		}
		
		~list()
		{
			node* temp = head;
			node* prev = head;
			for(int i = 0; i < size-1; i++)
			{
				temp= temp->next;
				free(prev);
				prev = temp;
			}
			if(size != 0)
			{
				free(temp);
			}
		}
		
		
};


int main()
{
	
	list test(6, 1);
	test.insertAtBegining(9);
	test.insertAtEnd(12);
	test.insertAtPosition(3, 5);
	test.insertAtPosition(4, 4);
	test.displayForward();
	test.deleteElement(5);
	test.displayForward();
	
}
