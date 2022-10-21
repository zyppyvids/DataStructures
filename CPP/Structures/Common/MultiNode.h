#ifndef STRUCTURES_MULTINODE_H
#define STRUCTURES_MULTINODE_H

const int INITIAL_CAPACITY_MNODE = 2;

template <typename T>
class MultiNode
{
public:
    MultiNode(T item);
    MultiNode(T item, MultiNode<T>* parent);
    MultiNode<T>** getChildren();
    bool hasChildren() const;
    void addChild(MultiNode<T>* child);
    int getChildrenCount() const;
    bool hasParent();
    MultiNode<T>* getParent();
    void setParent(MultiNode<T>* currentParent);
    T getData() const;
private:
    T data;
    MultiNode* parent;
    MultiNode** children;
    int childrenCount = 0;
    int capacity = 0;
    void resize();
};

#endif //STRUCTURES_MULTINODE_H
