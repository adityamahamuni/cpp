#pragma once
#ifndef _CIRCULARLINKEDLIST_H_
#define _CIRCULARLINKEDLIST_H_

#include<iostream>
#include<exception>
#include"Node.h"


class CircularLinkedListException : virtual public std::exception {
	std::string msg;

public:
	CircularLinkedListException(std::string msg) : msg(msg) {}

	virtual ~CircularLinkedListException() throw() {}
	virtual const char* what() const throw() {
		return msg.c_str();
	}
};


template <class T>
class CircularLinkedList {
private:
	Node<T>* head;
	Node<T>* last;

public:
	CircularLinkedList() : head(nullptr), last(nullptr) {}

	void addNode(T val) {
		Node<T>* newnode = new Node<T>();
		newnode->data = std::move(val);
		newnode->next = nullptr;

		if (head == nullptr) {
			head = newnode;
		}
		else {
			Node<T>* temp = head;
			while (temp->next != nullptr)
				temp = temp->next;
			temp->next = newnode;
		}
		last = newnode;
		last->next = head;
	}

	void display() {
		Node<T>* temp = head;
		do {
			std::cout << temp->data << " ";
			temp = temp->next;
		} while (temp->next != head);
	}
};

#endif // !_CIRCULARLINKEDLIST_H_