//
// Created by Etiosa Obasuyi on 2018-12-06.
//
#include<iostream>
#include "../Private/SinglyLinkedList.h"
SinglyLinkedList::SinglyLinkedList():head(nullptr), size(0),indexPostion(0) {

}
SinglyLinkedList::~SinglyLinkedList() {}


void SinglyLinkedList::reverse() 
{
   /*basically I want change the pointer direction
   since there's no prev pointer we need to store it 

   in each iteration we need to change the pointer direction one at a time
   since the head will not be the tail..next pointer reference is null
   */
	std::shared_ptr<Node>currNode = head;
	std::shared_ptr<Node>prevNode = nullptr;
	std::shared_ptr<Node>nextNode = nullptr; //a way to save the next node in the list so we don't lost it
	std::shared_ptr<Node>saveTail = tail;
	while (currNode!=nullptr)
	{
		nextNode = currNode->next; 		
		currNode->next = prevNode;//swaping
		if (currNode->next == nullptr) 
		{
			tail = currNode;
		}
		prevNode = currNode; //save the prev Node keep track of prev node
		currNode = nextNode;

	}
	head = prevNode;
	//tail = prevNode->next;
	//tail = saveTail;
}
bool SinglyLinkedList::isEmpty() {
	return head != nullptr;
}
bool SinglyLinkedList::deleteList() 
{
	/*iterate through the list and delete all the element */
	if (head == nullptr) 
	{
		std::cout << "CAN'T DELETE FROM EMPTY LIST" << std::endl;
		return false;
	}
	else 
	{
		std::shared_ptr<Node>currNode = head;
		std::shared_ptr<Node>nextNode = nullptr;
		
		while (currNode->next != nullptr)
		{
			nextNode = currNode->next;
			currNode = nullptr;
			currNode = nextNode;
			size--;

		}
		head = nullptr;
	}

	return true;
}

void SinglyLinkedList::printInfo()
{
	
    std::shared_ptr<Node> currNode= head;
	std::cout<<"print info  head "<<currNode->getData()<<std::endl;
	while(currNode!= nullptr)
    {
        std::cout<<" "<<currNode->getData();
        currNode=currNode->next;
    }
	std::cout << std::endl;
}

void SinglyLinkedList::printIndex()
{
	std::shared_ptr<Node> currNode = head;
	while (currNode != nullptr)
	{
		std::cout << " " << currNode->getIndex();
		currNode = currNode->next;
	}
	std::cout << std::endl;
}

bool SinglyLinkedList::linkedFirst(int data)
{
    std::shared_ptr<Node> newNode= std::make_shared<Node>(data);
    size++;
    newNode->setUpIndex(size-1);

    if(head == nullptr)
    {
        head = tail = newNode;

     return true;
    }
    /* if the list is not empty*/
      else
          {
              newNode->next= head;
              head= newNode;
              adjustIndex();//adjust the indeices after insertion of new elements

          }
      return true;

}
void SinglyLinkedList::adjustIndexAfterHeadRemoved()
{
	std::shared_ptr<Node> currNode = head;
	while (currNode!=nullptr)
	{
		currNode->setUpIndex(currNode->getIndex() - 1);
		currNode = currNode->next;
	}
	return;
}
void SinglyLinkedList::adjustIndex()
{
    std::shared_ptr<Node> currNode= head;
    std::shared_ptr<Node>nextNode= nullptr;

    int prevIndex= currNode->getIndex();
    int nextIndex;

    while(currNode->next!= nullptr)
    {
        nextNode= currNode->next;
        nextIndex=nextNode->getIndex();
        currNode->setUpIndex(nextIndex); //SWAmp the old index
        nextNode->setUpIndex(prevIndex); //swamp the new node(index)
        currNode=nextNode;
    }
}

/*TODO: move setup index and size to createNode method*/
bool SinglyLinkedList::linkedLast(int data)
{
    std::shared_ptr<Node> newNode= std::make_shared<Node>(data);
    size++;
    newNode->setUpIndex(size-1);


    if(head == nullptr)
    {
        head=tail=newNode;
    }
    else
        /* the list is not empty */
        {
            tail->next= newNode;

            /*update the tail node to the newnode */
            tail= newNode;
        }
    return true;
}

/*const (const T& data)- > enable to pass literals values into the argument
 * example 5*/
void SinglyLinkedList::pushFront(int data)
{
    linkedFirst(data);
}


void SinglyLinkedList::pushBack(int data)
{
    linkedLast(data);
}
void SinglyLinkedList::addBefore(std::shared_ptr<Node>& before, int data) 
{

	linkedBefore(before, data);
}
/*void SinglyLinkedList::pushBack(int data, int index)
{
	/*check if the index is valid*/
	/*if (isIndexValid(index)) 
	{
		std::cout << "index is valid" << std::endl;

	}
	else 
	{
		std::cout << "index is invalid" << std::endl;
	}
}*/
//c
/*
Write a function that takes two arguments. The first node from a singly 
linked list as the first argument and any node in the list as a second argument.  
The function should delete the second argument (node) from the list.


 */
