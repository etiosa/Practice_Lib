//
// Created by Etiosa Obasuyi on 2018-12-06.
//

#include "../Private/SinglyLinkedList.h"
SinglyLinkedList::SinglyLinkedList():head(nullptr), size(0) {

}
SinglyLinkedList::~SinglyLinkedList() {}


bool SinglyLinkedList::isEmpty() {
    return head != nullptr;
}

