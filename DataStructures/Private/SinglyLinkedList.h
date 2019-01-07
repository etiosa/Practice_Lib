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

   // bool checkIndex(int);
    bool isIndexValid(int);

	void adjustIndexAfterHeadRemoved();
    void adjustIndex();

    //Node* head;
    /* shared_ptr just return a pointer for us: take care of resource */
    std::shared_ptr<Node> head;
    std::shared_ptr<Node> tail;
    //TODO: Change the argument for LinkedFirst
	/*TDOD:
*/
    bool linkedFirst(int);
    bool linkedLast(int);
	

	bool linkedFirst(int, int);
	bool linkedLast(int, int);
	bool linkedAfter(int);
	bool linkedBefore(int);

	std::shared_ptr<Node>createNode(int);
	
	//pass node reference; since we are adding before and after the required Node
	bool linkedAfter(std::shared_ptr<Node>&, int);
	void createNode(std::shared_ptr<Node> &newNode, int &data);
	bool linkedBefore(std::shared_ptr<Node>&, int);
	
	/*Adding before and after a node with given index*/
	bool linkedAfter(int, int);
	bool linkedBefore(int, int);
	/*return the node with the given index: return a reference of the node*/
	std::shared_ptr<Node> findNodeIndex(int);

	void linkAdd(int, int);

	/*update the index after an element is added based on index*/
	void updateLinkedAddIndex(std::shared_ptr<Node>);


public:
    SinglyLinkedList();
    ~SinglyLinkedList();

    int getSize() const {return size;}

	/*TODO:change the return type to reference*/
    std::shared_ptr<Node>popBack();
    std::shared_ptr<Node>popFront();
    std::shared_ptr<Node>const& returnTail () const { return tail;}
    std::shared_ptr<Node> const& returnHead() const {return head;}
    std::shared_ptr<Node>& ascendSort();
    //Node* ascendSort();
    std::shared_ptr<Node>& descendSort();
    // Node* descendSort();

    /*TODO: change the argument for pushFront and pushBack to  Template */
    void pushFront(int);
    void pushBack(int);
    /* Add based on the index*/
    /* overloading*/
   // void pushFront(int,int);
    //void pushBack(int, int);
    void printInfo();
	void printIndex();//Testing

    bool isEmpty();
    void addAfter(std::shared_ptr<Node>&,int);
    void addBefore(std::shared_ptr<Node>&, int);
	bool addAfter(int, int);//index
	bool addBefore(int, int);//index

    bool deleteList();
    bool erase(std::string);
    bool find(std::string);
	/*return node base on the index*/
	std::shared_ptr<Node> find(int);
    bool deleteNode();
	/*Add element base on the index*/
	void add(int, int);


	void reverse();





};


#endif //PRACTICE_LIB_SINGLYLINKEDLIST_H
