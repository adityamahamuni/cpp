#include<iostream>
#include"Trees.h"

int main() {

	std::cout << " ************* Binary Search Tree************ " << std::endl;
	BinaryTree<int> tree;

	tree.insert(20);
	tree.insert(10);
	tree.insert(25);
	tree.insert(30);
	tree.insert(15);

	std::cout << "Elements of Binary Search Tree : (inorder traversal) " << std::endl;
	tree.display();

	std::cout << "Elements of Binary Search Tree : (pre-order traversal) " << std::endl;
	tree.preorder();
	std::cout << "Elements of Binary Search Tree : (post-order traversal) " << std::endl;
	tree.postorder();

	std::cout << "Elements of Binary Search Tree : (level-order traversal) " << std::endl;
	tree.levelorder();

	tree.search(10);

	tree.remove(20);

	std::cout << "Elements of Binary Search Tree : " << std::endl;
	tree.display();
	tree.remove(25);

	std::cout << "Elements of Binary Search Tree : " << std::endl;
	tree.display();
	tree.remove(30);

	std::cout << "Elements of Binary Search Tree : " << std::endl;
	tree.display();

	return 0;
}