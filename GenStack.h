
#ifndef GENSTACK_H
#define GENSTACK_H

#include <iostream>
#include "GenDoubleLinkedList.h"

using namespace std;

template<typename T>
class GenStack
{
    public:
    //constructor
        GenStack();
        GenStack(int maxSize);
        ~GenStack();

        //central methods
        void push(int k, T data);
        T pop();
        T peek();

        //support methods
        bool isFull();
        bool isEmpty();

        //data fields
        int size;
        int mSize;

        GenDoubleLinkedList<T> myList; 

};

//creates a stack with a defualt value
template<typename T>
GenStack<T>::GenStack()
{
    myList = new GenDoubleLinkedList<T>();
    size = 0;
    mSize = 5;
}

//creates the starting array size for the stack based on a value given
template<typename T>
GenStack<T>::GenStack(int maxSize)
{
    myList = new GenDoubleLinkedList<T>();
    mSize = maxSize;
    size = 0;
}

//destructor for the stack class
template<typename T>
GenStack<T>::~GenStack()
{
    delete myList;
}

//checks to see if the array is full
//if the array is full it creates a new array double the size
//it then sets the pointer of the original array to the new array and deletes the old array
template<typename T>
void GenStack<T>::push(int k, T data)
{
    if(isFull())
    {
        myList->removeBack();
        --size;
    }
    myList->insertFront(k, data);
    ++size;
}

//returns a value from the top of the stack
//top is decremented so the value cannot be recovered
//will throw -1 if the stack is empty
template<typename T>
T GenStack<T>::pop()
{
    //error chacking, make sure isEmpty
    if(isEmpty())
    {
        throw -1;
    }
    return myList.removeFront();
    --size;
}

//returns the value at the top of the stack without decrementing the top
//will throw -1 if the stack is empty
template<typename T>
T GenStack<T>::peek()
{
    //error chacking, make sure isEmpty
    if(isEmpty())
    {
        throw -1;
    }
    return myList.front->data;
}

//checks to see if the stack is full
template<typename T>
bool GenStack<T>::isFull()
{
    //error chacking, make sure full
    if(size == mSize)
    {
        return true;
    }
    return false;
}

//checks to see if the stack is empty
template<typename T>
bool GenStack<T>::isEmpty()
{
    //error chacking, make sure empty
    if(size<=0)
    {
        return true;
    }
    return false;
}


#endif
