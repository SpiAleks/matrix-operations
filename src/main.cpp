#include "../include/matrix.h"
#include <iostream>

int main() {
	std::cout << "=== Matrix Operations Program ===" << std::endl;

	Matrix A(2, 3);
	Matrix B(2, 3);
	Matrix C(3, 2);

	A.fillRandom();
	B.fillRandom();
	C.fillRandom();

	std::cout << "Matrix A:" << std::endl;
	A.display();

	std::cout << "Matrix B:" << std::endl;
	B.display();

	std::cout << "Matrix C:" << std::endl;
	C.display();

	try {
		std::cout << "A + B:" << std::endl;
		Matrix D = A + B;
		D.display();
	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	try {
		std::cout << "A * C:" << std::endl;
		Matrix E = A * C;
		E.display();
	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
}
