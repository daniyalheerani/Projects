#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node{
	int data;
	Node* next;
}; 
Node* head=NULL;
void enqueue(int num){
	Node *rear;	
	Node *newnode=(Node*)malloc(sizeof(Node*));
	newnode->data=num;
	newnode->next=NULL;
	if(head==NULL){
		cout<<"Queue is empty"<<endl;
		head=newnode;
	}
	else{
		rear=head;
		while(rear->next!=NULL){
			rear=rear->next;
		}
		rear->next=newnode;
	}
}
void dequeue(){
	Node* front;
	if(head==NULL){
		cout<<"Queue is empty"<<endl;
	}
	else{
		front=head;
		head=front->next;
		
		cout<<"Dequeued element is "<<front->data<<endl;
		free(front);
	}
}
void display(){
	Node* temp=head;
	if(head==NULL){
		cout<<"Queue is empty\n"<<endl;
	}
	while(temp!=NULL){
		cout<<temp->data<<"\t";
		temp=temp->next;
	}
	cout<<endl;
}
int main(int argc, char** argv) {
	
	enqueue(1);
	enqueue(2);
	enqueue(3);
	display();
	cout<<endl;
	enqueue(4);
	enqueue(5);
	display();
	dequeue();
	dequeue();
	dequeue();
	display();

	return 0;
}
