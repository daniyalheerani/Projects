#include <iostream>
#include <stdlib.h>

using namespace std;

struct node
{
	int data;
	node* left;
	node* right;
	node* parent;
};


class BinaryTree
{
	private:
	node* root;
	
	void inOrderHelper(node* temp)
	{
		if(temp != NULL)
		{
			inOrderHelper(temp->left);
			cout << temp->data << " "; //<< temp->height << " ";
			inOrderHelper(temp->right);
		}
	}
	
	node * minimum(node* x)
    {
        //finds minimum in x's subtree
        while(x->left!=NULL)
        {
            x=x->left;
        }
        return x;
    }
	
	node* searchHelper(node* temp, int key)
	{
		if(temp == NULL)
		{
			return NULL;
		}
		else if(temp->data == key)
		{
			return temp;
		}
		else if(key < temp->data)
		{
			return searchHelper(temp->left, key);
		}
		else
		{
			return searchHelper(temp->right, key);
		}
	}

	void insertHelper(node* temp, node* toAdd)
	{
		if(toAdd->data < temp->data)
		{
			if(temp->left == NULL)
			{
				temp->left = toAdd;
				toAdd->parent = temp;
				return;
			}
			insertHelper(temp->left, toAdd);
		}
		else
		{
			if(temp->right == NULL)
			{
				temp->right = toAdd;
				toAdd->parent = temp;
				return;
			}
			insertHelper(temp->right, toAdd);
		}
	}
	
	void replaceSubtree(node * u, node * v)
    {
        //replaces the subtree rooted at u with the subtree rooted at v
        if(u->parent==NULL){
            root=v;
        }
        else if(u==u->parent->left){
            u->parent->left=v;
        }
        else{
            u->parent->right=v;
        }
        if(v!=NULL){
            v->parent=u->parent;
        }
    }
	

	public:
	
	BinaryTree()
	{
		root = NULL;	
	}	
	
	void insert(int data)
	{
		node* temp = root;
		node* parentOfNewNode = NULL;
		while(temp != NULL)
		{
			parentOfNewNode = temp;
			if(data < temp->data)
			{
				temp = temp->left;
			}
			else if(data > temp->data)
			{
				temp = temp->right;
			}
		}
		node* newNode = (node*)malloc(sizeof(node));
		newNode->data = data;
		newNode->left = NULL;
		newNode->right = NULL;
		if(root == NULL)
		{
			root = newNode;
		}
		else if(data < parentOfNewNode->data)
		{
			parentOfNewNode->left = newNode;
			
		}
		else if(data > parentOfNewNode->data)
		{
			parentOfNewNode->right = newNode;
		}
		newNode->parent = parentOfNewNode;
			
	}

	void recursiveInsert(int data)
	{
		node* newNode = (node*)malloc(sizeof(node));
		newNode->left = newNode->right = newNode->parent = NULL;
		newNode->data = data;
		if(root == NULL)
		{
			root = newNode;
		}
		else
		{
			insertHelper(root, newNode);
		}
	}
	
	void search(int key)
	{
		node* temp = searchHelper(root, key);
		if(temp == NULL)
		{
			cout << "\nNot found\n";
		}
		else
		{
			cout << "Found "<< key << endl;
		}
	}
	
	void deleteNode(int key)
    {
        node * z = searchHelper(root, key);
        if(z != NULL)
        {
            //case 1: z has no childs, or a right child
            if(z->left == NULL)
            {
                replaceSubtree(z, z->right);
                delete z;
            }
            //case 2: z has a left child
            else if(z->right == NULL)
            {
                replaceSubtree(z, z->left);
                delete z;
            }
            //case 3: z has both child
            else
            {
                node  * successor = minimum(z->right);
                //case 4: if z's successor is not its right child, 
                //then find z's succesor and make it its right child
                if(successor != z->right)
                {
                    replaceSubtree(successor, successor->right);
                    successor->right = z->right;
                    successor->right->parent = successor;
                    z->right = successor;
                }
                replaceSubtree(z, successor);
                successor->left = z->left;
                successor->left->parent = successor;
                delete z;
            }
        }
    
    }
	
	void inOrderTraversal()
	{
		inOrderHelper(root);
	}
	
	
};

int main()
{
	BinaryTree test;
	for(int i = 1; i < 8; i++)
	{
		test.recursiveInsert(i);
	}
	cout << "InOrder Traversal:\n";
	test.inOrderTraversal();
	cout << "\nAfter deleting 4:\n";
	test.deleteNode(4);
	test.inOrderTraversal();
	test.insert(0);
	cout << "\nAfter inserting 0:\n";
	test.inOrderTraversal();
	cout << "\nAfter deleting 1:\n";
	test.deleteNode(1);
	test.inOrderTraversal();
}
