cmake_minimum_required(VERSION 3.20)
project(Structures)

set(CMAKE_CXX_STANDARD 14)

add_executable(Structures main.cpp Common/SingularNode.h Common/MultiNode.h Stack/Stack.h Stack/DynamicStack.h Queue/Queue.h Queue/DynamicQueue.h List/LinkedList.h Tree/DistinctTree.h)
