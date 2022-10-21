#ifndef STRUCTURES_SINGULARNODE_H
#define STRUCTURES_SINGULARNODE_H

template <typename T>
class SingularNode
{
public:
    SingularNode(T item);
    SingularNode<T>* getNext() const;
    void setNext(SingularNode<T>* nextIt);
    T getData() const;
private:
    T data;
    SingularNode* next;
};

#endif //STRUCTURES_SINGULARNODE_H
