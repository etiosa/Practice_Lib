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
std::shared_ptr<Doubly_Node> DoublyLinkedList::removeFront()
{
	/*TODO:  throw execption if the list is empty*/
	std::shared_ptr<Doubly_Node> result = nullptr;
	/*if there's just one element in the list*/
	if (size == 1)
	{
		result = head;
		size--;
		head = tail = nullptr;
		return result;
	}
	else
	{
		size--;
		result = head;
		/* adjust the node*/
		head = head->next;
		/*adjust the index*/
		adjustIndexAfterHeadRemoved();
	}
	return result;
}
std::shared_ptr<Doubly_Node> DoublyLinkedList::removeBack()
{
	/*TODO: throw execption when the list is empty*/
	std::shared_ptr<Doubly_Node> result = nullptr;
	/*if there's just one element in the list*/
	if (size == 1)
	{
		size--;
		result = head;
		head = tail = nullptr;
		return result;
	}
	else
	{
		size--;
		/* need to find the prev node*/
		std::shared_ptr<Doubly_Node> prevNode = tail->prev;
		result = tail;
		tail = prevNode;
		prevNode->next = nullptr;
		return result;
	}
	return result;
}
std::shared_ptr<Doubly_Node> DoublyLinkedList::popFront()
{
	std::shared_ptr<Doubly_Node> result = removeFront();
	return result;
}

std::shared_ptr<Doubly_Node>DoublyLinkedList::popBack()
{
	std::shared_ptr<Doubly_Node> result = removeBack();
	return result;
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
		current = current->next;
			 
    }
    return false;
}

bool DoublyLinkedList::isIndexVaild(int index)
{
	return index>=0&&index<size;
}
std::shared_ptr<Doubly_Node> DoublyLinkedList::createNode(int data) 
{
	std::shared_ptr<Doubly_Node>newNode = std::make_shared<Doubly_Node>(data);
	size++;
	newNode->setupIndex(size-1);
	/*TODO:setup the index*/
	return newNode;
}
//O(N)
/*TODO: optimize this solution*/
void DoublyLinkedList::adjustIndexAfterHeadRemoved() 
{
	
	std::shared_ptr<Doubly_Node>currNode = head;
	while (currNode!=nullptr)
	{
		currNode->setupIndex(currNode->getIndex() - 1);
		currNode = currNode->next;
	}
	return;
}
// O(n)
/*TODO: optimize this solution*/
void DoublyLinkedList::adjustIndex()
{
	/* adjusting the new created index for the old node index*/
	std::shared_ptr<Doubly_Node> currentNode = head;
	std::shared_ptr<Doubly_Node>nextNode=  nullptr; 

	 int prevtIndex;
	 int nextIndex;
	 while (currentNode->next!=nullptr)
	 {
		 prevtIndex = currentNode->getIndex();
		 nextNode = currentNode->next;
		 nextIndex = nextNode->getIndex();
		 /*swamp*/
		 currentNode->setupIndex(nextIndex);
		 nextNode->setupIndex(prevtIndex);
		 currentNode = nextNode;
	 }
	 return;
	
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
		// adjust index after insertion
		adjustIndex();
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
		return true; 
	}
	else 
	{
		tail->next = newNode;
		newNode->next = nullptr;
		newNode->prev = tail;
		tail = newNode;
		return true;


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
				// std::cout<<"find ->getData() is "<<find->getData()<<std::endl;

				 int data = find->prev->next->getData();
			 	newNode->prev = find->prev;
				// std::cout<<"find ->prev->next->getData() is "<<data<<std::endl;
				 //std::cout<<"find ->prev->prev->next->getData() is "<<find->prev->prev->next->getData()<<std::endl;

				 return true;
			 }
			 return false;

			}

}
/*TODO: Move createNode from LinkedBefore, LinkedAfter*/
bool DoublyLinkedList::linkedBefore(int data, int index) 
{
	//std::shared_ptr<Doubly_Node>newNode = createNode(data);
	std::shared_ptr < Doubly_Node> find = findNodeIndex(index);
	if (find != nullptr) 
	{
		if (find->getIndex() == 0) 
		{
			linkedFirst(data);
			return true;
		} 
		else if (find->getIndex() == tail->getIndex()) 
		{
			linkedLast(data);
			return true;      
		}
		else
		{
			std::shared_ptr<Doubly_Node>newNode = createNode(data);

			/*O(N)*/
			std::shared_ptr<Doubly_Node> currNode = head;
			while (currNode!=nullptr)
			{
				if (find == currNode) 
				{
					//link it 
					/*   0,1,2(find)
						newNode
					*/
					// 0 ,1 , newNode, find(index =2)

					//0,1,2,3
					// 0, 1, newNode(2),3,4
					//give the index to the newCreated Node,
					//then increment all the index after the node by one
					newNode->next = find;
					find->prev->next = newNode;
					newNode->prev = find;
					newNode->setupIndex(find->getIndex());
					/*adjust the index*/
					updateIndexAfterLinkedLBefore(find);
						
					return true;
				}
				currNode = currNode->next;
			}
		}
	}

	return false;
}	

void DoublyLinkedList::updateIndexAfterLinkedLBefore(std::shared_ptr<Doubly_Node>& updateindex) 
{
	while (updateindex!=nullptr)
	{
		updateindex->setupIndex(updateindex->getIndex() + 1);
		updateindex = updateindex->next;
	}
}
bool DoublyLinkedList::linkedAfter(int data, int index) 
{
	return false;
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
	std::shared_ptr<Doubly_Node>findNode = nullptr;
	std::shared_ptr<Doubly_Node>currNode = head;
	 /* is the index valid*/
	 if(isIndexVaild(index))
	 {
		 while (currNode!=nullptr)
		 {
			 if (currNode->getIndex() == index) 
			 {
				 findNode = currNode;
				 return findNode;
			 }
			 currNode = currNode->next;
		 }
		
	 }
	 //else
	 return findNode;
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
void DoublyLinkedList::addBefore(int data, int index) 
{
	linkedBefore(data, index);
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