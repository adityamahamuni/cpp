#pragma once
#ifndef _POLYNOMIAL_H_
#define _POLYNOMIAL_H_

#include<iostream>

template <class T>
class Term {
	T coeff;
	T exp;
};


template <class T>
class Polynomial {
private:
	int n;
	Term<T>* terms;

public:
	friend std::istream& operator>>(std::istream& is, Polynomial<T>& p);
	friend std::ostream& operator<<(std::ostream& os, const Polynomial<T> p);

	Polynomial<T> operator+(const Polynomial<T> p);
};
#endif // !_POLYNOMIAL_H_

