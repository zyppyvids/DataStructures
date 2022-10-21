#include <iostream>
#include "DynamicQueue.h"

// The constructor of the structure.
template<typename T>
DynamicQueue<T>::DynamicQueue() : capacity(INITIAL_SIZE_QUEUE)
{
    this->items = new T[this->capacity];
}

// Returns the element in the back
// of the elements' array of the structure.
template <typename T>
T DynamicQueue<T>::back() const
{
    if(this->currentSize <= 0)
    {
        std::cerr << "No items in the queue." << std::endl;
        return T();
    }

    return this->items[this->tail];
}

// Returns the element in the front
// of the elements' array of the structure.
template <typename T>
T DynamicQueue<T>::front() const
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
bool DynamicQueue<T>::empty() const
{
    return this->currentSize == 0;
}

// Returns the count of the elements in the structure.
template <typename T>
int DynamicQueue<T>::size() const
{
    return this->currentSize;
}

// Returns TRUE when the current size of the structure is equal to its current capacity.
// Returns FALSE otherwise.
template <typename T>
bool DynamicQueue<T>::full() const
{
    return this->currentSize == this->capacity;
}

// Adds an element to the structure
// at the back of the elements' array.
template <typename T>
T DynamicQueue<T>::enqueue(T item)
{
    if(this->currentSize >= this->capacity)
    {
        resize();
    }

    if (this->tail == this->capacity - 1)
    {
        resize();
    }

    this->items[++(this->tail)] = item;

    this->currentSize++;

    return this->items[this->tail];
}

// Removes an element from the structure
// at the front of the elements' array.
template <typename T>
T DynamicQueue<T>::dequeue(bool changeSize)
{
    if(this->currentSize <= 0)
    {
        std::cerr << "The queue is empty." << std::endl;
        return T();
    }

    if(changeSize)
    {
        this->currentSize--;
    }


    return this->items[this->head++];
}

// Resizes the elements' array when there is no more space in it.
template <typename T>
void DynamicQueue<T>::resize()
{
    this->capacity *= 2;
    T* temp = new T[this->capacity];

    int tempSize = size();

    for (int i = 0; i <= tempSize; i++)
    {
        temp[i] = dequeue(false);
    }

    this->items = temp;

    this->head = 0;
    this->tail = tempSize - 1;
};

// Deletes the elements' array of the structure.
template <typename T>
void DynamicQueue<T>::eraseQueue()
{
    delete[] this->items;
}

// The destructor of the structure -
// uses an additional function "eraseQueue".
template<typename T>
DynamicQueue<T>::~DynamicQueue()
{
    eraseQueue();
}

