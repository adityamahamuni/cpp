#include<iostream>
#include<stdio.h>
#include<vector>

#include"Matrix.h"
#include"SparseMatrix.h"
#include"Polynomial.h"


int main() {

	SparseMatrix s1(5, 5, 5);
	SparseMatrix s2(5, 5, 5);

	std::cin >> s1;
	std::cin >> s2;

	SparseMatrix sum = s1 + s2;


	std::cout << "First Matrix : \n" << s1 << std::endl;
	std::cout << "Second Matrix : \n" << s2 << std::endl;
	std::cout << "Sum Matrix : \n" << sum << std::endl;

	Polynomial<int> p1;
	std::cin >> p1;

	std::cout << p1;

	return 0;
}
