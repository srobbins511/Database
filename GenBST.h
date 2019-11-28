#include <iostream>
#include "GenTreeNode.h"


using namespace std;

template<typename T>
class GenBST
{
    private:
        GenTreeNode<T> *root;
    public:
        GenBST();
        ~GenBST();
        void insert(int k, T d);
        bool search(int value);

        bool deleteNode(int key);

        //Helper Functions
        bool isEmpty();
        GenTreeNode<T>* getMin();
        GenTreeNode<T>* getMax();
        void printTree();
        GenTreeNode<T>* getNode(int key);
        void recPrint(GenTreeNode<T> *node);
        void GenTreeBreakdown(GenTreeNode<T>* start);
        GenTreeNode<T>* getSuccessor(GenTreeNode<T> *d);
}; 

template<typename T>
GenBST<T>::GenBST()
{
    root = NULL; //empty tree
}

template<typename T>
GenBST<T>::~GenBST()
{
    GenTreeBreakdown(root);
}

template<typename T>
void GenBST<T>::GenTreeBreakdown(GenTreeNode<T>* start)
{
    if(start->left != NULL)
    {
        GenTreeBreakdown(start->left);
    }
    if(start->right != NULL)
    {
        GenTreeBreakdown(start->right);
    }
    delete start;
}

template<typename T>
bool GenBST<T>::search(int value)
{
    if(root == NULL) //empty tree 
    {
        return false;
    }
    else
    {
        //tree is not empty
        GenTreeNode<T> *current = root;

        while(current->key != value)
        {
            if(value < current->key)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }

            if(current == NULL)
            {
                //did not find the value
                return false;
            }
        }
    }
    return true;
}

template<typename T>
void GenBST<T>::insert(int value, T d)
{
    GenTreeNode<T> *node = new GenTreeNode<T>(value, d);
    if(root == NULL)
    {
        //empty tree
        root = node;
    }
    else
    {
        //tree is not empty, need to find the insertion location
        GenTreeNode<T> *current = root;
        GenTreeNode<T> *parent = NULL;

        while(true)
        {
            parent = current;
            if(value < current->key)
            {
                current = current->left;
                //going left
                if(current == NULL)
                {
                    //found insertion point
                    parent->left = node;
                    break;
                }
            }
            else if(value > current->key)
            {
                current = current->right;
                //going right
                if(current == NULL)
                {
                    //found insertion point
                    parent->right = node;
                    break;
                }
            }
        }
    }
}

template<typename T>
void GenBST<T>::recPrint(GenTreeNode<T> *node)
{
    if(node == NULL)
    {
        return;
    }
    recPrint(node->left);
    cout << node->key << endl;
    recPrint(node->right);
}

template<typename T>
void GenBST<T>::printTree()
{
    recPrint(root);
}

template<typename T>
GenTreeNode<T>* GenBST<T>::getMax()
{
    GenTreeNode<T> *current = root;
    if(root == NULL)
    {
        return NULL;
    }
    while(current->right != NULL)
    {
        current = current->right;
    }

    return (current);
}

template<typename T>
GenTreeNode<T>* GenBST<T>::getMin()
{
    GenTreeNode<T> *current = root;
    if(root == NULL)
    {
        return NULL;
    }
    while(current->left != NULL)
    {
        current = current->left;
    }

    return (current);
}

template<typename T>
bool GenBST<T>::deleteNode(int value)
{
    if(root == NULL)
    {
        return false;
    }

    GenTreeNode<T> *current = root;
    GenTreeNode<T> *parent = root;
    bool isLeft = true;

    //now lets look for the node

    while(current->key != value)
    {
        parent = current;
        if(value < current->key)
        {
            isLeft = true;
            current = current->left;
        }
        else
        {
            isLeft = false;
            current = current->right;
        }

        if(current == NULL)
        {
            //did not find the value
            return false;
        }
    }

    //if we make it here that means that we found the node that needs to be deleted 
    //now check the cases

    //no children
    if(current->left == NULL && current->right == NULL)
    {
        if(current == root)
        {
            root = NULL;
        }
        else if(isLeft)
        {
            parent->left = NULL;
        }
        else{
            parent->right = NULL;
        }
    }
    
    //node to be deleted has one child, need to determine if child is left or right and proceed

    else if(current->right == NULL)//child has no right children
    {
        if(current == root)
        {
            root = current->left;
        }
        else if(isLeft)
        {
            parent->left = current->left;
        }
        else{
            parent->right = current->left;
        }
    }
    else if(current->left == NULL)//child has no left children
    {
        if(current == root)
        {
            root = current->right;
        }
        else if(isLeft)
        {
            parent->left = current->right;
        }
        else{
            parent->right = current->right;
        }
    }
    else//node to be deleted has two children
    {
        GenTreeNode<T> *successor = getSuccessor(current);
        if(current == root)
        {
            root = successor;
        }
        else if(isLeft)
        {
            parent->left = successor;
        }
        else
        {
            parent->right = successor;
        }
        successor->left = current->left;
    }
    return true;
}

template<typename T>
GenTreeNode<T>* GenBST<T>::getSuccessor(GenTreeNode<T> *d) //d is the node to be deleted
{
    GenTreeNode<T> *sp = d; //sp is successors parent and is initialized to d
    GenTreeNode<T> *successor = d;
    GenTreeNode<T> *current = d->right; //start one right 
    while(current != NULL) //one right all the way left
    {
        sp = successor;
        successor = current;
        current = current->left;
    }
    if(successor != d->right)
    {
        //successor is a descendent of the right child
        sp->left = successor->right;
        successor->right = d->right;
    }
    return successor;
}

template<typename T>
GenTreeNode<T>* GenBST<T>::getNode(int key)
{
    GenTreeNode<T> *current;
    if(root == NULL) //empty tree 
    {
        return NULL;
    }
    else
    {
        //tree is not empty
        current = root;

        while(current->key != key)
        {
            if(key < current->key)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }

            if(current == NULL)
            {
                //did not find the value
                return NULL;
            }
        }
    }
    return current;
}