/* 

Write a function that, when provided the first node of a singly linked list, 
will sort the list by its values from smallest to largest.
 Do not use any built-in language sorting methods (e.g. sort in ruby)

Your answer will be judged on both readability and its performance in the worst-case scenario in Big O time.


*/

std::shared_ptr<Node> SinglyLinkedList::descendSort(std::shared_ptr<Node>&root){
     auto currentNode = head;
	 std::shared_ptr<Node> prevNode =nullptr;
	 std::shared_ptr<Node>nextNode = nullptr;
	 std::shared_ptr<Node>sortedList=nullptr
;
	 if(root==nullptr){
		 return nullptr;
	 }
	 if (root->next ==nullptr){
		 return root;
	 }
	 
	 while(currentNode !=nullptr){
		 nextNode = currentNode->next;
		 std::cout<<"current node value "<<currentNode->getData()<<std::endl;
		std::cout<<" next node value "<<nextNode->getData()<<std::endl;

		 if(currentNode->getData()>= nextNode->getData()){
			 std::cout<<"swamp current with next "<<std::endl;
			 //current Node is larger than next
			 //10 ->1
			 //1->10
			sortedList=nextNode;
			//sortedList->next= currentNode;
			std::cout<<"sorted list datat  "<<sortedList->getData()<<std::endl;
		 }
		currentNode=nextNode;
		//std::cout<<"sno wamp current with next "<<std::endl;


	 }
	 return sortedList;
  


	 //10->1->4->7->null
	 //1. currentNode 10
	 //nextNode==1
	 //compare the currentNode and nextNode data
	 // if(current.data <= nextNode)
	 //we can swamp the nextNode to the next Node
	 //nextNode ->currentNode(1->10)


	return nullptr;
}

int SinglyLinkedList::deleteNode(std::shared_ptr<Node>& root, std::shared_ptr<Node>& searchNode){

	  //check if the node is null
	 std::shared_ptr<Node> prevNode = nullptr;
	 auto currentNode = root;
	  if(root == nullptr){
		
		std::cout << "root is null" << std::endl;

		  return -1;
	  }
	  if(searchNode == nullptr){
		  return -1;
	  }
	  //if it's first node
	  if( head->getData() == searchNode->getData()){

		  prevNode = head;
		  head=nullptr;
		  head = prevNode->next;
		  
          std::cout<<"head and search same data"<<std::endl;
		  return 1;
	  }
	 

	 // loop through the listprint
	
    //check if the node is in the head or tail --> o(1)

	 while(currentNode!=nullptr){

			 if(currentNode->getData()== searchNode->getData()){
				 //if there's a match

				 //12 ->23 -> 24
				 //is 23
				 //prev is 12
				 //current is 23
				 //prev next point to current-> next
				 std::cout<<"search node data "<< searchNode->getData()<<std::endl;
				 prevNode->next = currentNode->next;
				 //head= prevNode;
				 return 1;

				 

			 }

			 
			 else{
				 prevNode = currentNode;
				 currentNode=currentNode->next;

			 }


	 }

	
}



std::shared_ptr<Node>  SinglyLinkedList::find(int index)
{
	 std::shared_ptr<Node>find = findNodeIndex(index);
		/*check if the find is not null*/
	 if (find != nullptr) 
	 {
		 return find;
	 }
	 return nullptr;
}
/*  */
bool SinglyLinkedList::isIndexValid(int indexValid)
{
    return indexValid>=0 && indexValid< size;
}
/*worst case: O(n)*/
std::shared_ptr<Node> SinglyLinkedList::findNodeIndex(int indexFind) 
{
	std::shared_ptr<Node> currNode = head;
		/*check if the index the exist*/
	if (isIndexValid(indexFind)) 
	{
		while (currNode != nullptr)
		{
			if (indexFind == currNode->getIndex())
			{
				std::cout << "find the index" << std::endl;
				return currNode;
			}
			currNode = currNode->next;
		}
	}
	return nullptr;
	
}
//0(1)
std::shared_ptr<Node> SinglyLinkedList::popBack()
{
	std::shared_ptr<Node> result = nullptr;

	/*if there's just one element in the list*/
	if (size==1) 
	{
		result = head;
		head = tail = nullptr;
		size--;
		return result;
	}
	/*check if there's a list*/
	if (head!=nullptr) 
	{
		/*need to find the prev node before we need tail */
		std::shared_ptr<Node>currNode = head;
		std::shared_ptr<Node> prevNode = nullptr;
		size--;
		while (currNode->next!=nullptr)
		{
			prevNode = currNode;
			currNode = currNode->next;
		}
		tail = tail->next;
		prevNode->next = nullptr;
		tail = prevNode;
		/*std::shared_ptr<Node> saved = tail;
		tail = tail->next;
		size--;*/
		return result;
	}
	return result;
}
//0(1)
std::shared_ptr<Node> SinglyLinkedList::popFront() 
{
	std::shared_ptr<Node>result = head;
	if (head != nullptr) 
	{
		head = head->next;
		adjustIndexAfterHeadRemoved();
		size--;
		return result;
	}
	return result;

}
bool SinglyLinkedList::linkedFirst(int data, int index) 
{
	if (isIndexValid(index)) 
	{
		linkedFirst(data);
		return true;
	}
	else
	{
		return false;
	}
}

