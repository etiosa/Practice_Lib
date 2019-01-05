//
// Created by Etiosa Obasuyi on 2018-12-06.
//

#include "../Private/Node.h"


Node::Node(int data):next(nullptr), data(data), indexPosition(0) {


}

Node::~Node()
{

}

void Node::setUpIndex(int index)
{
    indexPosition=index;
}