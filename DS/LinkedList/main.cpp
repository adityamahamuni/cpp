#include<iostream>
#include"LinkedList.h"


int main(int argc, const char* argv[]) {
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
	list.addNode(1000);
	list.addNode(1100);
	list.addNode(1200);

	LinkedList<int> concateList;
	concateList = list + list2;

	concateList.display();

	return 0;

}