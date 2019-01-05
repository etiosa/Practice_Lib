//
// Created by Etiosa Obasuyi on 2018-12-06.
//

#ifndef PRACTICE_LIB_SINGLYLINKEDLIST_H
#define PRACTICE_LIB_SINGLYLINKEDLIST_H

/* TODO: change the raw pointer to smart_pointer: shared pointer*/
#include<memory>
#include"Node.h"
class SinglyLinkedList {
private:
    int size;
    int indexPostion;

    bool checkIndex(int);
    bool isIndexValid(int);

    void registarIndex(int);
    void adjustIndex();

    //Node* head;
    /* shared_ptr just return a pointer for us: take care of resource */
    std::shared_ptr<Node> head;
    std::shared_ptr<Node> tail;
    //TODO: Change the argument for LinkedFirst
    bool linkedFirst(int);
    bool linkedLast(int);



public:
    SinglyLinkedList();
    ~SinglyLinkedList();

    int getSize() const {return size;}


    std::shared_ptr<Node>popBack();
    std::shared_ptr<Node>popFront();
    std::shared_ptr<Node> returnTail () const { return tail;}
    std::shared_ptr<Node> returnHead() const {return head;}
    std::shared_ptr<Node> ascendSort();
    //Node* ascendSort();
    std::shared_ptr<Node> descendSort();
    // Node* descendSort();

    /*TODO: change the argument for pushFront and pushBack */
    void pushFront(int);
    void pushBack(int);
    /* Add based on the index*/
    /* overloading*/
    void pushFront(int,int);
    void pushBack(int, int);
    void printInfo();


    bool isEmpty();
    bool addAfter();
    bool addBefore();
    bool deleteList();
    bool erase(std::string);
    bool find(std::string);
    bool deleteNode();







};


#endif //PRACTICE_LIB_SINGLYLINKEDLIST_H
