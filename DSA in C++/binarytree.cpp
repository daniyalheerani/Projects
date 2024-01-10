#include <iostream>

using namespace std;


struct Node{
	Node* left;
	Node* right;
	int data;
};

class tree{
		
	public:
		Node* root=NULL;
		void insertion(int data){
			Node* newnode=new Node;
			newnode->data=data;
			newnode->left=NULL;
			newnode->right=NULL;
			Node* current=root;
			Node* parent=NULL;
			while(current!=NULL){
				parent=current;
				if(data<parent->data){
					current=current->left;
				}
				else{
					current=current->right;
				}
			}
			if(root==NULL){
				root=newnode;
			}
			else if(data<parent->data){
				parent->left=newnode;
			}
			else{
				parent->right=newnode;
			}
		}
		void fordisplay(){
		
			display(root);
		}
		void display(Node *temp){	
				if(temp!=NULL){
					display(temp->left);
					cout<<temp->data<<" ";
					display(temp->right);
					
				}
				cout<<endl;
		}
		
		Node* search(int data){
			Node* current=new Node;
			current=root;
			while(current->data!=data){
				if(current==NULL){
				return NULL;	
			}
			else if(data<current->data){
				current=current->left;
			}
			else{
				current=current->right;
			}
		//	return current;
			}
				if(current->data==data){
				cout<<"fount: "<<data;
			}
			else{
				cout<<"not found.";
			}
		};
		void preOrder(Node *root){
			if(root!=NULL){
				cout<<root->data<<" ";
				preOrder(root->left);
				preOrder(root->right);
			
			}
			
		};
		void inOrder(Node *root){
			if(root!=NULL){
				inOrder(root->left);
				cout<<root->data<<" ";
				inOrder(root->right);
			}
		};
		void postOrder(Node* root){
			if(root!=NULL){
				postOrder(root->left);
				postOrder(root->right);
				cout<<root->data<<" ";
			}
		};
		
};

int main() {
	tree t;
	t.insertion(3);
	t.insertion(6);
	t.insertion(9);
	t.insertion(2);
	t.insertion(0);
	t.insertion(18);
	t.insertion(4);
//	t.fordisplay();
	t.search(2);cout<<endl;
	t.preOrder(t.root);cout<<endl;
	t.inOrder(t.root);cout<<endl;
	t.postOrder(t.root);
//	t.fordisplay();
	return 0;
}
