//
// Created by Etiosa Obasuyi on 2018-12-06.
//

#include "../Private/Stacks_Imp.h"
#include<iostream>
Stacks_Imp::Stacks_Imp(int size): data(0), size(0), top(0)
{
    stacks_Ar[MAX_SIZE];
}
Stacks_Imp::~Stacks_Imp()
{}
/*going to use array..well vector...dyanmaic
 * going to keep track of the index  that the element was pushed in
 *
 * the
 *
 * */

/*can only be done in the class: because is not part of an instance of a an  object but
 * for class
 * static void Stacks_Imp::steUpSize(int)
{

}*/
int Stacks_Imp::pop()
{
    if(!isEmpty())
    {
        std::cout<<"underFlows"<<std::endl;
        return -1;
    }
    else {
        //if we are doing one base index
        //first index is one
        //second index == 2
        //
        top = top-1; // decrease when we call the pop again: and +1 so we  get the las t element
       //in the array
       int data = stacks_Ar[top];
        //top = top-1;
        return  stacks_Ar[top+1];
    }
}
void Stacks_Imp::push(int data)
{

    /* add to an array: remember arr[0] will have access to the element
     * add to an array: have top to keep track of the element index
     *
     *
     * */
    /* 1. add element
     *
     * everytime someone called add increase
     *
     * the top */
    /* first time
     *
     * top would be
     *
     * after function execute top will now be 1
     *
     * when the method execute again
     * top is till one
     *
     * after the method execute the top will now be two
     *
     * 1) 1 -1 = 0  first run top is 0
     * 2) 2- 1 = 1
     * 3) 3 -1 = 2
     * 4) 4 -1 = 3 ---> most recent
     * */
      size++;
      top = size -1;
      stacks_Ar[top] = data;
}

bool Stacks_Imp::isEmpty()
{
    return size!=0;
}

void Stacks_Imp::printInfo()
{
    for(int i =0 ;i<=top;i++)
    {
        std::cout<<" "<<stacks_Ar[i];
    }
    std::cout<<std::endl;
}