#include <iostream>

using namespace std;


template<typename L>
struct Node
{
    L data;
    Node* left;
    Node* right;
    Node* parent;
    int height;
};

template <typename T>
class avl
{
    Node<T>* root;

    void inOrderTraversal(Node <T>* x)
    {
    
        if(x!=nullptr)
        {
            inOrderTraversal(x->left);
            cout<< x->data << " " << x->height << " ";
            inOrderTraversal(x->right);
            
        }
    }

    Node<T>* searchHelper(Node <T>* x,T &key){
        if(x==nullptr){
            return nullptr;
        }
        else if(key==x->data){
            return x;
        }
        else if(key<x->data){
            return searchHelper(x->left,key);
        }
        else{
           return searchHelper(x->right,key);
        }
        
    }

    Node <T> * minimum(Node <T>* x)
    {
        while(x->left!=nullptr)
        {
            x=x->left;
        }
        return x;
    }

    Node <T> * maximum(Node <T>* x)
    {
        while(x->right!=nullptr)
        {
            x=x->right;
        }
        return x;
    }

    void replaceSubtree(Node <T>* u, Node <T>* v)
    {
        //replaces the subtree rooted at u with the subtree rooted at v
        if(u->parent==nullptr){
            root=v;
        }
        else if(u==u->parent->left){
            u->parent->left=v;
        }
        else{
            u->parent->right=v;
        }
        if(v!=nullptr){
            v->parent=u->parent;
        }
    }

    void updateHeights(Node <T>* x)
    {
        Node <T> *criticalNode = nullptr;
        while(x != nullptr)
        {
            int balanceFactor = heightAndBalanceFactor(x);
            if(balanceFactor == 2 || balanceFactor == -2)
            {
                criticalNode = x;
                break;
            }
            x = x->parent;
        }
        if(criticalNode != nullptr)
        {
            balanceTree(criticalNode);
        }
    }

    int heightAndBalanceFactor(Node <T> *x)
    {
        //sets height and returns balance factor
        if(x->right == nullptr && x->left == nullptr)
        {
            x->height = 0;
            return 0;
        }
        else if(x->right == nullptr)
        {
            x->height = x->left->height+1;
            return 0-(x->left->height+1);
        }
        else if(x->left == nullptr)
        {
            x->height = x->right->height+1;
            return x->right->height+1;
        }
        else
        {
            x->height = max(x->right->height, x->left->height)+1;
            return x->right->height - x->left->height;
        }
    }

    void rotate(char rotationType, Node<T> *x, Node<T> *y)
    {
        //rotationType : if 'a' performs anti-clockwise rotation, if 'c' performs clockwise rotation
        if(rotationType == 'a')
        {
            y->parent = x->parent;
            x->parent = y;
            x->right = y->left;
            y->left = x;
        }
        else
        {
            y->parent = x->parent;
            x->parent = y;
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
    }

    void balanceTree(Node <T>* x)
    {
        //Balances a subtree rooted at x
        //x: a critical node

        //if a node is inserted in the subtree of x's right child
        if(heightAndBalanceFactor(x) > 0)
        {
            Node <T>* y = x->right; // right child of x
            //if insertion occured somewhere in right subtree of y
            if(heightAndBalanceFactor(y) > 0)
            {
                rotate('a', x, y);
                heightAndBalanceFactor(x);
                heightAndBalanceFactor(y);
                
            }
            //if insertion occured somewhere in left subtree of y
            else
            {
                //rotate clockwise
                rotate('c', y, y->left);
                heightAndBalanceFactor(y);
                heightAndBalanceFactor(y->parent);
                //then rotate anti-clockwise
                rotate('a', x, x->right);
                heightAndBalanceFactor(x);
                heightAndBalanceFactor(x->parent);
            }
            
        }
        //if a node is inserted in the subtree of x's left child
        else
        {
            Node <T>* y = x->left; // left child of x
            //if insertion occured somewhere in left subtree of y
            if(heightAndBalanceFactor(y) < 0)
            {
                rotate('c', x, y);
                heightAndBalanceFactor(x);
                heightAndBalanceFactor(y);
                
            }
            //if insertion occured somewhere in right subtree of y
            else
            {
                //rotate anti-clockwise
                rotate('a', y, y->right);
                heightAndBalanceFactor(y);
                heightAndBalanceFactor(y->parent);
                //then rotate clockwise
                rotate('c', x, x->left);
                heightAndBalanceFactor(x);
                heightAndBalanceFactor(x->parent);

            }
        }
    }

    public: 

    avl()
    {
        root=nullptr;
    }

    void insert(T data){
        Node<T>* newnode=new Node<T>;
        newnode->data=data;
        newnode->left=nullptr;
        newnode->right=nullptr;
        Node<T>* temp=root;
        Node<T>* parent_of_newnode=nullptr;
        while(temp!=nullptr){
            parent_of_newnode=temp;
            if(newnode->data < temp->data)
            {
                temp=temp->left;
            }
            else
            {
                temp=temp->right;
            }
        }
        if(root == nullptr){
            root = newnode;
        }
        else if(newnode->data < parent_of_newnode->data){
            parent_of_newnode->left = newnode;
        }
        else{
            parent_of_newnode->right = newnode;
        }
        newnode->parent=parent_of_newnode;
        updateHeights(newnode);
    }

    void deleteNode(T key)
    {
        Node <T> * z = searchHelper(root, key);
        if(z != nullptr)
        {
            Node <T> * zParent = z->parent;
            if(z->left == nullptr)
            {
                replaceSubtree(z, z->right);
                if(z->right != nullptr)
                {
                    z->right->height = z->height;
                }
                delete z;
            }
            else if(z->right == nullptr)
            {
                replaceSubtree(z, z->left);
                z->left->height = z->height;
                delete z;
            }
            else
            {
                Node <T> * successor = minimum(z->right);
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
                successor->height = z->height;
                delete z;
            }
            updateHeights(zParent);
        }
    
    }

    void display()
    {
        inOrderTraversal(root);
    }

};

int main(){
    avl <int> b;
    for(int i = 1; i < 16; i++)
    {
        b.insert(i);
    }
    b.display();
    b.deleteNode(4);
    cout << endl;
    b.display();
}
