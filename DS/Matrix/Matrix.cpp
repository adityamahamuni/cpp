#include"Matrix.h"

void Matrix2D::display() const {
	std::cout << "[\n";
	for (unsigned i = 0; i < row_size; i++) {
		std::cout << "  [ ";
		for (unsigned j = 0; j < col_size; j++) {
			std::cout << Mat[i][j] << " ";
		}
		std::cout << " ]\n";
	}
	std::cout << "]\n";
}

Matrix2D Matrix2D::operator+(const Matrix2D& obj) {
	Matrix2D Res(row_size, col_size, 0.0);
	try {
		if ((row_size == obj.row_size) && (col_size == obj.col_size)) {
			for (unsigned i = 0; i < row_size; i++)
				for (unsigned j = 0; j < col_size; j++)
					Res.Mat[i][j] = this->Mat[i][j] + obj.Mat[i][j];
		}
		else {
			throw(MatrixException("Matrices are not of the same size."));
		}
	}
	catch (const MatrixException& me) {
		std::cout << me.what() << std::endl;
	}
	return Res;
}

Matrix2D Matrix2D::add(const Matrix2D& B) {
	Matrix2D Res(row_size, col_size, 0.0);
	try {
		if ((row_size == B.row_size) && (col_size == B.col_size)) {
			for (unsigned i = 0; i < row_size; i++)
				for (unsigned j = 0; j < col_size; j++)
					Res.Mat[i][j] = this->Mat[i][j] + B.Mat[i][j];
		}
		else {
			throw(MatrixException("Matrices are not of the same size."));
		}
	}
	catch (const MatrixException& me) {
		std::cout << me.what() << std::endl;
	}
	return Res;
}

Matrix2D Matrix2D::operator + (double scalar) {
	Matrix2D Res(row_size, col_size, 0.0);
	for (unsigned i = 0; i < row_size; i++)
		for (unsigned j = 0; j < col_size; j++)
			Res.Mat[i][j] = this->Mat[i][j] + scalar;
	return Res;
}

Matrix2D Matrix2D::operator-(const Matrix2D& obj) {
	Matrix2D Res(row_size, col_size, 0.0);
	try {
		if ((row_size == obj.row_size) && (col_size == obj.col_size)) {
			for (unsigned i = 0; i < row_size; i++)
				for (unsigned j = 0; j < col_size; j++)
					Res.Mat[i][j] = this->Mat[i][j] - obj.Mat[i][j];
		}
		else {
			throw(MatrixException("Matrices are not of the same size."));
		}
	}
	catch (const MatrixException& me) {
		std::cout << me.what() << std::endl;

	}
	return Res;
}

Matrix2D Matrix2D::subtract(const Matrix2D& B) {
	Matrix2D Res(row_size, col_size, 0.0);
	try {
		if ((row_size == B.row_size) && (col_size == B.col_size)) {
			for (unsigned i = 0; i < row_size; i++)
				for (unsigned j = 0; j < col_size; j++)
					Res.Mat[i][j] = this->Mat[i][j] - B.Mat[i][j];
		}
		else {
			throw(MatrixException("Matrices are not of the same size."));
		}
	}
	catch (const MatrixException& me) {
		std::cout << me.what() << std::endl;
	}
	return Res;
}

Matrix2D Matrix2D::operator - (double scalar) {
	Matrix2D Res(row_size, col_size, 0.0);
	for (unsigned i = 0; i < row_size; i++)
		for (unsigned j = 0; j < col_size; j++)
			Res.Mat[i][j] = this->Mat[i][j] - scalar;
	return Res;
}

Matrix2D Matrix2D::operator * (double scalar) {
	Matrix2D Res(row_size, col_size, 0.0);
	for (unsigned i = 0; i < row_size; i++)
		for (unsigned j = 0; j < col_size; j++)
			Res.Mat[i][j] = this->Mat[i][j] * scalar;
	return Res;
}

Matrix2D Matrix2D::operator / (double scalar) {
	Matrix2D Res(row_size, col_size, 0.0);
	for (unsigned i = 0; i < row_size; i++)
		for (unsigned j = 0; j < col_size; j++)
			Res.Mat[i][j] = this->Mat[i][j] / scalar;
	return Res;
}

void Matrix2D::zeros(int row, int col) {
	Mat.clear();
	Mat.resize(row);
	for (unsigned i = 0; i < Mat.size(); i++) {
		Mat[i].resize(col, 0);
	}
}

void Matrix2D::ones(int row, int col) {
	Mat.clear();
	Mat.resize(row);
	for (unsigned i = 0; i < Mat.size(); i++) {
		Mat[i].resize(col, 1);
	}
}

Matrix2D Matrix2D::transpose() {
	Matrix2D Transpose(row_size, col_size, 0.0);
	for (unsigned i = 0; i < col_size; i++)
		for (unsigned j = 0; j < row_size; j++)
			Transpose.Mat[i][j] = this->Mat[j][i];

	return Transpose;
}