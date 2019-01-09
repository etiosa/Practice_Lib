//
// Created by Etiosa Obasuyi on 2018-12-06.
//

#ifndef PRACTICE_LIB_DOUBLY_NODE_H
#define PRACTICE_LIB_DOUBLY_NODE_H
#include<memory>
#include<string>
/* TODO: Change raw pointer to smart pointer*/
/*TODO: Change this class to template class*/
class Doubly_Node {
private:
    //Doubly_Node* next;
    //Doubly_Node* prev;
    

    /*TODO: change the data to a template */
    int data;
    int indexPosition;



public:
	std::shared_ptr<Doubly_Node> next;
	std::shared_ptr<Doubly_Node>prev;
    /*TODO: change the return type to a template */
    int getData() const { return  data;}

    void setupIndex(int);
    int getIndex() const {return indexPosition;}

    Doubly_Node(int);
    ~Doubly_Node();
};


#endif //PRACTICE_LIB_DOUBLY_NODE_H
