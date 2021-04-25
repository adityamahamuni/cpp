#include"SparseMatrix.h"

void SparseMatrix::read() {

	std::cout << "Enter Non-Zero Elements: \n";
	for (int i = 0; i < num; i++) {
		std::cin >> ele[i].i >> ele[i].j >> ele[i].x;
	}
}

void SparseMatrix::display() const{

	int k = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (ele[k].i == i && ele[k].j == j)
				std::cout << ele[k++].x << " ";
			else
				std::cout << "0 ";
		}
		std::cout << std::endl;
	}
}

std::istream& operator >> (std::istream& is, SparseMatrix& s) {
	std::cout << "Enter Non-Zero Elements: \n";
	for (int i = 0; i < s.num; i++) {
		std::cin >> s.ele[i].i >> s.ele[i].j >> s.ele[i].x;
	}
	return is;
}

std::ostream& operator << (std::ostream& os, const SparseMatrix& s)
{
	int k = 0;
	for (int i = 0; i < s.m; i++) {
		for (int j = 0; j < s.n; j++) {
			if (s.ele[k].i == i && s.ele[k].j == j)
				std::cout << s.ele[k++].x << " ";
			else
				std::cout << "0 ";
		}
		std::cout << std::endl;
	}
	return os;
}

SparseMatrix SparseMatrix::operator+(const SparseMatrix& s) {
	int i = 0, j = 0, k = 0;

	if (m != s.m || n != s.n)
		exit ;

	SparseMatrix* sum = new SparseMatrix(m, n, num + s.num);

	while (i < num && j < s.num) {
		if (ele[i].i < s.ele[j].i)
			sum->ele[k++] = ele[i++];
		else if(ele[i].i > s.ele[j].i)
			sum->ele[k++] = s.ele[j++];
		else {
			if (ele[i].j < s.ele[j].j)
				sum->ele[k++] = ele[i++];
			else if (ele[i].j > s.ele[j].j)
				sum->ele[k++] = s.ele[j++];
			else
			{
				sum->ele[k] = ele[i];
				sum->ele[k++].x = ele[i++].x + s.ele[j++].x;
			}
		}
	}

	for (; i < num; i++)
		sum->ele[k++] = ele[i];
	for (; j < s.num; j++)
		sum->ele[k++] = s.ele[j];

	sum->num = k;

	return *sum;
}