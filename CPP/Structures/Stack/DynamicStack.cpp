#include <iostream>
#include "DynamicStack.h"

// The constructor of the structure.
template <typename T>
DynamicStack<T>::DynamicStack() : capacity(INITIAL_SIZE_STACK)
{
    this->items = new T[this->capacity];
}

// Returns TRUE when there are no elements in the structure.
// Returns FALSE when there is at least one element in the structure.
template <typename T>
bool DynamicStack<T>::empty() const
{
    return this->counter <= -1;
}

// Returns TRUE when the count of the structure's items is equal to its current capacity.
// Returns FALSE otherwise.
template <typename T>
bool DynamicStack<T>::full() const
{
    return this->counter == this->capacity - 1;
}

// Adds new element to the structure
// at the back of the element's array.
template <typename T>
T DynamicStack<T>::push(T const& item)
{
    if(full())
    {
        resize();
    }

    this->items[++(this->counter)] = item;

    return this->items[this->counter];
}

// Removes the top element of the structure.
template <typename T>
T DynamicStack<T>::pop()
{
    if(empty())
    {
        std::cerr << "The stack is empty. Add element before trying to delete one." << std::endl;
        return T();
    }

    return this->items[(this->counter)--];
}

// Returns the top element of the elements' array.
// Can be called "peek" too.
template <typename T>
T DynamicStack<T>::top() const
{
    if(empty())
    {
        std::cerr << "The stack is empty. Add element before trying to delete one." << std::endl;
        return T();
    }

    return this->items[this->counter];
}

// Resizes the dynamically created array
// of the elements of the structure.
template <typename T>
void DynamicStack<T>::resize()
{
    this->capacity *= 2;
    T* temp = new T[this->capacity];

    for (int i = this->counter; i >= 0 ; --i)
    {
        temp[i] = this->items[i];
    }

    this->items = temp;
};

// Deletes the elements' array in the structure.
template <typename T>
void DynamicStack<T>::eraseStack()
{
    delete[] this->items;
}

// The destructor of the structure -
// uses an additional function "eraseStack".
template <typename T>
DynamicStack<T>::~DynamicStack()
{
    eraseStack();
}