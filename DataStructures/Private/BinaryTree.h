//
// Created by Etiosa Obasuyi on 2018-12-06.
//

#ifndef PRACTICE_LIB_BINARY_TREE_H
#define PRACTICE_LIB_BINARY_TREE_H
#include<memory>
#include "BSTNode.h"
#include"SinglyLinkedList.h"
/*Binary Definition: Must have two children */

class BinaryTree {
public:
    BinaryTree();
    ~BinaryTree();


    bool isEmpty();
    bool addToBST(int);
    int getSize() const {return size;}
private:
    std::shared_ptr<BSTNode>transfomrToBST(SinglyLinkedList&);
    int size;
    std::shared_ptr<BSTNode>createNode(int);

    /*TODO:change the data to array of int*/
    bool checkIfDataIsBST(SinglyLinkedList&);
   std::shared_ptr<BSTNode> root;


};


#endif //PRACTICE_LIB_BINARY_TREE_H
