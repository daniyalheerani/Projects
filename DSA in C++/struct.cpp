#include<iostream>
#include<stdlib.h>
#include<string>
#include<cstring>

using namespace std;

struct Node{
	int data;
	Node* next;
	Node* perv;
};

class doubly{
	Node *head=NULL;
	public:
		void createlist(int n){
			int data;
			for(int i=0;i<n;i++){
				cout<<"Enter data."<<endl;
				cin>>data;
				Node* newnode=(Node*)malloc(sizeof(Node));
				newnode->data=data;
				newnode->next=NULL;
				newnode->perv=NULL;
				if(head==NULL){
					head=newnode;	
				}
				else{
					Node *temp=head;
					while(temp->next!=NULL){
						temp=temp->next;		
					}
					temp->next=newnode;
					newnode->perv=temp;		
				}
			}
		}
		void display(int n){
			int count=0;
			Node* temp=head;
			cout<<"\n\n\n";
			for(int i=0;i<n;i++){
				cout<<temp->data<<endl;
				temp=temp->next;
				count++;
			}
			cout<<"Total nodes are: "<<count<<endl;
		}
		void insertionbig( int val){
			Node* nn=(Node*)malloc(sizeof(Node*));
			nn->next=head;
			nn->data=val;
			head->perv=nn;
			head=nn;
			head->perv=NULL;
		}
		void delbig(){
			Node* temp=head;
			head=head->next;
			head->perv=NULL;
			free(temp);
		}
		void insertlast(int data){
			Node* nn=(Node*)malloc(sizeof(Node*));
			nn->data=data;
			Node* temp=head;
			while(temp->next!=NULL){
				temp=temp->next;
			}
			temp->next=nn;
			nn->perv=temp;
			nn->next=NULL;
		}
		void delast(){
			Node* temp=head;
			while(temp!=NULL){
				temp=temp->next;
			}
			temp->perv->next=NULL;
			free(temp);
		}
			
};
int main(){
	doubly d;
	d.createlist(6);
	d.display(6);
	d.insertionbig(12);
	d.display(7);
	d.delbig();
	d.display(6);
	d.insertlast(18);
	d.display(7);
	d.delast();
	d.display(6);
}