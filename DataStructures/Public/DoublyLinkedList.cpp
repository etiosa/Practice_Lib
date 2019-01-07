//
// Created by Etiosa Obasuyi on 2018-12-06.
//

#include "../Private/DoublyLinkedList.h"
#include<iostream>
DoublyLinkedList::DoublyLinkedList():size(0), head(nullptr),tail(nullptr) {

}
DoublyLinkedList::~DoublyLinkedList() 
{}
bool DoublyLinkedList::isEmpty()
{
    return head!= nullptr;
}

bool  DoublyLinkedList::deleteList()
{
    if(!isEmpty())
    {
        head=tail= nullptr;
        return true;
    }
    return false;
}
/* Worse case: o(n)*/
bool DoublyLinkedList::find(int findData)
{
    std::shared_ptr<Doubly_Node>current= head;
    while(current!= nullptr)
    {
        if(current->getData() == findData)
        {
            return true;
            //set<int> seti;
        }
    }
    return false;

}
std::shared_ptr<Doubly_Node> DoublyLinkedList::createNode(int data) 
{
	std::shared_ptr<Doubly_Node>newNode = std::make_shared<Doubly_Node>(data);
	size++;
	/*TODO:setup the index*/
	return newNode;
}
bool DoublyLinkedList::linkedFirst(int data) 
{
	std::shared_ptr<Doubly_Node>newNode = createNode(data);
	/*check if there's an element in the list*/
	if (head == nullptr) 
	{
		head = tail = newNode;
	}
	else 
	{
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
		newNode->prev = nullptr;
		return true;

	}
	return false;
}
/*TODO change data to Template data*/
bool DoublyLinkedList::linkedLast(int data) 
{
	std::shared_ptr<Doubly_Node>newNode = createNode(data);
	if(tail==nullptr)
	{
		head = tail = newNode;
	}
	else 
	{
		tail->next = newNode;
		newNode->next = nullptr;
		newNode->prev = tail;
		tail = newNode;


	}
	return false;
}

void DoublyLinkedList::pushFront(int data)
{
	linkedFirst(data);
}

void DoublyLinkedList::pushBack(int data) 
{
	linkedLast(data);
}

void DoublyLinkedList::reverse() 
{

/*for each iteration change the pointer direction*/
	std::shared_ptr<Doubly_Node>currNode = head;
	std::shared_ptr<Doubly_Node>TempprevNode = nullptr;

	while (currNode!=nullptr)
	{
		TempprevNode = currNode->prev;
		//swamp prev for next
		currNode->prev = currNode->next; //first because the head prev is null..cause null execption
		//swamp next for prev
		currNode->next = TempprevNode;; //execption here
		/*if (currNode == nullptr) 
		{
			tail = currNode;
		}*/

		currNode = currNode->prev;
	}
	//tail = head;
	head = TempprevNode->prev;

}

void DoublyLinkedList::printInfo() 
{
	std::shared_ptr<Doubly_Node>currNode = head;

	while (currNode!=nullptr)
	{
		std::cout << " " << currNode->getData();
		currNode = currNode->next;
	}
	std::cout<<std::endl;
}


