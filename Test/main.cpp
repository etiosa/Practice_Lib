
#include <iostream>
#include "../DataStructures/Private/SinglyLinkedList.h"
#include"../DataStructures/Private/DoublyLinkedList.h"
int main() {
  //  SinglyLinkedList testing;
    //testing.Testing<int>();
 /*   testing.pushFront(5);//index 0  ...now swamping
    testing.pushFront(4);//index 1
    testing.pushBack(120);//index 2
    testing.pushFront(1);// index 3 ... now swamping
    testing.pushFront(120);
	testing.pushFront(123);
	testing.pushFront(124);
	testing.pushFront(125);
	//testing.pushFront(100, 0);
	testing.add(10023, 3);
	testing.add(100222223, 5);
	testing.printInfo();

	testing.reverse();
	std::cout << "after reverse" << std::endl;

	testing.printInfo();
	std::cout << "TAIL IS "<<testing.returnTail()->getData();
	/*std::shared_ptr<Node>headNext = testing.returnHead();
	testing.addAfter(headNext, 100000);
	testing.addBefore(headNext,9999999);
	std::shared_ptr<Node>headNexts = testing.returnHead();

	//std::cout << testing.returnHead()<<std::endl;
	testing.addBefore(headNexts, 9999999);

	std::cout << testing.returnHead() << std::endl;

	//testing.addBefore(headNext, 042);
	testing.printInfo();
	testing.deleteList();
	std::cout << "after delete list" << std::endl;
	testing.printInfo();
	std::cout << "size after delete" << testing.getSize()<< std::endl;
	std::cout << "print after delete" << std::endl;
	testing.printInfo();
	
	std::string t = "y";
	//testing.pushFront(2, 2);
	//testing.find(0);
	//testing.popFront();
	
	//testing.popFront();


	std::cout << "sized is "<<testing.getSize()<<std::endl;
	
	//testing.printInfo();

	testing.printIndex();

    //operation: pushfront
    //: old is 0
    //: new is 3..
	*/
	DoublyLinkedList testing;
	testing.pushFront(100);
	testing.pushFront(200);
	testing.pushBack(300);

	testing.printInfo();

	testing.reverse();

	//testing.printResver();
	testing.printInfo();
    return 0;
}