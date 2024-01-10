#include<iostream>
#include<stdlib.h>
#include<string>
#include<cstring>

using namespace std;

struct Node{
	int data;
	Node* left;
	Node * right;
	int height;
};

Node* node=NULL;

class avl{
	public:
		int height(Node* node){
			if(node==NULL){
				return 0;
			}
			return node->height;
		}
		int getbalacefactor(Node* node){
			if(node==NULL){
				return 0;
			}
			return height(node->left)-height(node->right);
		}
		
		Node* rightRotate(Node* x){
			Node* s=x->left;
			Node* v=s->right;
			
			s->right=x;
			x->left=v;
			
			x->height=max(height(x->right),height(x->left)+1);
			s->height=max(height(s->right),height(s->left)+1);
			return s;
		}
		
		Node* leftRotate(Node* x){
			Node* s=x->right;
			Node* v=s->left;
			
			s->right=x;
			x->left=v;
			
			x->height=max(height(x->right),height(x->left)+1);
			s->height=max(height(s->right),height(s->left)+1);
			return s;
		}
		
		struct Node* insertion(Node* node,int key){
		
			Node* newnode=new Node;
			newnode->data=key;
			newnode->left=NULL;
			newnode->right=NULL;
			newnode->height=1;
			
			if(node==NULL){
				node=newnode;
				return newnode;
			}
			else if(key>node->data){
				return	insertion(node->right,key);
			}
			else if(key<node->data){
				return insertion(node->left,key);
			}
			//node=newnode;
			node->height=max(height(node->left),height(node->right)+1);
			return node;
	}
	void inorder(Node* temp){
		temp=node;
		if(temp!=NULL){
			inorder(temp->left);
			cout<<temp->data<<" ";
			inorder(temp->right);
		}
	}
	Node* min(Node* node,int key){
		Node* temp=node;
		while(temp!=NULL){
			temp=temp->left;
		}
		return temp;
	}
	Node* Delete(Node* node,int key){
		if(node==NULL){
			return NULL;
		}
		if(key<node->data){
			node->left=Delete(node->left,key);
		}
		else if(key>node->data){
			node->right=Delete(node->right,key);
		}
		else{
			if(node->left==NULL && node->right==NULL){
				free(node);
				return NULL;
			}
			else if(node->left==NULL){
				Node *temp=node->right;
				free(node);
				return temp;
			}
			else if(node->right==NULL){
				Node* temp=node->left;
				free(node);
				return temp;
			}
			Node *temp=min(node->right,key);
			node->data=temp->data;
			node->right=Delete(node->right,temp->data);
		}
		return node;
	}
	
};

int main(){
	bst b;
	node=b.insertion(node,2);
	node=b.insertion(node,4);
	node=b.insertion(node,0);
	node=b.insertion(node,8);
	node=b.insertion(node,11);
	b.inorder(node);
	
	
	return 0;
}