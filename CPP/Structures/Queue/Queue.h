#ifndef STRUCTURES_QUEUE_H
#define STRUCTURES_QUEUE_H

const int MAXSIZE_QUEUE = 20;

template <typename T>
class Queue
{
public:
    T back() const;
    T front() const;
    bool empty() const;
    int size() const;
    bool full() const;
    T enqueue(T item);
    T dequeue();
private:
    T items[MAXSIZE_QUEUE];
    int head = 0;
    int tail = -1;
    int currentSize = 0;
};

#endif //STRUCTURES_QUEUE_H
