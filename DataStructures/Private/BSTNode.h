//
// Created by Etiosa Obasuyi on 2019-01-30.
//
//
#ifndef PRACTICE_LIB_BSTNODE_H
#define PRACTICE_LIB_BSTNODE_H

#include <memory>

class BSTNode {

private:
    int data;
public:
   std::shared_ptr<BSTNode> top; //
   std::shared_ptr<BSTNode>leftChild;
   std::shared_ptr<BSTNode>rightChild;

   BSTNode(int);
   ~BSTNode();
};


#endif //PRACTICE_LIB_BSTNODE_H
