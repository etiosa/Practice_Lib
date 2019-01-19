//
// Created by Etiosa Obasuyi on 2018-12-06.
//

#include "../Private/DoublyLinkedList.h"
#include<iostream>
/*TODO: create Enum class for error
 * and a logging class
 * */
DoublyLinkedList::DoublyLinkedList():size(0), head(nullptr),tail(nullptr), indexPosition(0) {

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

bool DoublyLinkedList::isIndexVaild(int index)
{
	return index>0&&index<size;
}
std::shared_ptr<Doubly_Node> DoublyLinkedList::createNode(int data) 
{
	std::shared_ptr<Doubly_Node>newNode = std::make_shared<Doubly_Node>(data);
	size++;
	newNode->setupIndex(size-1);
	/*TODO:setup the index*/
	return newNode;
}
// O(1)
void DoublyLinkedList::adjustIndex()
{
	/* adjusting the new created index for the old node index*/
	std::shared_ptr<Doubly_Node> currentNode = head;
	std::shared_ptr<Doubly_Node>nextNode=  currentNode->next; //lol prev is null

	 int currentIndex = currentNode->getIndex();
	 int prevIndex = nextNode->getIndex();

	 //int currentIndextTemp = currentIndex;
	 //int prevIndexTemp = prevIndex;
	 /* swamping: after linkedFirst: 1,0*/
	 currentNode->setupIndex(prevIndex);
	 nextNode->setupIndex(currentIndex);

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
		adjustIndex(); // I am just swamping the value

		head = newNode;
		newNode->prev = nullptr;
		// adjust index after insertion
		//adjustIndex(head); // I am just swamping the value

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

bool DoublyLinkedList::linkedAFter(std::shared_ptr<Doubly_Node>& after, int data)
{
	std::shared_ptr<Doubly_Node>newNode=createNode(data);

	/* Checking if we adding to front of the list*/
	if(after==head)
	{
		linkedFirst(data);
		return true;

	}
	/* if we are adding at the tail*/
	else if(after == tail)
	{
		linkedLast(data);
		return true;
	}
	else
		{
		/*check if the node exist in our list*/
		std::shared_ptr<Doubly_Node>find= findNode(after);

			if(find!= nullptr)
			{
				/*update the newNode pointer */
				newNode->next =after->next;
				after->next->prev= newNode;
				after->next= newNode;
				newNode->prev = after;
				return true;

			}
		}
	return false;
}
bool DoublyLinkedList::linkedBefore(std::shared_ptr<Doubly_Node> & before, int data)
{
		std::shared_ptr<Doubly_Node> newNode= createNode(data);

		if(before==head)
		{
			/* 0 is before 1*/
			newNode->next = before;
			newNode->prev = nullptr;
			before->prev= newNode;
			head= newNode;
			return true;
		}
		else if(before==tail)
		{
			newNode->next = tail;
			tail->prev->next = newNode;
			newNode->prev= tail->prev;
			return true;
		}
		else
			{
			 /* check if the node Exist*/
			 std::shared_ptr<Doubly_Node> find = findNode(before);
			 if(find!= nullptr)
			 {
			 	newNode->next = find;

			 	find->prev->next=  newNode;
				 std::cout<<"find ->getData() is "<<find->getData()<<std::endl;

				 int data = find->prev->next->getData();
			 	newNode->prev = find->prev;
				 std::cout<<"find ->prev->next->getData() is "<<data<<std::endl;
				 std::cout<<"find ->prev->prev->next->getData() is "<<find->prev->prev->next->getData()<<std::endl;

				 return true;
			 }
			 return false;

			}

}
bool DoublyLinkedList::linkAdd(int data, int index)
{
	std::shared_ptr<Doubly_Node>newNode= createNode(data);
	if(index==0)
	{
		linkedFirst(data);
		return true;
	}
	else if(index==tail->getIndex())
	{
		linkedLast(data);
		return true;
	}
	else
		{ /*find the node with that index */
			std::shared_ptr<Doubly_Node>findNode= findNodeIndex(index);
			if(findNode!= nullptr)
			{
				//TODO:do something with
			}
		}
	return false;
}
std::shared_ptr<Doubly_Node> DoublyLinkedList::findNodeIndex(int index)
{
	 /* is the index valid*/
	 if(isIndexVaild(index))
	 {

	 }
	 //else
	 return nullptr;
}
//0(n)
std::shared_ptr<Doubly_Node> DoublyLinkedList::findNode(std::shared_ptr<Doubly_Node>& find )
{
	std::shared_ptr<Doubly_Node>currNode= head;
	while(currNode!= nullptr)
	{
		if(find==currNode)
		{
			return currNode;
		}
		currNode= currNode->next;
	}
	return nullptr;
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


void DoublyLinkedList::addBefore(std::shared_ptr<Doubly_Node>& before, int data)
{
	linkedBefore(before, data);
}

void DoublyLinkedList::addAfter(std::shared_ptr<Doubly_Node> & after, int data)
{
	linkedAFter(after, data);
}


/* test index */
void DoublyLinkedList::printIndex()
{
	std::shared_ptr<Doubly_Node>current= head;
	while(current!= nullptr)
	{
		/* cout is */
		std::cout<<" "<<current->getIndex();
		current=current->next;
	}
}