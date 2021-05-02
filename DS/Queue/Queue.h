#pragma once
#ifndef _QUEUE_H_
#define _QUEUE_H_

#include<iostream>
#include<exception>
#include"Stack.h"


class QueueException : virtual public std::exception {
	std::string msg;

public:
	QueueException(std::string msg) : msg(msg) {}

	virtual ~QueueException() throw() {}
	virtual const char* what() const throw() {
		return msg.c_str();
	}
};

template <class T>
class Queue {
private:
	int size;
	int front;
	int rear;
	T* qArr;

public:
	Queue() : size(-1), front(0), rear(0) {}
	Queue(int size) : size(size), front(0), rear(0) {
		qArr = new T[size];
	}

	bool isFull() { return (rear == (size - 1)); }
	bool isEmpty() { return (front == rear); }

	void enqueue(T data) {
		try {
			if (isFull())
				throw(QueueException("Queue is Full."));
			else {
				qArr[rear++] = std::move(data);
			}
		}
		catch (const QueueException& me) {
			std::cout << me.what() << std::endl;
		}
	}

	T dequeue() {
		try {
			if (isEmpty()) {
				throw(QueueException("Queue is Empty."));
				return NULL;
			}
			else {
				T temp;
				temp = qArr[front++];
				return temp;
			}
		}
		catch (const QueueException& me) {
			std::cout << me.what() << std::endl;
		}
	}

	void display() {
		for (int i = front; i < rear; i++) {
			std::cout << qArr[i] << " ";
		}
		std::cout << std::endl;
	}

	~Queue() {
		delete[] qArr;
	}
};

template <class T>
class QueueStk {
private:
	int size;
	Stack<T> enqeueStk = Stack<T>(size);
	Stack<T> deqeueStk = Stack<T>(size);

public:
	QueueStk() : size(-1) {}
	QueueStk(int size) : size(size) {}

	void enqueue(T data) {
		enqeueStk.push(data);
	}

	T dequeue() {
		if (deqeueStk.isEmpty())
			while (!(enqeueStk.isEmpty()))
				deqeueStk.push(enqeueStk.pop());
		return deqeueStk.pop();
	}

	void display() {
		deqeueStk.display();
		enqeueStk.display();
	}

};

#endif // !_QUEUE_H_

