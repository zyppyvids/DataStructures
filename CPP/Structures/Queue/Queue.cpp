#include <iostream>
#include "Queue.h"

// Returns the element at the back of the elements' array.
template <typename T>
T Queue<T>::back() const
{
    if(this->currentSize <= 0)
    {
        std::cerr << "No items in the queue." << std::endl;
        return T();
    }

    return this->items[this->tail];
}

// Returns the element at the front of the elements' array.
template <typename T>
T Queue<T>::front() const
{
    if(this->currentSize <= 0)
    {
        std::cerr << "No items in the queue." << std::endl;
        return T();
    }

    return this->items[this->head];
}

// Returns TRUE when there are no elements in the structure.
// Returns FALSE when there is at least one element in the structure.
template <typename T>
bool Queue<T>::empty() const
{
    return this->currentSize == 0;
}

// Returns the count of the elements in the structure.
template <typename T>
int Queue<T>::size() const
{
    return this->currentSize;
}

// Returns TRUE when there is no more space for new elements.
// Returns FALSE when there is more space for new elements.
template <typename T>
bool Queue<T>::full() const
{
    return this->currentSize == MAXSIZE_QUEUE;
}

// Adds an element to the structure
// at the back of the elements' array
template <typename T>
T Queue<T>::enqueue(T item)
{
    if(this->currentSize >= MAXSIZE_QUEUE)
    {
        std::cerr << "The queue is full. Try using a dynamic queue instead." << std::endl;
        return T();
    }

    if (this->tail == MAXSIZE_QUEUE - 1)
    {
        this->tail = -1;
    }

    this->items[++(this->tail)] = item;

    (this->currentSize)++;

    return this->items[this->tail];
}

// Removes an element from the structure
// from the front of the elements' array.
template <typename T>
T Queue<T>::dequeue()
{
    if(this->currentSize <= 0)
    {
        std::cerr << "The queue is empty." << std::endl;
        return T();
    }

    if(this->head >= MAXSIZE_QUEUE)
    {
        this->head = 0;
    }

    (this->currentSize)--;

    return this->items[this->head++];
}

