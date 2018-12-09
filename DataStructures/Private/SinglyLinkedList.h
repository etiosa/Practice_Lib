//
// Created by Etiosa Obasuyi on 2018-12-06.
//

#ifndef PRACTICE_LIB_SINGLYLINKEDLIST_H
#define PRACTICE_LIB_SINGLYLINKEDLIST_H

/* TODO: change the raw pointer to smart_pointer: shared pointer*/
#include"Node.h"
class SinglyLinkedList {
private:
    int size;
    Node* head;

    bool linkedFirst();
    bool linkedLast();

public:
    int getSize() const {return size;}
    /*  Check if the list is empty*/
    bool isEmpty();

    SinglyLinkedList();
    ~SinglyLinkedList();
    void pushFront();
    void pushBack();






};


#endif //PRACTICE_LIB_SINGLYLINKEDLIST_H
