
#include <iostream>
#include "../DataStructures/Private/SinglyLinkedList.h"
int main() {
    SinglyLinkedList testing;
    //testing.Testing<int>();
    testing.pushFront(5);//index 0  ...now swamping
    testing.pushFront(4);//index 1
    //testing.pushBack(120);//index 2
    testing.pushFront(1);// index 3 ... now swamping
    testing.pushFront(120);
    //operation: pushfront
    //: old is 0
    //: new is 3..



    testing.printInfo();
    return 0;
}