bool SinglyLinkedList::linkedLast(int data, int index) 
{
	if (isIndexValid(index)) 
	{
		linkedLast(data);
	}
	return false;
}
void SinglyLinkedList::addAfter(std::shared_ptr<Node>& after,int data) 
{
	linkedAfter(after, data);
}/*TODO: Ajust The index and size*/
bool SinglyLinkedList::linkedAfter(std::shared_ptr<Node>& after, int data) 
{
	std::shared_ptr<Node>newNode = createNode(data);
	std::shared_ptr<Node> currNode = head;
	std::shared_ptr<Node>prevNode = nullptr;
	while (currNode!=nullptr)
	{
		if (after == currNode) //if we are add the head
		{
			
			newNode->next = after->next;
			after->next = newNode;
			return true;
		}
		/*adding after the tail*/
		else if (after == tail) 
		{
			after->next = newNode;
			tail = newNode;
			return true;
		}
		else 
		{
			/*find the node*/
			while (currNode != nullptr) 
			{
				if (currNode == after) 
				{
					newNode->next = prevNode->next;
					prevNode->next = newNode;
					return true;
				}
				prevNode = currNode;
				//change the preNode before next
				currNode = currNode->next;

			}
		}
	}

	return false;
}

std::shared_ptr<Node> SinglyLinkedList::createNode(int data)
{
	
	std::shared_ptr<Node>newNode = std::make_shared<Node>(data);
	return newNode;
}

bool SinglyLinkedList::linkedAfter(int data) 
{
	return false;
}

bool SinglyLinkedList::linkedBefore(std::shared_ptr<Node>& before, int data) 
{
	std::shared_ptr<Node>newNode = createNode(data);
	std::shared_ptr<Node>preNode = nullptr;
	std::shared_ptr<Node>currNode = head;
	if (before == head) 
	{
		linkedFirst(data);
		return true;
	}
	else
	{
		while (currNode!=nullptr)
		{
			if (before == currNode) 
			{
				newNode->next = before->next;
				//before = newNode;
				preNode = newNode;
				return true;
			}
			preNode = currNode;
			currNode = currNode->next;
		}
	}

	return false;

}

bool SinglyLinkedList::linkedAfter(int data, int index) 
{
	if (isIndexValid(index)) 
	{
		/*find the node with thei given index*/
		std::shared_ptr<Node> findNode = findNodeIndex(index);
	}
	return false;
}

bool SinglyLinkedList::linkedBefore(int data, int index) 
{
	if (isIndexValid(index)) 
	{
		/*find the node with the given index*/
		std::shared_ptr<Node> findNode = findNodeIndex(index);
	}
	return false;
}


void SinglyLinkedList::add(int data, int index)
{
	if (isIndexValid(index)) 
	{
		if (index == 0) 
		{
			linkedFirst(data);
			return;
		}
		else if (index == tail->getIndex()) 
		{	
			linkedLast(data);
			return;
		}
		linkAdd(data, index);
		return;
	}

}
void SinglyLinkedList::linkAdd(int data, int index) 
{
	std::shared_ptr<Node> findNode=findNodeIndex(index);

	/*get that node of that index
	then update
	*/
	std::shared_ptr<Node>newNode = nullptr;
	std::shared_ptr<Node>currNode = head;
	std::shared_ptr<Node> prevNode = nullptr;
	while (currNode !=nullptr)
	{
 
		if (findNode == currNode) 
		{
			size++;
			newNode = std::make_shared<Node>(data);
			newNode->setUpIndex(findNode->getIndex());
			prevNode->next = newNode;
			newNode->next = findNode;
			updateLinkedAddIndex(findNode);
			//prevNode->next = findNode->next;
			//findNode = currNode->next;
			break;
		}
		prevNode = currNode;
		currNode = currNode->next;

	}
	return;
}

void SinglyLinkedList::updateLinkedAddIndex(std::shared_ptr<Node> update)
{
	while (update!=nullptr)
	{
		update->setUpIndex(update->getIndex() + 1);
		update = update->next;
	}
}
