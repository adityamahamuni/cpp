#pragma once
#ifndef _TREES_H_
#define _TREES_H_

#include<iostream>
#include<exception>


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

};

#endif // !_TREES_H_

