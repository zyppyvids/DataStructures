#include "MultiNode.h"

// A constructor of the structure using only data as input.
template <typename T>
MultiNode<T>::MultiNode(T item) : capacity(INITIAL_CAPACITY_MNODE)
{
    this->data = item;
    this->parent = nullptr;
    this->children = new MultiNode<T>*[INITIAL_CAPACITY_MNODE];
}

// A constructor of the structure using data and parent as input.
template <typename T>
MultiNode<T>::MultiNode(T item, MultiNode<T>* currentParent) : capacity(INITIAL_CAPACITY_MNODE)
{
    this->data = item;
    this->parent = currentParent;
    this->children = new MultiNode<T>*[INITIAL_CAPACITY_MNODE];
}

// Gets the children connected to the current node.
template <typename T>
MultiNode<T>** MultiNode<T>::getChildren()
{
    return this->children;
}

// Returns TRUE if there is at least one child connected to the current node.
// Returns FALSE if there are no children connected to the current node.
template <typename T>
bool MultiNode<T>::hasChildren() const
{
    return this->childrenCount > 0;
}

// Resizes the children array when there is no more space.
template <typename T>
void MultiNode<T>::resize()
{
    this->capacity *= 2;

    MultiNode<T>** temp = new MultiNode<T>*[this->capacity];

    for (int i = 0; i < this->childrenCount; ++i)
    {
        temp[i] = this->children[i];
    }

    this->children = temp;
}

// Adds a child connected to the current node.
template <typename T>
void MultiNode<T>::addChild(MultiNode<T>* child)
{
    if(this->childrenCount >= this->capacity)
    {
        resize();
    }

    this->children[(this->childrenCount)++] = child;
}

// Gets the count of the children connected to the current node.
template <typename T>
int MultiNode<T>::getChildrenCount() const
{
    return this->childrenCount;
}

// Returns TRUE when the current node has a parent connected to it.
// Returns FALSE otherwise.
template <typename T>
bool MultiNode<T>::hasParent()
{
    return this->parent;
}

// Gets the parent of the current node.
template <typename T>
MultiNode<T>* MultiNode<T>::getParent()
{
    return this->parent;
}

// Sets the parent of the current node.
template <typename T>
void MultiNode<T>::setParent(MultiNode<T>* currentParent)
{
    this->parent = currentParent;
}

// Returns the data of the current node.
template <typename T>
T MultiNode<T>::getData() const
{
    if(!this)
    {
        return T();
    }
    return this->data;
}
