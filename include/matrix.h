#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <iostream>

class Matrix {
private:
	std::vector<std::vector<int>> data;
	int rows;
	int cols;

public:
	Matrix(int r, int c);
	Matrix(const std::vector<std::vector<int>>& input);

	void fillRandom();
	void display() const;

	Matrix operator+(const Matrix& other) const;
	Matrix operator*(const Matrix& other) const;
	double determinant() const;

	int getRows() const { return rows; }
	int getCols() const { return cols; }
};

#endif
