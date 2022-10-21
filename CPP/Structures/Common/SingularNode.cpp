#include "SingularNode.h"

// The constructor of the structure.
template <typename T>
SingularNode<T>::SingularNode(T item)
{
    this->data = item;
    this->next = nullptr;
}

// Gets the node connected to the current node.
template <typename T>
SingularNode<T>* SingularNode<T>::getNext() const
{
    return this->next;
}

// Sets the node connected to the current node.
template <typename T>
void SingularNode<T>::setNext(SingularNode<T>* nextIt)
{
    this->next = nextIt;
}

// Gets the data of the node.
template <typename T>
T SingularNode<T>::getData() const
{
    return this->data;
}
