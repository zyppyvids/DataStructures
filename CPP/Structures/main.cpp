/*
 * Made by: Emil Yordanov.
 * To start it you should:
 *      1. See what structure you want to test;
 *      2. Uncomment the definition of the structure you want to test;
 *      3. Build the project and see the given tests.
 * More explanation on the classes in their headers and .cpp files with comments above every function.
 */
#include <iostream>
// Common
#include "Common/SingularNode.cpp"
#include "Common/MultiNode.cpp"

// Stack
//#define STACK
#include "Stack/Stack.cpp"
#include "Stack/DynamicStack.cpp"

// Queue
//#define QUEUE
#include "Queue/Queue.cpp"
#include "Queue/DynamicQueue.cpp"

// List
//#define LIST
#include "List/LinkedList.cpp"

// Tree
//#define TREE
#include "Tree/DistinctTree.cpp"

// The tests of DistinctTree.cpp
void DISTINCTTREE_TESTS()
{
    std::cout << "DISTINCTIVE TREE TESTS" << std::endl << std::endl;

    DistinctTree<int> ints = DistinctTree<int>();

    std::cout << "DISTINCTIVE TREE ADD" << std::endl;
    std::cout << "----------" << std::endl;

    ints.add(1);
    ints.add(2, 1);
    ints.add(10, 2);
    ints.add(8, 2);
    ints.add(3, 1);
    ints.add(9, 10);
    ints.add(13, 8);
    ints.add(15, 2);
    ints.add(14, 8);

    ints.print(ints.getBase());

    std::cout << std::endl;

    std::cout << "SIZE: " << ints.size() << std::endl;
}

// The tests of LinkedList.cpp
void LINKEDLIST_TESTS()
{
    std::cout << "LINKED LIST TESTS" << std::endl << std::endl;

    LinkedList<int> ints = LinkedList<int>();

    std::cout << "LINKED LIST ADD" << std::endl;
    std::cout << "----------" << std::endl;
    for (int i = 0; i < 10; ++i)
    {
        ints.add(i);
        std::cout << ints[i] << " ";
    }

    std::cout << std::endl << std::endl;

    std::cout << "REMOVED: " << ints.removeAt(1) << std::endl;

    std::cout << std::endl;

    for (int i = 0; i < ints.size(); ++i)
    {
        std::cout << ints[i] << " ";
    }

    std::cout << std::endl << std::endl;

    std::cout << "SIZE: " << ints.size() << std::endl;
}

// The tests of DynamicQueue.cpp
void DQUEUE_TESTS()
{
    std::cout << "DYNAMIC QUEUE TESTS" << std::endl << std::endl;

    DynamicQueue<int> ints;

    std::cout << "DYNAMIC QUEUE ENQUEUE" << std::endl;
    std::cout << "----------" << std::endl;
    for (int i = 0; i < 20; ++i)
    {
        std::cout << ints.enqueue(i) << " ";
    }

    std::cout << std::endl << std::endl;

    std::cout << "SIZE: " << ints.size() << std::endl;
    std::cout << "FRONT: " << ints.front() << std::endl;
    std::cout << "BACK: " << ints.back() << std::endl;

    std::cout << std::endl;

    std::cout << "FULL: " << (ints.full() ? "TRUE" : "FALSE") << std::endl;

    std::cout << std::endl;

    std::cout << "DYNAMIC QUEUE DEQUEUE" << std::endl;
    std::cout << "---------" << std::endl;
    for (int i = 0; i < 18; ++i)
    {
        std::cout << ints.dequeue() << " ";
    }

    std::cout << std::endl << std::endl;

    std::cout << "SIZE: " << ints.size() << std::endl;
    std::cout << "FRONT: " << ints.front() << std::endl;
    std::cout << "BACK: " << ints.back() << std::endl;

    std::cout << std::endl;

    std::cout << "FULL: " << (ints.full() ? "TRUE" : "FALSE") << std::endl;

    std::cout << std::endl;

    std::cout << "DYNAMIC QUEUE ENQUEUE" << std::endl;
    std::cout << "---------" << std::endl;
    for (int i = 1000; i < 1002; ++i)
    {
        std::cout << ints.enqueue(i) << " ";
    }

    std::cout << std::endl << std::endl;

    std::cout << "SIZE: " << ints.size() << std::endl;
    std::cout << "FRONT: " << ints.front() << std::endl;
    std::cout << "BACK: " << ints.back() << std::endl;

    std::cout << std::endl;

    std::cout << "FULL: " << (ints.full() ? "TRUE" : "FALSE") << std::endl;

    std::cout << std::endl;

    std::cout << "DYNAMIC QUEUE DEQUEUE" << std::endl;
    std::cout << "---------" << std::endl;

    int currentSize = ints.size();

    for (int i = 0; i < currentSize; ++i)
    {
        std::cout << ints.dequeue() << " ";
    }

    std::cout << std::endl << std::endl;

    std::cout << "SIZE: " << ints.size() << std::endl;
    std::cout << "FRONT: " << ints.front() << std::endl;
    std::cout << "BACK: " << ints.back() << std::endl;

    std::cout << std::endl;

    std::cout << "FULL: " << (ints.full() ? "TRUE" : "FALSE") << std::endl;
    std::cout << "EMPTY: " << (ints.empty() ? "TRUE" : "FALSE") << std::endl;
}

