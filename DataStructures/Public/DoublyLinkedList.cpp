//
// Created by Etiosa Obasuyi on 2018-12-06.
//

#include "../Private/DoublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList():size(0), head(nullptr),tail(nullptr) {

}

bool DoublyLinkedList::isEmpty()
{
    if(head != nullptr)
    {
        return true;
    }
    return false;
}
