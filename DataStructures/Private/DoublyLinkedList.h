//
// Created by Etiosa Obasuyi on 2018-12-06.
//

#ifndef PRACTICE_LIB_DOUBLYLINKEDLIST_H
#define PRACTICE_LIB_DOUBLYLINKEDLIST_H
/*TODO: change the raw pointer to smart pointer*/
#include<memory>
#include "Doubly_Node.h"

class DoublyLinkedList {
private:
    int size;
   // Doubly_Node* head;
    //Doubly_Node* tail;
    std::shared_ptr<Doubly_Node>head;
    std::shared_ptr<Doubly_Node> tail;
    bool linkedLast();
    bool linkedFirst();

public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    int getSize()const{return size;}
    void pushFront();
    void pushBack();




    bool isEmpty();
    bool addBefore();
    bool addAfter();
    bool deleteNode();
    bool find(std::string);/*TODO: change the paramter to a template */
    bool erase(std::string data);
    bool deleteList();
    bool popFront();
    bool popBack();


};


#endif //PRACTICE_LIB_DOUBLYLINKEDLIST_H
