#include <iostream>
using namespace std;

struct Node{
   string data;   
   Node *leftChild;
   Node *rightChild;
};
Node *root=NULL;
void enterWord(string data){
   Node *tempNode=new Node;
   Node *current;
   Node *parent;

   tempNode->data=data;
   tempNode->leftChild=NULL;
   tempNode->rightChild=NULL;

   if(root==NULL){
      root=tempNode;
   }
	else{
      current=root;
      parent=NULL;
		while(1){                
         parent=current;
         if(data<parent->data){
            current=current->leftChild;                
            if(current==NULL){
               parent->leftChild=tempNode;
               return;
            }
         }
         else{
            current=current->rightChild;            
            if(current==NULL){
               parent->rightChild=tempNode;
               return;
            }
         }
      }
   }
}
void removeWord(string data){
	
}
Node* searchWord(string data){
   struct Node *current=root;
   while(current->data!=data){
      if(current!=NULL){
	  }
      if(current->data>data){
         current=current->leftChild;
      }
      else{                
         current=current->rightChild;
      }
      if(current==NULL){
         return NULL;
      }
   }
   return current;
}
void traversePreOrder(struct Node *temp){
	if(temp!=NULL) {
   	cout<<temp->data<<" ";
   	traversePreOrder(temp->leftChild);
   	traversePreOrder(temp->rightChild);
	}
	cout<<endl;
}

void traverseInOrder(struct Node *temp){
	if(temp!=NULL){
   	traverseInOrder(temp->leftChild);
   	cout<<temp->data<<" ";
   	traverseInOrder(temp->rightChild);
	}
	cout<<endl;
}

void traversePostOrder(struct Node *temp){
	if(temp!=NULL){
   	traversePostOrder(temp->leftChild);
		traversePostOrder(temp->rightChild);
		cout<<temp->data<<" ";
	}
	cout<<endl;
}

int menu(){
	int choice;
	string st;
	cout<<"\n\n\n\t\t\tWelcome to our dictionary\n\n\n";
	
	while(1){
		cout<<"\n\nWhich action do you want to perform\n";
		cout<<"\1. Add Word\n2. Remove Word\n3. Search Word\n4. Display Words\n5. Exit";
		cout<<endl<<"Enter your choice: ";
		cin>>choice;
		if(choice==1){
			cout<<"Enter word to add: ";
			cin>>st;
			enterWord(st);
		}
		else if(choice==2){
			cout<<"Enter word to remove: ";
			cin>>st;
			removeWord(st);
		}
		else if(choice==3){
			cout<<"Enter word to search: ";
			cin>>st;
			Node *temp=NULL;
			temp=searchWord(st);
			if(temp==NULL){
				cout<<"Word not found\n";
			}
			else{
				cout<<"Word: "<<temp->data;
			}
		}
		else if(choice==4){
			traversePreOrder(root);
		}
		else if(choice==5){
			return 0;
		}

	}
}


int main(int argc, char** argv) {
	
	menu();
	
	return 0;
}
