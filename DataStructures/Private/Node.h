//
// Created by Etiosa Obasuyi on 2018-12-06.
//

#ifndef PRACTICE_LIB_NODE_H
#define PRACTICE_LIB_NODE_H
#include<memory>
/* TODO: change the raw pointer to smart pointer: shared_pointer */
/* TODO: change Node class to a template class*/
class Node {
private:
    //Node* next;
    int data;
    int indexPosition;

    bool checkIndex();
    bool isIndexValid(int);



/* Note: Node class is use to chain links*/
public:
    Node(int);
    ~Node();
    //std::shared_ptr<Node>getNext() const { return next;}

    /*TODO:  Change the next variable to private */
     std::shared_ptr<Node> next;
     int getData() const {return data;}
     int getIndex() const{return indexPosition;}

     /* setup the position of the node in the linked list */
     void setUpIndex(int);

};


#endif //PRACTICE_LIB_NODE_H
