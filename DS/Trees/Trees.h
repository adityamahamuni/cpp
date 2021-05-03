#pragma once
#ifndef _TREES_H_
#define _TREES_H_

#include<iostream>
#include<exception>
#include"Queue.h"


enum NODE_CHILD { L, R };

class TreeException : virtual public std::exception {
	std::string msg;

public:
	TreeException(std::string msg) : msg(msg) {}

	virtual ~TreeException() throw() {}
	virtual const char* what() const throw() {
		return msg.c_str();
	}
};

template <class T>
struct node {
	int data;
	node<T>* left;
	node<T>* right;
};

template <class T>
class BinaryTree {

public:
	node<T>* root;

	BinaryTree() : root(nullptr) {}
	
	node<T>* createEmpty(node<T>* nodePtr) {
		if (nodePtr == nullptr) {
			return NULL;
		}
		else {
			createEmpty(nodePtr->left);
			createEmpty(nodePtr->right);
			delete nodePtr;
		}
		return NULL;
	}

	node<T>* insert(T data, node<T>* nodePtr) {
		if (nodePtr == nullptr)
		{
			nodePtr = new node<T>;
			nodePtr->data = std::move(data);
			nodePtr->left = nodePtr->right = nullptr;
		}
		else if (data < nodePtr->data) {
			nodePtr->left = insert(data, nodePtr->left);
		}
		else if (data > nodePtr->data) {
			nodePtr->right = insert(data, nodePtr->right);
		}

		return nodePtr;
	}

	void inorder(node<T>* nodePtr) {
		if (nodePtr == nullptr)
			return;
		inorder(nodePtr->left);
		std::cout << nodePtr->data << " ";
		inorder(nodePtr->right);
	}

	void inorder() {
		inorder(root);
		std::cout << std::endl;
	}

	void preorder(node<T>* nodePtr) {
		if (nodePtr == nullptr)
			return;
		std::cout << nodePtr->data << " ";
		preorder(nodePtr->left);
		preorder(nodePtr->right);
	}

	void preorder() {
		preorder(root);
		std::cout << std::endl;
	}

	void postorder(node<T>* nodePtr) {
		if (nodePtr == nullptr)
			return;
		postorder(nodePtr->left);
		postorder(nodePtr->right);
		std::cout << nodePtr->data << " ";
	}

	void postorder() {
		postorder(root);
		std::cout << std::endl;
	}
	
	void levelorder(node<T> * nodePtr) {
		Queue<node<T>*> q(100);
		std::cout << root->data << " ";

		q.enqueue(nodePtr);
		while (!q.isEmpty()) {
			nodePtr = q.dequeue();
			if (nodePtr->left) {
				std::cout << nodePtr->left->data << " ";
				q.enqueue(nodePtr->left);
			}
			if (nodePtr->right) {
				std::cout << nodePtr->right->data << " ";
				q.enqueue(nodePtr->right);
			}
		}
	}

	void levelorder() {
		levelorder(root);
		std::cout << std::endl;
	}
	
	void insert(T data) {
		root = insert(data, root);
	}

	void display() {
		inorder(root);
		std::cout << std::endl;
	}

	node<T>* min(node<T>* nodePtr) {
		if (nodePtr == nullptr)
			return NULL;
		else if (nodePtr->left == nullptr)
			return nodePtr;
		else
			return min(nodePtr->left);
	}

	node<T>* max(node<T>* nodePtr) {
		if (nodePtr == nullptr)
			return NULL;
		else if (nodePtr->right == nullptr)
			return nodePtr;
		else
			return max(nodePtr->right);
	}

	node<T>* remove(T data, node<T>* nodePtr) {
		node<T>* temp;

		if (nodePtr == nullptr)
			return NULL;
		else if (data < nodePtr->data)
			nodePtr->left = remove(data, nodePtr->left);
		else if (data > nodePtr->data)
			nodePtr->right = remove(data, nodePtr->right);

		else if (nodePtr->left && nodePtr->right)
		{
			temp = min(nodePtr->right);
			nodePtr->data = temp->data;
			nodePtr->right = remove(nodePtr->data, nodePtr->right);
		}
		else {
			temp = nodePtr;
			if (nodePtr->left == nullptr)
				nodePtr = nodePtr->right;
			else if (nodePtr->right == nullptr)
				nodePtr = nodePtr->left;

			delete temp;
		}
		return nodePtr;
	}

	void remove(T data) {
		root = remove(data, root);
	}

	bool search(T data, node<T>* nodePTr) {
		if (nodePTr == nullptr)
			return false;
		else {
			if (data == nodePTr->data)
				return true;
			else if (data < nodePTr->data)
				return search(data, nodePTr->left);
			else if (data > nodePTr->data)
				return search(data, nodePTr->right);
		}
		return false;
	}

	void search(T data) {
		if (search(data, root))
			std::cout << "Element " << data << " found in the Binary Search Tree." << std::endl;
		else
			std::cout << "Element " << data << " not found in the Binary Search Tree." << std::endl;
	}

};

#endif // !_TREES_H_

