#ifndef STRUCTURES_LINKEDLIST_H
#define STRUCTURES_LINKEDLIST_H

template <typename T>
class LinkedList
{
public:
    void add(T item);
    T at(int index);
    T operator[](int index);
    int size() const;
    T removeAt(int index);
    ~LinkedList();
private:
    SingularNode<T>* head;
    int currentSize = 0;
    void eraseNode(SingularNode<T>* currentNode);
};


#endif //STRUCTURES_LINKEDLIST_H
