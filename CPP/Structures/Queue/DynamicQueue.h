#ifndef STRUCTURES_DYNAMICQUEUE_H
#define STRUCTURES_DYNAMICQUEUE_H

const int INITIAL_SIZE_QUEUE = 2;

template <typename T>
class DynamicQueue
{
public:
    DynamicQueue();
    T back() const;
    T front() const;
    bool empty() const;
    int size() const;
    bool full() const;
    T enqueue(T item);
    T dequeue(bool changeSize = true);
    ~DynamicQueue();
private:
    T* items;
    int head = 0;
    int tail = -1;
    int currentSize = 0;
    int capacity = 0;
    void resize();
    void eraseQueue();
};


#endif //STRUCTURES_DYNAMICQUEUE_H
