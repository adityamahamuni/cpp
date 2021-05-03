#include<iostream>
#include"Trees.h"

int main() {

	std::cout << " ************* Binary Search Tree************ " << std::endl;
	BinarySearchTree<int> tree;

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



	std::cout << "\n ************* AVL Tree************ " << std::endl;
	AVLTree<int> avltree;
	avltree.insert(10);
	avltree.insert(5);
	avltree.insert(20);

	std::cout << "\nElements of AVL Tree (inorder traversal) : " << std::endl;
	avltree.display();

	std::cout << "\nElements of AVL Tree (pre-order traversal) : " << std::endl;
	avltree.preorder();
	std::cout << "\nElements of AVL Tree (post-order traversal) : " << std::endl;
	avltree.postorder();


	std::cout << "\n ******** LL Rotation of AVL Tree *********** " << std::endl;
	AVLTree<int> llRotate;

	llRotate.insert(20);
	llRotate.insert(10);
	llRotate.insert(5);

	std::cout << "\nElements of AVL Tree : " << std::endl;
	llRotate.display();

	std::cout << "\n ******** LR Rotation of AVL Tree *********** " << std::endl;
	AVLTree<int> lrRotate;

	lrRotate.insert(30);
	lrRotate.insert(10);
	lrRotate.insert(20);

	std::cout << "\nElements of AVL Tree (inorder traversal) : " << std::endl;
	lrRotate.display();

	std::cout << "\n ******** RR Rotation of AVL Tree *********** " << std::endl;
	AVLTree<int> rrRotate;

	rrRotate.insert(10);
	rrRotate.insert(20);
	rrRotate.insert(50);

	std::cout << "\nElements of AVL Tree (inorder traversal) : " << std::endl;
	rrRotate.display();

	std::cout << "\n ******** RL Rotation of AVL Tree *********** " << std::endl;
	AVLTree<int> rlRotate;

	rlRotate.insert(10);
	rlRotate.insert(30);
	rlRotate.insert(20);

	std::cout << "\nElements of AVL Tree (inorder traversal) : " << std::endl;
	rlRotate.display();

	return 0;
}