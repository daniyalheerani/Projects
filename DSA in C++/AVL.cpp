#include <iostream>
#include <stdlib.h>

using namespace std;

struct node
{
	int data;
	node* left;
	node* right;
	node* parent;
	int height;
};


class BinaryTree
{
	private:
	node* root;
	
	void inOrderHelper(node* temp)
	{
        //used for displaying tree using inorder traversal
		if(temp != NULL)
		{
			inOrderHelper(temp->left);
			cout << temp->data << " ";
			inOrderHelper(temp->right);
		}
	}
	
	void heights(node* temp)
	{
        //used for printing height of nodes
		if(temp != NULL)
		{
			heights(temp->left);
			cout << temp->height << " ";
			heights(temp->right);
		}
	}
	
	
	node* helperSearch(node* temp, int key)
	{
        //searches the tree for key, returns pointer to a node if found, else NULL
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
			return helperSearch(temp->left, key);
		}
		else
		{
			return helperSearch(temp->right, key);
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

    node * minimum(node* x)
    {
        //finds minimum in x's subtree
        while(x->left!=NULL)
        {
            x=x->left;
        }
        return x;
    }
	
	void updateHeights(node* x)
	{
		//updates height of nodes from x up to the tree root
        //also balances the tree if balance factor is disturbed after insertion or deletion
        node  *criticalNode = NULL;
        while(x != NULL)
        {
            int balanceFactor = updateNodeHeightAndBalanceFactor(x);
            if(balanceFactor == 2 || balanceFactor == -2)
            {
                criticalNode = x;
                break;
            }
            x = x->parent;
        }
        if(criticalNode != NULL)
        {
            balanceTree(criticalNode);
        }
	}
	
	int updateNodeHeightAndBalanceFactor(node *x)
    {
        //sets height of given node x and returns balance factor

        //if x has no child, then its height is 0, and balance factor also 0
        if(x->right == NULL && x->left == NULL)
        {
            x->height = 0;
            return 0; //returning the balance factor of x
        }
        //if x has only left child, then x's height is the height of its left child + 1 
        else if(x->right == NULL)
        {
            x->height = x->left->height+1;
            return x->left->height+1;
        }
        //if x has only right child, then x's height is the height of its right child + 1 
        else if(x->left == NULL)
        {
            x->height = x->right->height+1;
            return 0 - (x->right->height+1);
        }
        //if x has both children, then x's height is the maximum of heights of its children + 1
        else
        {
            x->height = max(x->right->height, x->left->height)+1;
            return x->left->height - x->right->height;
        }
    }
    
    void rotate(char rotationType, node *x, node *y)
    {
        //Time complexity: O(1) -> constant time
        //rotationType : if 'a' performs anti-clockwise rotation, if 'c' performs clockwise rotation
        y->parent = x->parent;
        x->parent = y;
        if(rotationType == 'a')
        {
            x->right = y->left;
            y->left = x;
        }
        else if (rotationType == 'c')
        {
            x->left = y->right;
            y->right = x;
            
        }
        if(x == root)
        {
            root = y;
        }
        else if(y->parent->right == x)
        {
            y->parent->right = y;
        }
        else
        {
            y->parent->left = y;
        }
        updateNodeHeightAndBalanceFactor(x);
        updateNodeHeightAndBalanceFactor(y);
    }
	
	
	void balanceTree(node *x)
	{
		//Balances a subtree rooted at x
        //x: a critical node

        //if a node is inserted in the subtree of x's right child
        if(updateNodeHeightAndBalanceFactor(x) < 0)
        {
            node * y = x->right; // right child of x
            //if insertion occured somewhere in right subtree of y
            if(updateNodeHeightAndBalanceFactor(y) < 0)
            {
                rotate('a', x, y);
            }
            //if insertion occured somewhere in left subtree of y
            else
            {
                //rotate clockwise
                rotate('c', y, y->left);
                //then rotate anti-clockwise
                rotate('a', x, x->right);
            }
            
        }
        //if a node is inserted in the subtree of x's left child
        else
        {
            node * y = x->left; // left child of x
            //if insertion occured somewhere in left subtree of y
            if(updateNodeHeightAndBalanceFactor(y) > 0)
            {
                rotate('c', x, y);
            }
            //if insertion occured somewhere in right subtree of y
            else
            {
                //rotate anti-clockwise
                rotate('a', y, y->right);
                //then rotate clockwise
                rotate('c', x, x->left);
            }
        }
	}
	
    
	public:
	
	BinaryTree()
	{
		root = NULL;	
	}	
	
	void insert(int data)
	{
        //non recursive insert
		node* temp = root;
        //this will be the parent of the new node that is about to be inserted in the tree
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
		newNode->height = 0;
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
		updateHeights(newNode);
			
	}
	
	void search(int key)
	{
		node* temp = helperSearch(root, key);
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
        //deletes the node whose data == key
        node * z = helperSearch(root, key);
        if(z != NULL)
        {
            node * zParent = z->parent;
            //case 1: z has no childs, or a right child
            if(z->left == NULL)
            {
                replaceSubtree(z, z->right);
                if(z->right != nullptr)
                {
                    updateNodeHeightAndBalanceFactor(z->right);
                }
                delete z;
            }
            //case 2: z has a left child
            else if(z->right == NULL)
            {
                replaceSubtree(z, z->left);
                updateNodeHeightAndBalanceFactor(z->left);
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
                updateNodeHeightAndBalanceFactor(successor);
                delete z;
            }
            updateHeights(zParent);
        }
    
    }
	
	
	void inOrderTraversal()
	{
		inOrderHelper(root);
	}

    void printHeights()
    {
        heights(root);
    }
	
	
};

int main()
{
	BinaryTree test;
    cout << "Inserting 50, 47, 45, 60, 40, 39, 66:\n";
    test.insert(50);
    test.insert(47);
    test.insert(45);
    test.insert(60);
    test.insert(40);
    test.insert(39);
    test.insert(66);
	cout << "InOrder Traversal:\n";
	test.inOrderTraversal();
	cout << "\nHeight of nodes: \n";
    test.printHeights();
    cout << "\nAfter Deleting 60:\n";
    test.deleteNode(60);
    cout << "InOrder Traversal:\n";
	test.inOrderTraversal();
	cout << "\nHeight of nodes: \n";
    test.printHeights();
    

}
