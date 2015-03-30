#include <iostream>

#include "question1.hpp"
#include "question2.hpp"
#include "question3.hpp"

using question1::operator*;

std::ostream& operator<<(std::ostream& os, boost::numeric::ublas::matrix<int> mat) { // Fonction permettant l'impression d'une matrice
	int rows = mat.size1(),
	    cols = mat.size2();

	for(int row = 0 ; row < rows ; ++row) {
		for(int col = 0 ; col < cols ; ++col) {
			if(col == 0) {
				if(row == 0) {
					os << "⎡ ";
				} else if(row == rows - 1) {
					os << "⎣ ";
				} else {
					os << "⎢ ";
				}
			}

			os << mat(row, col) << "\t";

			if(col == cols - 1) {
				if(row == 0) {
					os << "⎤" << std::endl;
				} else if(row == rows - 1) {
					os << "⎦" << std::endl;
				} else {
					os << "⎥" << std::endl;
				}
			}
		}
	}

	return os;
}

int main (int argc, char const* argv[]) {
	
	boost::numeric::ublas::matrix<int> A(3,3);
	boost::numeric::ublas::matrix<int> B(3,3);

	int rows = A.size1();
	int cols = A.size2();

	for(int i = 0 ; i < rows ; ++i) {
		for(int j = 0 ; j < cols ; ++j) {
			A(i, j) = i + j;
			B(i, j) = i - j;
		}
	}

	std::cout << "A =" << std::endl << A   << std::endl;
	std::cout << "B =" << std::endl << B   << std::endl;
	std::cout << "A*B =" << std::endl << A*B << std::endl;
	std::cout << static_cast<boost::numeric::ublas::matrix<int>>(boost::numeric::ublas::prod(A, B)) << std::endl;
	std::cout << "A³ =" << std::endl << question2::pow(A, 3) << std::endl;

	for(int i = 0 ; i <= 30 ; ++i) {
		std::cout << "F_" << i << " = " << question3::fibonacci(i) << std::endl;
	}

	return 0;
}
