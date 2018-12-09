//
// Created by Etiosa Obasuyi on 2018-12-06.
//

#ifndef PRACTICE_LIB_DOUBLYLINKEDLIST_H
#define PRACTICE_LIB_DOUBLYLINKEDLIST_H
/*TODO: change the raw pointer to smart pointer*/
#include "Doubly_Node.h"

class DoublyLinkedList {
private:
    int size;
    Doubly_Node* head;
    Doubly_Node* tail;
    bool linkedLast();
    bool linkedFirst();

public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    int getSize()const{return size;}
    bool isEmpty();
    void pushFront();
    void pushBack();


};


#endif //PRACTICE_LIB_DOUBLYLINKEDLIST_H