// The tests of Queue.cpp
void QUEUE_TESTS()
{
    std::cout << "NORMAL QUEUE TESTS" << std::endl << std::endl;

    Queue<int> ints;

    std::cout << "NORMAL QUEUE ENQUEUE" << std::endl;
    std::cout << "----------" << std::endl;
    for (int i = 0; i < 20; ++i)
    {
        std::cout << ints.enqueue(i) << " ";
    }

    std::cout << std::endl << std::endl;

    std::cout << "SIZE: " << ints.size() << std::endl;
    std::cout << "FRONT: " << ints.front() << std::endl;
    std::cout << "BACK: " << ints.back() << std::endl;

    std::cout << std::endl;

    std::cout << "FULL: " << (ints.full() ? "TRUE" : "FALSE") << std::endl;

    std::cout << std::endl;

    std::cout << "NORMAL QUEUE DEQUEUE" << std::endl;
    std::cout << "---------" << std::endl;
    for (int i = 0; i < 18; ++i)
    {
        std::cout << ints.dequeue() << " ";
    }

    std::cout << std::endl << std::endl;

    std::cout << "SIZE: " << ints.size() << std::endl;
    std::cout << "FRONT: " << ints.front() << std::endl;
    std::cout << "BACK: " << ints.back() << std::endl;

    std::cout << std::endl;

    std::cout << "FULL: " << (ints.full() ? "TRUE" : "FALSE") << std::endl;

    std::cout << std::endl;

    std::cout << "NORMAL QUEUE ENQUEUE" << std::endl;
    std::cout << "---------" << std::endl;
    for (int i = 1000; i < 1002; ++i)
    {
        std::cout << ints.enqueue(i) << " ";
    }

    std::cout << std::endl << std::endl;

    std::cout << "SIZE: " << ints.size() << std::endl;
    std::cout << "FRONT: " << ints.front() << std::endl;
    std::cout << "BACK: " << ints.back() << std::endl;

    std::cout << std::endl;

    std::cout << "FULL: " << (ints.full() ? "TRUE" : "FALSE") << std::endl;

    std::cout << std::endl;

    std::cout << "NORMAL QUEUE DEQUEUE" << std::endl;
    std::cout << "---------" << std::endl;

    int currentSize = ints.size();

    for (int i = 0; i < currentSize; ++i)
    {
        std::cout << ints.dequeue() << " ";
    }

    std::cout << std::endl << std::endl;

    std::cout << "SIZE: " << ints.size() << std::endl;
    std::cout << "FRONT: " << ints.front() << std::endl;
    std::cout << "BACK: " << ints.back() << std::endl;

    std::cout << std::endl;

    std::cout << "FULL: " << (ints.full() ? "TRUE" : "FALSE") << std::endl;
    std::cout << "EMPTY: " << (ints.empty() ? "TRUE" : "FALSE") << std::endl;
}

// The tests of DynamicStack.cpp
void DSTACK_TESTS()
{
    std::cout << "DYNAMIC STACK TESTS" << std::endl << std::endl;

    DynamicStack<int> ints;

    std::cout << "DYNAMIC STACK PUSH" << std::endl;
    std::cout << "----------" << std::endl;
    for (int i = 0; i < 20; ++i)
    {
        std::cout << ints.push(i) << " ";
    }

    std::cout << std::endl << std::endl;

    std::cout << "DYNAMIC STACK POP" << std::endl;
    std::cout << "---------" << std::endl;
    for (int i = 0; i < 20; ++i)
    {
        std::cout << ints.pop() << " ";
    }

    std::cout << std::endl << std::endl;

    std::cout << "FULL: " << (ints.full() ? "TRUE" : "FALSE") << std::endl;
    std::cout << "EMPTY: " << (ints.empty() ? "TRUE" : "FALSE") << std::endl;
}

// The tests of Stack.cpp
void STACK_TESTS()
{
    std::cout << "NORMAL STACK TESTS" << std::endl << std::endl;

    Stack<int> ints = Stack<int>();

    std::cout << "NORMAL STACK PUSH" << std::endl;
    std::cout << "----------" << std::endl;
    for (int i = 0; i < 10; ++i)
    {
        std::cout << ints.push(i) << " ";
    }

    std::cout << std::endl << std::endl;

    std::cout << "NORMAL STACK POP" << std::endl;
    std::cout << "---------" << std::endl;
    for (int i = 0; i < 10; ++i)
    {
        std::cout << ints.pop() << " ";
    }

    std::cout << std::endl << std::endl;

    std::cout << "FULL: " << (ints.full() ? "TRUE" : "FALSE") << std::endl;
    std::cout << "EMPTY: " << (ints.empty() ? "TRUE" : "FALSE") << std::endl;
}

int main()
{
    // For more info - see the top of this document.
#ifdef TREE
    DISTINCTTREE_TESTS();
#endif
#ifdef LIST
    LINKEDLIST_TESTS();
#endif
#ifdef QUEUE
    QUEUE_TESTS();
    DQUEUE_TESTS();
#endif
#ifdef STACK
    STACK_TESTS();
    DSTACK_TESTS();
#endif
    return 0;
}
