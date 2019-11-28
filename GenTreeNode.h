#include <iostream>

using namespace std;

template<typename T>
class GenTreeNode
{
    public:
        GenTreeNode();
        GenTreeNode(int k, T d); // k is the key, which in this example is also the data
        ~GenTreeNode(); // when creating template class destructor must be virtual

        int key;
        T data;
        GenTreeNode<T> *left;
        GenTreeNode<T> *right;
};

template<typename T>
GenTreeNode<T>::GenTreeNode()
{
    key = NULL;
    data = NULL;
    left = NULL;
    right = NULL;
}

template<typename T>
GenTreeNode<T>::GenTreeNode(int k, T d)
{
    key = k;
    T data;
    left = NULL;
    right = NULL;
}

template<typename T>
GenTreeNode<T>::~GenTreeNode()
{
    delete data;
}
