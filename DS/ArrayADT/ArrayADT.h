#pragma once

#include<iostream>

#include<stdio.h>
#include<stdlib.h>


template<class T>

class Array {
private:
	T* A;
	int size;
	int length;

public:
	Array() {
		size = 10;
		length = 0;
		A = new T[size];
	}

	Array(int sz) {
		size = sz;
		length = 0;
		A = new T[size];
	}

	~Array() { delete[]A; }

	void displayArr();
	void Append(T x);
	void Insert(int index, T x);
	T Delete(int index);

	int LinearSearch(int key);
	int BinarySearch(int key);

	int get(int index);
	void set(int index, T x);
	int Max();
	int Min();
	int Sum();
	float Avg();

	void Reverse();
	bool isSorted();
	Array<T>* Merge(Array<T> arr2);
	void findDuplicates();
};