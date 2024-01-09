#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <iostream>
#include <stdlib.h>
using namespace std;

template <typename L>
struct node
{
    L data;
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
        newNode->data = val;
        newNode->next = nullptr;
        //link the newNode to the previous last node (now second last)
        if(head == nullptr)
        {
            head = newNode;
        }
        else
        {
            temp->next = newNode;
        }
        size++;
    }

    void deleteAtBegining()
    {
        node <T> *temp = head;
        head = head->next;
        delete temp;
        size--;
    }


    template <typename K>
    node<T>* search(K& val)
    {
        //this function searches the list for the given data
        //returns pointer to that node if found otherwise returns nullptrptr
        node <T> * temp = head;
        //this loop stops at the last node
        for(int i = 0; i < size; i++)
        {
            if(temp->data == val)
            {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }

    template <typename K>
    int countInstances(K &key)
    {
        int count = 0;
        node <T> * temp = head;
        //this loop stops at the last node
        for(int i = 0; i < size; i++)
        {
            if(temp->data == key)
            {
                count++;
            }
            temp = temp->next;
        }
        return count;
    }

    template <typename K>
    bool deleteData(K& toDelete)
    {
        //toDelete : An object to be deleted
        node <T> * temp = head;
        if(temp->data == toDelete)
        {
            deleteAtBegining();
        }
        else
        {
            for(int i = 0; i < size-1; i++)
            {
                if(temp->next->data == toDelete)
                {
                    node <T> * del = temp->next;
                    temp->next = temp->next->next;
                    delete del;
                    size--;
                    return true;
                }
                temp = temp->next;
            }
        }
        return false;
    }

    template <typename K>
    int displaySpecific(K &key, void (T::*printTitle)(), void(T::*printData)())
    {
        //display specific entries equal to key using the given functions and returns the number of entries
        node <T> * temp = head;
        int count = 0;
        (temp->data.*printTitle)();
        for(int i = 0; i < size; i++)
        {
            if(temp->data == key)
            {
                count++;
                (temp->data.*printData)();
            }
            temp = temp->next;
        }
        return count;
    }

    void displayAll(void (T::*printTitle)(), void(T::*printData)())
    {
        //display all entries using the functions given
        node <T> * temp = head;
        (temp->data.*printTitle)();
        for(int i = 0; i < size; i++)
        {
            (temp->data.*printData)();
            temp = temp->next;
        }
    }

    T getMax()
    {
        node <T> * temp = head;
        T maximum;
        for(int i = 0; i < size; i++)
        {
            if(temp->data > maximum)
            {
                maximum = temp->data;
            }
            temp = temp->next;
        }
        return maximum;
    }

    int getSize() {return size;}

    void outputToFile(string filename)
    {
        fstream file(filename, ios::out);
        node <T> * temp = head;
        for(int i = 0; i < size; i++)
        {
            file << temp->data;
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