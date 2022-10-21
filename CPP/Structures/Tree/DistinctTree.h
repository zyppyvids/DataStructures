#ifndef STRUCTURES_DISTINCTTREE_H
#define STRUCTURES_DISTINCTTREE_H

template <typename T>
class DistinctTree
{
public:
    void add(T item, T parent = T());
    int size() const;
    MultiNode<T>* getBase() const;
    void print(MultiNode<T>* head, int counter = 0, int currentChildCounter = 0);
    ~DistinctTree();
private:
    MultiNode<T>* base;
    int currentSize = 0;
    void internalAdd(T value, MultiNode<T>* head, T item);
    void eraseNode(MultiNode<T>* head);
};


#endif //STRUCTURES_DISTINCTTREE_H
