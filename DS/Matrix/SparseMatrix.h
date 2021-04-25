#pragma once
#ifndef _SPARSEMATRIX_H_
#define _SPARSEMATRIX_H_

#include<iostream>
#include<vector>

class Element {
public:
	int i;
	int j;
	int x;
};


class SparseMatrix {
private:
	int m;
	int n;
	int num;
	Element *ele;

public:
	SparseMatrix(int m, int n, int num) : m(m), n(n), num(num) {
		ele = new Element[this->num];
	};

	~SparseMatrix() {
		delete[] ele;
	}

	void read();
	void display() const;

	friend std::istream& operator >> (std::istream& is, SparseMatrix& s);
	friend std::ostream& operator << (std::ostream& os, const SparseMatrix& s);

	SparseMatrix operator+(const SparseMatrix& );
};

#endif // !_SPARSEMATRIX_H_