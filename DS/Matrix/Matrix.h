#pragma once
#include<iostream>
#include<cmath>
#include<math.h>
#include<vector>
#include<tuple>
#include<exception>


class MatrixException : virtual public std::exception{
	std::string msg;

public:
	MatrixException(std::string msg) : msg(msg){}

	virtual ~MatrixException() throw(){}
	virtual const char* what() const throw() {
		return msg.c_str();
	}
};

//template <class T>
class Matrix2D {
private:
	unsigned col_size;
	unsigned row_size;
	std::vector<std::vector<double>> Mat;

public:
	Matrix2D() : row_size(0), col_size(0), Mat({}) {};
	Matrix2D(unsigned row, unsigned col): row_size(row), col_size(col) {
		Mat.resize(row_size, std::vector<double>(col_size, 0));
	}
	Matrix2D(unsigned row, unsigned col, double value) : row_size(row), col_size(col) {
		Mat.resize(row_size, std::vector<double>(col_size, value));
	}

	void display() const;
	std::tuple<int, int> size() { return { this->row_size, this->col_size }; }

	int rows() const { return this->row_size; }
	int cols() const { return this->col_size; }

	Matrix2D operator + (const Matrix2D& );
	Matrix2D operator + (double);
	Matrix2D add(const Matrix2D& );

	Matrix2D operator - (const Matrix2D& );
	Matrix2D operator - (double);
	Matrix2D subtract(const Matrix2D&);

	Matrix2D operator * (const Matrix2D& );
	Matrix2D operator * (double);

	Matrix2D operator / (double);

	void zeros(int , int );
	void ones(int , int );

	Matrix2D transpose();
	Matrix2D dot(Matrix2D);
	Matrix2D cross(Matrix2D);
	double determinant();
	Matrix2D inverse();

	~Matrix2D() {};
};
