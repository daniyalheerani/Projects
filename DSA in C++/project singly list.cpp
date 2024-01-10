#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <iostream>
#include <stdlib.h>
using namespace std;

template <typename L>
struct node
{
    L value;
    node *next;
};


template <typename T>
class list
{
    private:
    node <T>*head;
    int size;

    public:

    list() = default;

    list(int s, T val)
    {
        //this constructor creates a list of size 's' and initializes it with val
        size = s;
        head = new node<T>;
        node <T> * temp = head;
        temp->value = val;
        for(int i = 1; i < size; i++)
        {
            temp->next = new node<T>;
            temp = temp->next;
            temp->value = val;
           
        }
        temp->value = val;
        temp->next = NULL;
    }

    void insertAtBegining(T val)
    {
        node <T> *newNode = new node<T>;
        newNode->value = val;
        newNode->next = head;
        //newNode is the new head of the list
        head = newNode;
        size++;
    }

    void insertAtEnd(T val)
    {
        node <T> * temp = head;
        for(int i = 0; i < size-1; i++)
        {
            //this loop stops at the last node
            temp = temp->next;
        }
        //create a newNode
        node <T> *newNode = new node<T>;
        newNode->value = val;
        newNode->next = NULL;
        //link the newNode to the previous last node (now second last)
        temp->next = newNode;
        size++;
    }

    void deleteAtBegining()
    {
        node <T> *temp = head;
        head = head->next;
        delete temp;
        size--;
    }

    void deleteAtEnd()
    {
        node <T> * temp = head;
        for(int i = 0; i < size-2; i++)
        {
            //this loop stops at the second last node
            temp = temp->next;
        }
        //free the last node
        delete temp->next;
        //second last node is the last node now
        temp->next = NULL;
        size--;
    }

    bool search(T& val, bool change = false)
    {
        //this function searches the list for the given value
        //returns true if found otherwise returns false
        //change : if true, assigns the value found in the list to the object referred to by T& val
        node <T> * temp = head;
        //this loop stops at the last node
        for(int i = 0; i < size; i++)
        {
            if(temp->value == val)
            {
                if(change)
                {
                    val = temp->value;
                }
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    void replace(T& toReplace, T& replaceWith)
    {
        //toReplace: An object that is to be replaced
        //replaceWith: This object will replace toReplace
        node <T> * temp = head;
        //this loop stops at the last node
        for(int i = 0; i < size; i++)
        {
            if(temp->value == toReplace)
            {
                temp->value = replaceWith;
                return;
            }
            temp = temp->next;
        }
        return;
    }

    void deleteData(T& toDelete)
    {
        //toDelete : An object to be deleted
        node <T> * temp = head;
        if(temp->value == toDelete)
        {
            deleteAtBegining();
        }
        else
        {
            for(int i = 0; i < size-1; i++)
            {
                if(temp->next->value == toDelete)
                {
                    node <T> * del = temp->next;
                    temp->next = temp->next->next;
                    delete del;
                    size--;
                    return;
                }
                temp = temp->next;
            }
        }
        return;
    }

    void display()
    {
        node <T> * temp = head;
        cout << "[";
        for(int i = 0; i < size; i++)
        {
            cout << temp->value << ", ";
            temp = temp->next;
        }
        cout << "\b\b]\n";
    }

    int getSize() {return size;}

    void saveChanges(string filename)
    {
        fstream file(filename, ios::out);
        node <T> * temp = head;
        for(int i = 0; i < size; i++)
        {
            file << temp->value;
            temp = temp->next;
        }
    }

    ~list()
    {
        //freeing the whole list
        node <T> *next = head->next;
        node <T> *cur = head;
        for(int i = 0; i < size-1; i++)
        {
            delete cur;
            cur = next;
            next = next->next;
        }
    }

};

#endif