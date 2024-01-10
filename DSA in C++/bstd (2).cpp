#include<iostream>
using namespace std;

struct node {
	int key;
	struct node *left, *right;
};

struct node* newNode(int item)
{
	struct node* temp= (struct node*)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}
void inorder(struct node* root)
{
	if (root != NULL) {
		inorder(root->left);
		cout << root->key <<" ";
		inorder(root->right);
	}
}

struct node* insert(struct node* node, int key)
{
	if (node == NULL)
		return newNode(key);

	if (key < node->key)
		node->left = insert(node->left, key);
	else
		node->right = insert(node->right, key);
	return node;
}
void Search(struct node* root, int key)
{
	int depth = 0;
	node *temp = new node;
	temp = root;
	while(temp != NULL)
	{
		depth++;
		if(temp->key == key)
		{
			cout<<"\nData found at depth: "<<depth;
			return;
		}
		else if(temp->key > key)
			temp = temp->left;
		
		else
			temp = temp->right;
	}
 
	cout<<"\n Data not found";
}
struct node* minValueNode(struct node* node)
{
	struct node* current = node;
	while (current->left != NULL)
		current = current->left;

	return current;
}

struct node* deleteNode(struct node* root, int key)
{
	if (root == NULL)
		return root;

	
	if (key < root->key)
		root->left = deleteNode(root->left, key);

	
	else if (key > root->key)
	{
		root->right = deleteNode(root->right, key);
	}	
	else {
		if (root->left == NULL and root->right == NULL)
			return NULL;

		else if (root->left == NULL) {

			struct node* temp = root->right;
			free(root);
			cout<<temp->key;
			return temp;
		}
		else if (root->right == NULL) {
			struct node* temp = root->left;
			free(root);
			return temp;
		}

		struct node* temp = minValueNode(root->right);

		// Copy the inorder successor's content to this node
		root->key = temp->key;
		// Delete the inorder successor
		root->right = deleteNode(root->right, temp->key);
	}
	return root;
}

// Driver Code
int main()
{
	struct node* root=NULL;
	root = insert(root, 40);
	root = insert(root, 30);
	root = insert(root, 20);
	root = insert(root, 60);
	root = insert(root, 65);
	root = insert(root, 70);
	root = insert(root, 80);





	cout << "Inorder traversal of the given tree \n";
	inorder(root);

	cout << "\nDelete 20\n";
	root = deleteNode(root, 20);
	cout << "Inorder traversal of the modified tree \n";
	inorder(root);

	cout << "\n Delete 65\n";
	root = deleteNode(root, 70);
	cout << "Inorder traversal of the modified tree \n";
	inorder(root);

	cout << "\n Delete 40\n";
	root = deleteNode(root, 40);
	cout << "Inorder traversal of the modified tree \n";
	inorder(root);

	cout<<"search 80\n";
	Search(root,80);

	return 0;
}

