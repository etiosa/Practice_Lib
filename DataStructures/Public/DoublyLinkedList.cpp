//
// Created by Etiosa Obasuyi on 2018-12-06.
//

#include "../Private/DoublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList():size(0), head(nullptr),tail(nullptr) {

}

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
bool DoublyLinkedList::find(std::string findData)
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