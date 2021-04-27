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

