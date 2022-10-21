#include <iostream>
#include "Stack.h"

// Returns TRUE when there are no elements in the structure.
// Returns FALSE when there is at least one element in the structure.
template <typename T>
bool Stack<T>::empty() const
{
    return this->counter <= -1;
}

// Returns TRUE when there is no more space in the structure.
// Returns FALSE when there is more space in the structure.
template <typename T>
bool Stack<T>::full() const
{
    return this->counter == MAXSIZE_STACK - 1;
}

// Adds a new element to the structure at its top.
template <typename T>
T Stack<T>::push(T const& item)
{
    if(full())
    {
        std::cerr << "The stack is full. You can try using a dynamic stack." << std::endl;
        return T();
    }

    this->items[++(this->counter)] = item;

    return this->items[this->counter];
}

// Removes the top element of the structure.
template <typename T>
T Stack<T>::pop()
{
    if(empty())
    {
        std::cerr << "The stack is empty. Add element before trying to delete one" << std::endl;
        return T();
    }

    return this->items[(this->counter)--];
}

// Returns the top element of the structure.
// Can be called "peek" too.
template <typename T>
T Stack<T>::top() const
{
    if(empty())
    {
        std::cerr << "The stack is empty. Add element before trying to delete one" << std::endl;
        return T();
    }

    return this->items[this->counter];
}