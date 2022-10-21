#ifndef STRUCTURES_DYNAMICSTACK_H
#define STRUCTURES_DYNAMICSTACK_H

const int INITIAL_SIZE_STACK = 8;

template <typename T>
class DynamicStack
{
public:
    DynamicStack();
    bool empty() const;
    bool full() const;
    T push(T const& item);
    T pop();
    T top() const;
    ~DynamicStack();
private:
    T* items;
    int counter = -1;
    int capacity = 0;
    void resize();
    void eraseStack();
};

#endif //STRUCTURES_DYNAMICSTACK_H
