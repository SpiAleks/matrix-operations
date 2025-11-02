#include "../include/matrix.h"
#include <random>
#include <stdexcept>

Matrix::Matrix(int r, int c) : rows(r), cols(c) {
	data.resize(rows, std::vector<int>(cols, 0));
}

Matrix::Matrix(const std::vector<std::vector<int>>& input) {
	rows = input.size();
	if (rows > 0) {
		cols = input[0].size();
		data = input;
	} else {
		cols = 0;
	}
}

void Matrix::fillRandom() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(1, 10);

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			data[i][j] = dis(gen);
		}
	}
}

void Matrix::display() const {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			std::cout << data[i][j] << "\t";
		}
		std::cout << std::endl;
	}
}

Matrix Matrix::operator+(const Matrix& other) const {
	if (rows != other.rows || cols != other.cols) {
		throw std::invalid_argument("Matrics dimensions don't match for addition");
	}

	Matrix result(rows, cols);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			result.data[i][j] = data[i][j] + other.data[i][j];
		}
	}
	return result;
}

Matrix Matrix::operator*(const Matrix& other) const {
	if (cols != other.rows) {
		throw std::invalid_argument("Matrices dimensions don't match for multiplication");
	}

	Matrix result(rows, other.cols);
	for (int i = 0; i < rows; i++) {
		for (k = 0; k < cols; k++) {
			int temp = data[i][k];
			for (int j = 0; j < other.cols; j++) {
				result.data[i][j] += temp * other.data[k][j];
			}
		}
	}

	return result;
}
