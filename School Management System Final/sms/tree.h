#ifndef TREE_H
#define TREE_H

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

    void inOrderTraversal(ostream &out, Node <T>* x)
    {
    
        if(x!=nullptr)
        {
            inOrderTraversal(out, x->left);
            out << x->data;
            inOrderTraversal(out, x->right);
            
        }
    }

    template <typename K>
    Node<T>* searchHelper(Node <T>* x,K &key){
        if(x==nullptr){
            return nullptr;
        }
        else if(x->data == key){
            return x;
        }
        else if(x->data < key){
            return searchHelper(x->left,key);
        }
        else{
           return searchHelper(x->right,key);
        }
        
    }

    template <typename K>
    void displayHelper(Node <T>* x, K &key, void (T::*print)(), bool specific)
    {
        if(x != nullptr)
        {
            displayHelper(x->left, key, print, specific);
            if(x->data == key || !specific)
            {
                (x->data.*print)();
            }
            displayHelper(x->right, key, print, specific);
        }
    }

    template <typename K>
    int countInstancesHelper(Node<T>* x, K &key)
    {
        if(x!=nullptr)
        {
            if(x->data == key)
            {
                return countInstancesHelper(x->left, key)+countInstancesHelper(x->right, key)+1;
            }
            else
            {
                return countInstancesHelper(x->left, key)+countInstancesHelper(x->right, key);
            }
            
        }
        else
        {
            return 0;
        }
    }

    Node <T> * minimum(Node <T>* x)
    {
        //finds minimum in x's subtree
        while(x->left!=nullptr)
        {
            x=x->left;
        }
        return x;
    }

    Node <T> * maximum(Node <T>* x)
    {
        //finds maximum in x's subtree
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
        //updates height of nodes from x up to the tree root
        //also balances the tree if balance factor is disturbed after insertion or deletion
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

    template <typename K>
    void deleteNode(K key)
    {
        Node <T> * z = searchHelper(root, key);
        if(z != nullptr)
        {
            Node <T> * zParent = z->parent;
            //case 1: z has no childs, or a right child
            if(z->left == nullptr)
            {
                replaceSubtree(z, z->right);
                if(z->right != nullptr)
                {
                    heightAndBalanceFactor(z->right);
                }
                delete z;
            }
            //case 2: z has a left child
            else if(z->right == nullptr)
            {
                replaceSubtree(z, z->left);
                heightAndBalanceFactor(z->left);
                delete z;
            }
            //case 3: z has both child
            else
            {
                Node <T> * successor = minimum(z->right);
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
                heightAndBalanceFactor(successor);
                delete z;
            }
            updateHeights(zParent);
        }
    
    }

    
    template <typename K>
    int countInstances(K &key)
    {
        return countInstancesHelper(root, key);
    }

    template <typename K>
    Node<T>* search(K &data)
    {
        return searchHelper(root,data);
    }

    Node<T>* getMax()
    {
        return maximum(root);
    }

    void outputTo(ostream &out)
    {
        inOrderTraversal(out, root);
    }

    template <typename K>
    void display(K &key, void (T::*printTitle)(), void (T::*printData)(), bool specific = true)
    {
        (root->data.*printTitle)();
        displayHelper(root, key, printData, specific);
    }

    bool isEmpty()
    {
        if(root == nullptr)
        {
            return true;
        }
        return false;
    }

};

#endif