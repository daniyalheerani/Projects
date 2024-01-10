#include <iostream>
#include <stdlib.h>
using namespace std;
struct Node {
	int data;
	Node *next;
};
Node *head=NULL;
void createList(int n){
	
	int val;
	for(int i=0;i<n;i++)
	{
		cout<<"enter the value of node: ";
		cin>>val;
		Node *newNode=(Node*)malloc(sizeof(Node*));
		newNode->data=val;
		newNode->next=NULL;
		if(head==NULL)
		{
			head=newNode;
		}
		else{
			Node *temp=head;
			while(temp->next!=NULL)
			{
				
				temp=temp->next;
				
			}
			temp->next=newNode;
			
		}
	}
}
void reverse(){
	Node * current=head;
	Node* prev=NULL;
	Node *next=NULL;
	while(current!=NULL){
		
		next=current->next;
		current->next=prev;
		
		prev=current;
		current=next;
	}
	head=prev;
}
void display(){
	Node*temp=head;
	if(head==NULL)
	{
		cout<<"Linked list is empty";
		
	}
	else{
		while(temp!=NULL)
		{
			cout<<temp->data<<"\t";
			temp=temp->next;
		}
	}
	
}

int main(int argc, char** argv) {
	
	createList(6);
	cout<<endl<<"List: "<<endl;
	display();
	reverse();
	cout<<endl<<"Reversed list: "<<endl;
	display();
	
	return 0;
}
