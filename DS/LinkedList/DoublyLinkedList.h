#pragma once
#ifndef _DOUBLYLINKEDLIST_H_
#define _DOUBLYLINKEDLIST_H_

#include<iostream>
#include<exception>


class DoublyLinkedListException : virtual public std::exception {
	std::string msg;

public:
	DoublyLinkedListException(std::string msg) : msg(msg) {}

	virtual ~DoublyLinkedListException() throw() {}
	virtual const char* what() const throw() {
		return msg.c_str();
	}
};

template <class T>
class DNode {
public:
	DNode<T>* prev;
	T data;
	DNode<T>* next;
};

template <class T>
class DoublyLinkedList {
private:
	DNode<T>* head;

public:
	DoublyLinkedList() : head(nullptr) {}
	~DoublyLinkedList() {}

	friend std::ostream& operator<<(std::ostream& str, DoublyLinkedList& data) {
		data.display(str);
		return str;
	}

	int size() {
		int count = 0;
		if (head == nullptr)
			return 0;
		else {
			DNode<T>* temp = head;
			while (temp != nullptr) {
				count++;
				temp = temp->next;
			}
		}
		return count;
	}

	void addNode(const T val) {
		DNode<T>* newnode = new DNode<T>();
		newnode->data = std::move(val);
		newnode->prev = nullptr;
		newnode->next = nullptr;

		if (head == nullptr)
			head = newnode;
		else {
			DNode<T>* temp = head;
			while (temp->next != nullptr) {
				temp = temp->next;
			}
			temp->next = newnode;
			newnode->prev = temp;
		}
	}

	void insert(const T val, int pos = 0) {
		try {
			if (pos < 0 || pos > size())
				throw(DoublyLinkedListException("Doubly LinkedList Exception: Index out of range."));
		}
		catch (const DoublyLinkedListException& me) {
			std::cout << me.what() << std::endl;
		}

		DNode<T>* temp = new DNode<T>();
		temp->data = std::move(val);

		DNode<T>* p;

		if (pos == 0) {
			temp->prev = head;
			temp->next = head;
			head = temp;
		}
		else if (pos > 0) {
			p = head;
			for (int i = 0; i < pos - 1 && p; i++)
				p = p->next;
			temp->prev = p;
			temp->next = p->next;
			p->next = temp;
		}
	}

	void push_back(const T val) {
		DNode<T>* newnode = new DNode<T>();
		newnode->data = std::move(val);
		newnode->prev = nullptr;
		newnode->next = nullptr;

		if (head == nullptr)
			head = newnode;
		else {
			DNode<T>* temp = head;
			while (temp->next != nullptr) {
				temp = temp->next;
			}
			temp->next = newnode;
			newnode->prev = temp;
		}
	}

	T remove(int pos = 0) {

		T x;

		try {
			if (pos < 0 || pos > size())
				throw(DoublyLinkedListException("Doubly LinkedList Exception: Index out of range."));
		}
		catch (const DoublyLinkedListException& me) {
			std::cout << me.what() << std::endl;
		}

		DNode<T>* p = nullptr;
		DNode<T>* temp = head;

		if (pos == 0) {
			head = head->next;
			x = temp->data;
			delete temp;
			return x;
		}
		else if (pos > 0) {
			p = head;
			for (int i = 0; i <= pos - 1 && p; i++) {
				temp = p;
				p = p->next;
			}
			temp->prev = p;
			temp->next = p->next;

			x = temp->data;
			delete p;
			return x;
		}
		return NULL;
	}

	void display(std::ostream& str = std::cout) {
		if (head == nullptr)
			std::cout << "List is empty" << std::endl;
		else {
			DNode<T>* temp = head;
			while (temp) {
				str << temp->data << " ";
				temp = temp->next;
			}
			str << std::endl;
		}
	}

};

#endif // !_DOUBLYLINKEDLIST_H_

