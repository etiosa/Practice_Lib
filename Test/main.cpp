
#include <iostream>
#include "../DataStructures/Private/SinglyLinkedList.h"
#include"../DataStructures/Private/DoublyLinkedList.h"
#include "../DataStructures/Private/Stacks_Imp.h"
#include "../DataStructures/Private/Queue_Imp.h"
#include "../DataStructures/Private/BinaryTree.h"

int main() {

	//i=y;
	//y=i;
	  SinglyLinkedList testing;
    //testing.Testing<int>();
    testing.pushFront(5);//index 0  ...now swamping
    testing.pushFront(4);//index 1
    testing.pushFront(1);// index 3 ... now swamping
    testing.pushFront(120);
	//testing.pushFront(123);
	//testing.pushFront(124);
	//testing.pushFront(125);
	//testing.pushFront(100, 0);
	//testing.add(10023, 3);
	//testing.add(100222223, 5);
	///testing.printInfo();

	///testing.reverse();
	//std::cout << "after reverse" << std::endl;

	//testing.printInfo();
	//std::cout << "TAIL IS "<<testing.returnTail()->getData();
	//std::shared_ptr<Node>headNext = testing.returnHead();
	//testing.addAfter(headNext, 100000);
	//testing.addBefore(headNext,9999999);
	//std::shared_ptr<Node>headNexts = testing.returnHead();

	//std::cout << testing.returnHead()<<std::endl;
	//testing.addBefore(headNexts, 9999999);

	//std::cout << testing.returnHead() << std::endl;

	//testing.addBefore(headNext, 042);
	//testing.printInfo();
	//std::cout<<"before delete Node called"<<std::endl;
	auto head= testing.returnHead();
	//auto searchNode = head;
	//int result=testing.deleteNode(head,searchNode->next->next->next);

	//std::cout<<"tail"<<"------"<<searchNode->next->next->next->getData()<<std::endl;

	//std::cout<<"after delettin"<<std::endl;
	//	std::cout<<"delete value"<< result<<std::endl;

	
	testing.printInfo();

	testing.descendSort(head);
	
	//std::cout<< sortedList->getData()<<std::endl;

	
	//testing.deleteNode(testing.returnHead(), )
	//testing.deleteList();
	//std::cout << "after delete list" << std::endl;
	//testing.printInfo();
	//std::cout << "size after delete" << testing.getSize()<< std::endl;
	//std::cout << "print after delete" << std::endl;
	//testing.printInfo();
	
	//testing.pushFront(2, 2);
	//testing.find(0);
	//testing.popFront();
	
	//testing.popFront();




    //operation: pushfront
    //: old is 0
    //: new is 3..
	

	/* ======== DOUBLY LINKED LIST */

	/*DoublyLinkedList testing;
	testing.pushFront(100);
	testing.pushFront(200);
	testing.pushBack(300);
	testing.pushFront(200);
	testing.pushFront(1000);
	testing.addBefore(-90, 4);

	testing.printInfo();


	//testing.popBack();

	std::shared_ptr<Doubly_Node> head= testing.getHead();
	std::shared_ptr<Doubly_Node>tail = testing.getTail();

	///testing.printInfo();
	//testing.addAfter(head, 8000);
	//testing.addAfter(tail, 10000);

	///std::cout<<"before adding to after second ele"<<std::endl;
	////testing.printInfo();
	///std::shared_ptr<Doubly_Node>secondele = testing.getHead()->next;


	////std::cout<<secondele->getData()<<std::endl;

	//testing.addBefore(head,1);


	//testing.addAfter(secondele,2999);

	std::shared_ptr<Doubly_Node> head2= testing.getHead();

	std::shared_ptr<Doubly_Node>tail2 = testing.getTail();


	//testing.addBefore(head2,1);
	//testing.addBefore(tail2,-9);
	////std::shared_ptr<Doubly_Node>third = testing.getHead()->next->next;

	//std::cout<<testing.getHead()->next->next->getData()<<std::endl;
	///testing.addBefore(third,987);

	//std::cout<<"before reverse;"<<std::endl;
	///std::cout<<"after adding to after second ele"<<std::endl;

	testing.printInfo();

	std::cout<<"index is   "<<std::endl;

	testing.printIndex();

	//int arr[20];
	/*Stacks_Imp stackstesting (5);
	stackstesting.push(9);
	stackstesting.push(12);
	stackstesting.push(40);
	stackstesting.push(400);*/


	/*std::cout<<"the recently added index in the stack is "<<stackstesting.getTop()<<std::endl;
	//std::cout<<
	stackstesting.printInfo();
	int pop = stackstesting.pop();
	int pop1 = stackstesting.pop();
	int pop2= stackstesting.pop();

	std::cout<<"pop data is "<<pop<<std::endl;
	std::cout<<"pop1 data is "<<pop1<<std::endl;
	std::cout<<"pop2 data is "<<pop2<<std::endl;

	stackstesting.printInfo();*/

	/*Queue_Imp t;
	t.Enequeue(1);
    t.Enequeue(2);
    t.Enequeue(3);
    t.Enequeue(4);
    t.Enequeue(5);

    t.Dequeue();*/

	BinaryTree bst;
	//bst.addToBST(10);

	return 0;
}