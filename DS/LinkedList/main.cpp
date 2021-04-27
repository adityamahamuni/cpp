#include<iostream>
#include"LinkedList.h"
#include"CircularLinkedList.h"
#include"DoublyLinkedList.h"


int main(int argc, const char* argv[]) {

	std::cout << "********* Singly Linked List ***************" << std::endl;
	LinkedList<int> list;
	list.addNode(100);

	list.addNode(200);
	list.addNode(300);
	list.addNode(400);

	//list.insert(700, 0);
	list.push_back(800);
	list.push_back(900);
	list.push_back(900);

	int x = 0;

	list.display(); 
	
	x = list.remove(1);
	std::cout << x << " - Element removed from the list" << std::endl;

	list.display();

	std::cout << "Size of Linked List : " << list.size() << std::endl;
	
	std::cout << "Sum of Elements of Linked List : " << list.sum() << std::endl;
	std::cout << "Max : " << list.max() << std::endl;

	if (list.LinearSearch(100) != NULL) {
		std::cout << "Linear Search found element " << std::endl;
	}
	else {
		std::cout << "Element not found in the List." << std::endl;
	}
	
	if (list.isSorted()) {
		std::cout << "List is Sorted!! " << std::endl;
	}
	else {
		std::cout << "List is not Sorted!!" << std::endl;
	}


	std::cout << "Before removing Duplicates!" << std::endl;
	list.display();

	list.removeDuplicates();
	std::cout << "After removing Duplicates!" << std::endl;
	list.display();

	std::cout << "\nConcatenate Linked Lists" << std::endl;
	LinkedList<int> list2;
	list2.addNode(1000);
	list2.addNode(1100);
	list2.addNode(1200);

	LinkedList<int> concateList;
	concateList = list + list2;

	concateList.display();

	std::cout << "\n********* Circular Linked List ***************" << std::endl;
	CircularLinkedList<int> clist1;
	clist1.addNode(100);
	clist1.addNode(2);
	clist1.addNode(500);
	clist1.insert(50, 1);

	clist1.display();

	std::cout << "Size of List : " << clist1.size() << std::endl;

	clist1.remove(3);
	clist1.display();


	std::cout << "\n********* Doubly Linked List ***************" << std::endl;
	DoublyLinkedList<int> dlist;
	dlist.addNode(500);
	dlist.addNode(700);
	dlist.addNode(25);
	dlist.insert(50, 2);
	dlist.insert(70, 1);

	dlist.display();

	std::cout << "Size of List : " << dlist.size() << std::endl;

	dlist.remove(1);
	dlist.display();

	dlist.push_back(20);
	dlist.display();

	return 0;
}