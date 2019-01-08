//
// Created by Etiosa Obasuyi on 2018-12-06.
//

#include "../Private/Doubly_Node.h"

Doubly_Node::Doubly_Node(int data):next(nullptr), prev(nullptr), data(data), indexPosition(0) {

}
Doubly_Node::~Doubly_Node()
{

}
void Doubly_Node::setupIndex(int index)
{
    indexPosition=index;
}