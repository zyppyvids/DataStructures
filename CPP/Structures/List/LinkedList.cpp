#include "LinkedList.h"

// Adds a new node connected to the bottom
// of the nodes in the structure.
template <typename T>
void LinkedList<T>::add(T item)
{
    if (!this->head)
    {
        this->head = new SingularNode<T>(item);
        this->currentSize++;

        return;
    }

    SingularNode<T>* currentNode = this->head;

    while(currentNode->getNext())
    {
        currentNode = currentNode->getNext();
    }

    currentNode->setNext(new SingularNode<T>(item));

    this->currentSize++;
}

// Returns the element in the given index.
template <typename T>
T LinkedList<T>::at(int index)
{
    SingularNode<T>* currentNode = this->head;

    for (int i = 0; i < index; ++i)
    {
        currentNode = currentNode->getNext();
    }

    return currentNode->getData();
}

// Returns the element in the given index: a[0] -> returns the element at the index 0.
template<typename T>
T LinkedList<T>::operator[](int index)
{
    return at(index);
}

// Removes an element at a specific index.
template <typename T>
T LinkedList<T>::removeAt(int index)
{
    if(index >= this->currentSize)
    {
        std::cerr << "This index is out of the bounds of the structure." << std::endl;
        return T();
    }

    SingularNode<T>* currentNode = this->head;

    for (int i = 0; i < index - 1; ++i)
    {
        currentNode = currentNode->getNext();
    }

    T returnable = currentNode->getNext()->getData();

    currentNode->setNext(currentNode->getNext()->getNext());

    this->currentSize--;

    return returnable;
}

// Returns the count of the elements in the structure.
template <typename T>
int LinkedList<T>::size() const
{
    return this->currentSize;
}

// Gets to the bottom of the given node and
// deletes this node and every node above it recursively.
template <typename T>
void LinkedList<T>::eraseNode(SingularNode<T>* current)
{
    if(current->getNext())
    {
        eraseNode(current->getNext());
    }

    delete current;
}

// The destructor of the structure -
// uses an additional function "eraseNode".
template <typename T>
LinkedList<T>::~LinkedList()
{
    eraseNode(this->head);
}



