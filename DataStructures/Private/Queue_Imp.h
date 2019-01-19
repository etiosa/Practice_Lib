//
// Created by Etiosa Obasuyi on 2018-12-06.
//

#ifndef PRACTICE_LIB_QUEUE_IMP_H
#define PRACTICE_LIB_QUEUE_IMP_H

#define  MAX_SIZE 1000
#include<array>
/* implement first-in-FIRST-out(FIFO)*/
class Queue_Imp {
private:
    int headIndex;
    int tailIndex;//keep track of the newly arrived element to the list

    std::array <int, MAX_SIZE> Queue;
  //  int [MAX_SIZE] Queue;

public:
    void Enequeue(int); // insert into the list at the end of the list
    /* just as customers waiting in the line
     * the newly arrived customers will be place in the end of the line*/
    int Dequeue(); // take the element at the head of the list
    Queue_Imp();
    ~Queue_Imp();
};


#endif //PRACTICE_LIB_QUEUE_IMP_H
