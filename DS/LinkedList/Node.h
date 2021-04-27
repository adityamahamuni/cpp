#pragma once
#ifndef _NODE_H_
#define _NODE_H_


template <class T>
class Node {
public:
	T data;
	Node<T>* next;
};

#endif // !_NODE_H_
