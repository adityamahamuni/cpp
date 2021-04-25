#include<iostream>
#include"LinkedList.h"


int main(int argc, const char* argv[]) {
	LinkedList<int> list;
	list.addNode(100);

	list.addNode(200);
	list.addNode(300);
	list.addNode(400);
	list.insert(700, 0);
	list.push_back(800);
	list.push_back(900);


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
	
	return 0;

}