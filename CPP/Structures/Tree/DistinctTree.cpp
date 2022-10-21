#include "DistinctTree.h"

// [AUTHOR COMMENT] This was tough af.
// Adds an element "itParent" as a child of the element "item".
template <typename T>
void DistinctTree<T>::add(T item, T itParent)
{
    if (item == itParent)
    {
        std::cerr << "No duplicate values allowed." << std::endl;

        return;
    }

    if (!this->base)
    {
        this->base = new MultiNode<T>(item);
        this->currentSize++;

        return;
    }

    if (itParent == T())
    {
        std::cerr << "Parent cannot be null if the base is set." << std::endl;

        return;
    }

    // [HOW IT WORKS]
    // FINAL IDEA: Use distinct values as a way of
    // inserting elements - implement searching and
    // find a node with a certain value, then
    // add the given item as its child

    internalAdd(itParent, this->base, item);
    this->currentSize++;
}

// [AUTHOR COMMENT] This was tough too.
// An additional function that is used to internally
// add an element and fix its parent-child relationship.
template <typename T>
void DistinctTree<T>::internalAdd(T value, MultiNode<T>* head, T item)
{
    if(!head)
    {
        return;
    }

    if(head->getData() == value)
    {
        head->addChild(new MultiNode<T>(item, head));
        return;
    }

    MultiNode<T>** children = head->getChildren();

    int counter = 0;

    while(children[counter] && counter < head->getChildrenCount())
    {
        internalAdd(value, children[counter], item);
        counter++;
    }
}

// Returns the size of the given tree - the count
// of all elements in the tree.
template<typename T>
int DistinctTree<T>::size() const
{
    return this->currentSize;
}

// Gets the base/root of the tree
template<typename T>
MultiNode<T> *DistinctTree<T>::getBase() const
{
    if(!(this->base))
    {
        std::cerr << "You haven't added any elements to the tree. Add one first to be able to get its base." << std::endl;
    }

    return this->base;
}

//Prints the tree in a structure like this:
//└───1
//    ├───2
//    │   ├───10
//    │   │   └───9
//    │   ├───8
//    │   │   └───13
//    │   └───15
//    └───3
template <typename T>
void DistinctTree<T>::print(MultiNode<T>* head, int counter, int currentChildCounter)
{
    if(!head)
    {
        return;
    }

    for (int i = 0; i < counter; ++i)
    {
        std::cout << "   " << (i < counter - 1 ? (i == 0 ? " │" : "│") : (i == 0 ? " " : ""));
    }

    std::cout << (head->hasParent() && (currentChildCounter < (head->getParent()->getChildrenCount()) - 1) ? "├───" : "└───") << head->getData() << std::endl;

    if(!head->hasChildren())
    {
        return;
    }

    MultiNode<T>** children = head->getChildren();
    int childCounter = 0;
    while(children[childCounter] && childCounter < head->getChildrenCount())
    {
        print(children[childCounter], counter + 1, childCounter);
        childCounter++;
    }
}

// Finds the bottom of a given node and deletes it and
// recursively every node above it.
template <typename T>
void DistinctTree<T>::eraseNode(MultiNode<T>* head)
{
    if(!head)
    {
        return;
    }

    if(!head->hasChildren())
    {
        delete head;
        return;
    }

    MultiNode<T>** children = head->getChildren();

    int counter = 0;

    while(children[counter] && counter < head->getChildrenCount())
    {
        eraseNode(children[counter]);
        counter++;
    }

    delete head;
}

// The destructor of the structure
// - uses an additional function "eraseNode".
template<typename T>
DistinctTree<T>::~DistinctTree()
{
    eraseNode(this->base);
}
