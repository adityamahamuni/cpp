#pragma once
#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#include<iostream>
#include<exception>


class LinkedListException : virtual public std::exception {
	std::string msg;

public:
	LinkedListException(std::string msg) : msg(msg) {}

	virtual ~LinkedListException() throw() {}
	virtual const char* what() const throw() {
		return msg.c_str();
	}
};


template <class T>
class Node {
public:
	T data;
	Node<T>* next;
};

template <class T>
class LinkedList {
private:
	Node<T>* head;
	Node<T>* last;

public:
	LinkedList() : head(nullptr), last(nullptr) {}
	LinkedList(T data) {
		addNode(data);
	}

	
	~LinkedList(){}

	friend std::ostream& operator<<(std::ostream& str, LinkedList& data) {
		data.display(str);
		return str;
	}


	LinkedList<T>& operator +(LinkedList& other) {
		if (head == nullptr) {
			return other;
		}
		else if (other.head == nullptr) {
			return *this;
		}
		else {
			LinkedList<T> result;
			result.head = head;
			Node<T>* temp = result.head;

			while (temp->next != nullptr)
				temp = temp->next;

			temp->next = other.head;
			while (temp->next != nullptr)
				temp = temp->next;

			temp->next = nullptr;
			result.last = temp;

			return result;
		}
	}


	LinkedList<T>& concatenate(LinkedList& other) {
		return head + other;
	}

	void addNode(const T data) {

		Node<T>* newnode = new Node<T>();
		newnode->data = std::move(data);
		newnode->next = nullptr;

		if (head == nullptr)
			head = newnode;

		else {
			Node<T>* temp = head;
			while (temp->next != nullptr)
				temp = temp->next;
			temp->next = newnode;
		}
		last = newnode;
	}

	int size() {
		int count = 0;
		if (head == nullptr)
			return 0;
		else {
			Node<T>* temp = head;
			while (temp != nullptr) {
				count++;
				temp = temp->next;
			}
		}
		return count;
	}
	int sum() {
		int total = 0;
		if (head == nullptr)
			return 0;
		else {
			Node<T>* temp = head;
			while (temp != nullptr) {
				total = total + temp->data;
				temp = temp->next;
			}
		}
		return total;
	}
	int max() {
		int MAX = -32678;
		if (head == nullptr)
			return 0;
		else {
			Node<T>* temp = head;
			while (temp != nullptr) {
				if (MAX < temp->data)
					MAX = temp->data;
				temp = temp->next;
			}
		}
		return MAX;
	}

	T LinearSearch(T key) {
		if (head == nullptr)
			return 0;
		else {
			Node<T>* temp = head;
			while (temp != nullptr) {
				if (temp->data == key)
					return temp->data;
				temp = temp->next;
			}
		}
		return NULL;
	}

	void display(std::ostream& str = std::cout) const {
		if (head == nullptr)
			std::cout << "List is empty!\n";
		else {
			Node<T>* temp = head;
			while (temp != nullptr) {
				str << temp->data << " ";
				temp = temp->next;
			}
			std::cout << "\n";
		}
	}

	void insert(T val, int pos = 0) {

		try {
			if (pos < 0 || pos > size())
				throw(LinkedListException("LinkedList Exception: Index out of range."));
		}
		catch (const LinkedListException& me) {
			std::cout << me.what() << std::endl;
		}

		Node<T>* temp  =new Node<T>();
		temp->data = std::move(val);

		Node<T>* p;

		if (pos == 0) {
			temp->next = head;
			head = temp;
		}
		else if (pos > 0){
			p = head;
			for (int i = 0; i < pos - 1 && p; i++) {
				p = p->next;
			}
			temp->next = p->next;
			p->next = temp;
		}
	}

	void push_back(T data) {
		Node<T>* temp = new Node<T>();
		temp->data = std::move(data);
		temp->next = nullptr;

		if (head == nullptr)
			head = last = temp;

		else {
			last->next = temp;
			last = temp;
		}
	}

	T remove(int pos = 0) 
	{
		
		T x;

		try {
			if (pos < 0 || pos > size())
				throw(LinkedListException("LinkedList Exception: Index out of range."));
		}
		catch (const LinkedListException& me) {
			std::cout << me.what() << std::endl;
		}

		Node<T>* p = nullptr;
		Node<T>* temp = head;

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
			temp->next = p->next;
			x = temp->data;
			delete p;
			return x;
		}
		return NULL;
	}

	bool isSorted() {
		if (head == nullptr) {
			std::cout << "List is empty!\n";
			return false;
		}
		else {
			Node<T>* temp = head;
			T x = NULL;
			while (temp != nullptr) {
				if (temp->data < x) { return false; }
				x = temp->data;
				temp = temp->next;				
			}
		}
		return true;
	}

	void removeDuplicates() {
		try {
			if (isSorted()) {
				Node<T>* temp = head;
				Node<T>* p = head->next;

				while (p != nullptr) {
					if (temp->data != p->data) {
						temp = p;
						p = p->next;
					}
					else {
						temp->next = p->next;
						delete p;
						p = temp->next;
					}
				}
			}
			else {
				throw(LinkedListException("LinkedList Exception: LinkedList is not Sorted."));
			}
		}
		catch (const LinkedListException& me) {
			std::cout << me.what() << std::endl;
		}
	}

};

#endif // !_LINKEDLIST_H_
