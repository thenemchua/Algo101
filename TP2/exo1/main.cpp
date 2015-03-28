#include <iostream>
#include "question1.hpp"

using question1::operator*;

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

	std::cout << A   << std::endl;
	std::cout << B   << std::endl;
	std::cout << A*B << std::endl;

	return 0;
}
