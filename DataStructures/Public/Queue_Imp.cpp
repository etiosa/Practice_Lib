//
// Created by Etiosa Obasuyi on 2018-12-06.
//

#include "../Private/Queue_Imp.h"
#include <iostream>

/*
 * the element reside in the queue
 * head+1....head+1....tail-1,tail-1..tail is the las the element
 *
 * when tail =3
 * size is 3
 * if tail == size
 * tail=1
 * 0,1,2,3,4,5== 6 size
 *
 * */
Queue_Imp::Queue_Imp(): headIndex(0), tailIndex(0)
{

}
Queue_Imp::~Queue_Imp() {}

void Queue_Imp::Enequeue(int data)
{
    /* the tail of the keep check of the next element in the list */
    /* while the head keep the head of the list
     * the element that has been in the list longer
     * */
    //tail of the queue should keep the track of the list
    //while inser it into the list
    Queue [tailIndex] = data;
    //check if the queue is empty
    if(tailIndex==Queue.size()) {
        /* circular  when tail index is equal to size
         * *
         * /
         *
         * /
         */
        //doing 0 base indexing
        tailIndex = 0;
    }
        else
            {
            //after add increment the tail index
            tailIndex= tailIndex+1;
            }

    }




int Queue_Imp::Dequeue()
{
    // when the head index is eqauil to tailindex plus 1
    //the element is fulll there is oberflow....because headIndex is 0

   int sizeCheck = tailIndex+1;
   if(sizeCheck==Queue.size())
   {
       std::cout<<"the Queue is overFlow"<<std::endl;
       return -1;
   }
   else if (headIndex==tailIndex)
   {
       std::cout<<"underFlow"<<std::endl;
       return -1;
   }
    //get the element in the head first
    int data;
   data = Queue[headIndex];
   //once the we reach the head==size..we are done with the list of the queue


   return 0;

}
