#pragma once
#ifndef _STACK_H_
#define _STACK_H_

#include<iostream>
#include<exception>


class StackException : virtual public std::exception {
	std::string msg;

public:
	StackException(std::string msg) : msg(msg) {}

	virtual ~StackException() throw() {}
	virtual const char* what() const throw() {
		return msg.c_str();
	}
};


template <class T>
class Stack {
private:
	int size;
	int top;
	T* stackArr;

public:
	Stack() : top(-1) {}
	Stack(int size) : size(size), top(-1) { 
		stackArr = new T[size];
	}

	bool isEmpty() {
		if (top == -1)
			return true;
		return false;
	}

	bool isFull() {

		if (top == (size - 1))
			return true;
		return false;
	}

	void push(T data) {
		try {
			if (isFull())
				throw(StackException("Stack is Full."));
			else {
				stackArr[++top] = data;
			}
		}
		catch (const StackException& me) {
			std::cout << me.what() << std::endl;
		}
	}

	T pop() {
		try {
			if (isEmpty()) {
				throw(StackException("Stack is Empty."));
				return NULL;
			}
			else {
				T elem = stackArr[top];
				top--;
				return elem;
			}
		}
		catch (const StackException& me) {
			std::cout << me.what() << std::endl;
		}
	}

	T peek() {	
		try {
			if (isEmpty()) {
				throw(StackException("Stack is Empty."));
				return NULL;
			}
			else {
				return stackArr[top];
			}
		}
		catch (const StackException& me) {
			std::cout << me.what() << std::endl;
		}
	}

	void display() {
		for (int i = 0; i <= top; i++) {
			std::cout << stackArr[i] << " ";
		}
		std::cout << std::endl;
	}

	~Stack() {
		delete[] stackArr;
	}
};

#endif // !_STACK_H_

