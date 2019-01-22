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
    int indexPosition;
    /* Change the argument to template */
    bool linkedLast(int);
    bool linkedFirst(int);
    /* add base of the index*/
    bool linkedAFter(std::shared_ptr<Doubly_Node>&, int);
    bool linkedBefore(std::shared_ptr<Doubly_Node>&,int);
	bool linkedBefore(int, int);// add before using index
	bool linkedAfter(int, int);// add after using index
    /* add node base on the index*/
    bool linkAdd (int,int);

	std::shared_ptr<Doubly_Node> createNode(int);


	std::shared_ptr<Doubly_Node> findNode(std::shared_ptr<Doubly_Node>&);
	bool isIndexVaild(int);
	std::shared_ptr<Doubly_Node>findNodeIndex(int index);
	/*adjust index after new node is added to the front*/
	void adjustIndex();
	/*adjust the  index after the head of the node is removed*/
	void adjustIndexAfterHeadRemoved();

	std::shared_ptr<Doubly_Node>removeFront();
	std::shared_ptr<Doubly_Node>removeBack();
	/**/
	void updateIndexAfterLinkedLBefore(std::shared_ptr<Doubly_Node>&);
public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    int getSize()const{return size;}
    void pushFront(int);
    void pushBack(int );
	void reverse();
	void printInfo();
	void addAfter(std::shared_ptr<Doubly_Node>&, int);
	void addBefore(std::shared_ptr<Doubly_Node>&, int);
	void addBefore(int, int);
    std::shared_ptr<Doubly_Node> getHead() const{ return head;}
    std::shared_ptr<Doubly_Node> getTail() const{ return tail;}



    bool isEmpty();
    bool addBefore();
    bool addAfter();
    bool deleteNode();
    bool find(int);/*TODO: change the paramter to a template */
    bool erase(std::string data);
    bool deleteList();
    std::shared_ptr<Doubly_Node> popFront();
    std::shared_ptr<Doubly_Node> popBack();

	void printResver();

	void printIndex();

};

#endif //PRACTICE_LIB_DOUBLYLINKEDLIST_H
