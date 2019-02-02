//
// Created by Etiosa Obasuyi on 2018-12-06.
//

#include "../Private/BinaryTree.h"
#include<iostream>
BinaryTree::BinaryTree(): root(nullptr){}

BinaryTree::~BinaryTree() {}

bool BinaryTree::isEmpty()
{
    if(root== nullptr) {
        return false;
    }
    return true;
}
bool BinaryTree::addToBST(int data)
{
    /*dyanmic create node */
    std::shared_ptr<BSTNode>newNode = createNode(data);
    if(!isEmpty())
    {
        /* then just root..no right an left child*/
        root=newNode;
        std::cout<<"just root";
    }

    return false;
}
std::shared_ptr<BSTNode> BinaryTree::createNode(int data)
{
    size++;
    std::shared_ptr<BSTNode> newNode = std::make_shared<BSTNode>(data);
    return newNode;
}

std::shared_ptr<BSTNode> BinaryTree::transfomrToBST(SinglyLinkedList &) {
    /*transform the node */


    return std::shared_ptr<BSTNode>();
}

