#ifndef STRUCTURES_STACK_H
#define STRUCTURES_STACK_H

const int MAXSIZE_STACK = 100;

template <typename T>
class Stack
{
public:
    bool empty() const;
    bool full() const;
    T push(T const& item);
    T pop();
    T top() const;
private:
    T items[MAXSIZE_STACK];
    int counter = -1;
};


#endif //STRUCTURES_STACK_H
