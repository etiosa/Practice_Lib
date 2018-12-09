//
// Created by Etiosa Obasuyi on 2018-12-06.
//

#ifndef PRACTICE_LIB_DOUBLY_NODE_H
#define PRACTICE_LIB_DOUBLY_NODE_H

/* TODO: Change raw pointer to smart pointer*/
class Doubly_Node {
private:
    Doubly_Node* next;
    Doubly_Node* prev;


public:
    Doubly_Node();
    ~Doubly_Node();
};


#endif //PRACTICE_LIB_DOUBLY_NODE_H
