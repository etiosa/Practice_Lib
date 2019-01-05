//
// Created by Etiosa Obasuyi on 2018-12-06.
//
#include<iostream>
#include "../Private/SinglyLinkedList.h"
SinglyLinkedList::SinglyLinkedList():head(nullptr), size(0),indexPostion(0) {

}
SinglyLinkedList::~SinglyLinkedList() {}


bool SinglyLinkedList::isEmpty() {
    return head != nullptr;
}

void SinglyLinkedList::printInfo()
{
    std::shared_ptr<Node> currNode= head;
    while(currNode!= nullptr)
    {
        std::cout<<" "<<currNode->getData();
        currNode=currNode->next;
    }
}

bool SinglyLinkedList::linkedFirst(int data)
{
    std::shared_ptr<Node> newNode= std::make_shared<Node>(data);
    size++;
    newNode->setUpIndex(size-1);

    if(!isEmpty())
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
    /* th*/

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
        currNode->setUpIndex(nextIndex);
        nextNode->setUpIndex(prevIndex);
        currNode=nextNode;
    }
}


bool SinglyLinkedList::linkedLast(int data)
{
    std::shared_ptr<Node> newNode= std::make_shared<Node>(data);
    size++;
    newNode->setUpIndex(size-1);


    if(!isEmpty())
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

void SinglyLinkedList::pushFront(int data, int index)
{

}
void SinglyLinkedList::pushBack(int data)
{
    linkedLast(data);
}


/*  */
bool SinglyLinkedList::isIndexValid(int indexValid)
{
    return indexValid>=0 && indexValid< size;
}