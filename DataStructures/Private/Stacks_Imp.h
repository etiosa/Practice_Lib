//
// Created by Etiosa Obasuyi on 2018-12-06.
//

#ifndef PRACTICE_LIB_STACKS_IMP_H
#define PRACTICE_LIB_STACKS_IMP_H

/*implement last-in-first out(LIFO) */
#include <vector>
#include <array>
#define MAX_SIZE 1000
class Stacks_Imp {
private:
    int size;
    int data;
    std::vector<int>stacks;
    int top;//store the top of the stack
   // static const int  MAX_SIZE=4;
    enum {MAX_SIZES};

    std::array<int, MAX_SIZE>stacks_Ar;

    /* how you int c++ class array
     *
     *array<int, size>
     * int []...is c style array--dont use it
     *
     * *
     */



public:
    bool isEmpty();
    Stacks_Imp( int);
    ~Stacks_Imp();
    void push(int);
    int pop();
    int getTop() const { return top;}
    void printInfo();

};


#endif //PRACTICE_LIB_STACKS_IMP_H
