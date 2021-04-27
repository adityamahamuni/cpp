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
	CircularLinkedList() : head(nullptr) {
		last = head;
	}
	~CircularLinkedList() {}

	void addNode(const T val) {
		Node<T>* newnode = new Node<T>();
		newnode->data = std::move(val);
		newnode->next = head;

		if (head == nullptr) {
			newnode->next = newnode;
			head = newnode;
		}
		else {
			Node<T>* temp = head;
			while (temp->next != head)
				temp = temp->next;
			temp->next = newnode;
		}
		last = newnode;
		last->next = head;
	}

	void insert(T val, int pos = 0) {
		try {
			if (pos < 0 || pos > size())
				throw(CircularLinkedListException("Circular LinkedList Exception: Index out of range."));
		}
		catch (const CircularLinkedListException& me) {
			std::cout << me.what() << std::endl;
		}

		Node<T>* temp = new Node<T>();
		temp->data = std::move(val);

		Node<T>* p;

		if (pos == 0) {
			temp->next = head;
			head = temp;
		}
		else if(pos > 0) {
			p = head;
			for (int i = 0; i < pos - 1 && p; i++)
				p = p->next;
			temp->next = p->next;
			p->next = temp;
		}
	}

	T remove(int pos = 0) {
		T x;
		try {
			if (pos < 0 || pos > size())
				throw(CircularLinkedListException("Circular LinkedList Exception: Index out of range."));
		}
		catch (const CircularLinkedListException& me) {
			std::cout << me.what() << std::endl;
		}

		Node<T>* temp = head;
		Node<T>* p = nullptr;

		if (pos == 0) {
			head = head->next;
			x = temp->data;

			delete temp;
			return x;
		}
		else if(pos > 0) {
			p = head;
			for (int i = 0; i < pos - 1 && p; i++) {
				temp = p;
				p = p->next;
			}
			temp->next = p->next;
			x = temp->data;
			
			delete p;
			return x;
		}
		return NULL;
	}

	void display() {
		Node<T>* temp = head;

		try {
			if (head == nullptr) {
				throw(CircularLinkedListException("Circular LinkedList Exception: No elements in the List."));
			}
			else {
				do {
					std::cout << temp->data << " ";
					temp = temp->next;
				} while (temp->next != head);
				std::cout << temp->data << std::endl;
			}
		}
		catch (const CircularLinkedListException& me) {
			std::cout << me.what() << std::endl;
		}

	}

	int size() {
		int count = 1;
		if (head == nullptr) {
			return 0;
		}
		else {
			Node<T>* temp = head;
			do {
				count++;
				temp = temp->next;
			} while (temp->next != head);
		}
		return count;
	}

};

#endif // !_CIRCULARLINKEDLIST_H_