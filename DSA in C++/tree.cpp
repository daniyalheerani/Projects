#include <iostream>

using namespace std;
template<typename L>
struct Node{
L data;
Node* left;
Node* right;
Node* parent;
};

template <typename T>
class binaryTree{
    Node<T>* root;
    int height;

    void display(Node <T>* x){
    
        if(x!=nullptr){
            display(x->left);
            cout<< x->data << " ";
            display(x->right);
            
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

    Node <T> * minimum(Node <T>* x){
        while(x->left!=nullptr){
            x=x->left;
        }
        return x;
    }


    public: 
    binaryTree(){
        root=nullptr;
        height=0;
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
            if(newnode->data < temp->data){
                temp=temp->left;
            }
            else{
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
        
        
    }

    void inOrderTraversal()
    {
        display(root);
    }
    
    bool search(T &data){
        Node <T> *foundData = searchHelper(root,data);
        if(foundData == nullptr)
        {
            return false;
        }
        else
        {
            data = foundData->data;
            return true;
        }
    }

    void replace(Node <T>* u, Node <T>* v){
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
    

    void deleteFromTree(T key)
    {
        Node <T> * z = searchHelper(root, key);
        if(z != nullptr)
        {

            if(z->left == nullptr)
            {
                replace(z, z->right);
                delete z;
            }
            else if(z->right == nullptr)
            {
                replace(z, z->left);
                delete z;
            }
            else
            {
                Node <T> * successor = minimum(z->right);
                if(successor != z->right)
                {
                    replace(successor, successor->right);
                    successor->right = z->right;
                    successor->right->parent = successor;
                }
                replace(z, successor);
                successor->left = z->left;
                successor->left->parent = successor;
                delete z;
            }

        }
    
    }
    
};

int main(){
    binaryTree <int> b;
    b.insert(0);
    b.insert(4);
    b.insert(3);
    b.insert(5);
    b.insert(8);
    b.insert(-10);
    b.insert(34);
    b.inOrderTraversal();
    int a = 4;
    /* if(b.search(a))
    {
        cout << "found\n";

    }
    else{
        cout << "not found\n";
    } */
    b.deleteFromTree(a);
    cout << endl;
    b.inOrderTraversal();


}
