cmake_minimum_required(VERSION 3.13)
project(DataStructures)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(Private)
include_directories(Public)

add_executable(DataStructures
    Private/ArrayList.h
    Private/AVL_Tree.h
    Private/B_Tree.h
        Private/BinaryTree.h
    Private/DisJoint_Set.h
    Private/Doubly_Node.h
    Private/DoublyLinkedList.h
    Private/Graph.h
    Private/Hash_Table.h
    Private/Heaps.h
    Private/Node.h
    Private/Queue_Imp.h
    Private/Red_Black_Tree.h
    Private/SinglyLinkedList.h
    Private/Stacks_Imp.h
    Private/Tries.h
    Private/Vector.h
    Public/ArrayList.cpp
    Public/AVL_Tree.cpp
    Public/B_Tree.cpp
        Public/BinaryTree.cpp
    Public/DisJoint_Set.cpp
    Public/Doubly_Node.cpp
    Public/DoublyLinkedList.cpp
    Public/Graph.cpp
    Public/Hash_Table.cpp
    Public/Heaps.cpp
    Public/Node.cpp
    Public/Queue_Imp.cpp
    Public/Red_Black_Tree.cpp
    Public/SinglyLinkedList.cpp
    Public/Stacks_Imp.cpp
    Public/Tries.cpp
    Public/Vector.cpp
    GraphNode.cpp
    GraphNode.h)
