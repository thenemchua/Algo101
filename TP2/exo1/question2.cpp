#include "question2.hpp"

using boost::numeric::ublas::matrix;
using boost::numeric::ublas::prod;

namespace question2 {

	matrix<int> operator*(matrix<int> const& A, matrix<int> const& B) {
		return static_cast<matrix<int>>(prod(A, B));
	}

	matrix<int>& operator*=(matrix<int>& A, matrix<int> const& B) {
		A = A*B;
		return A;
	}

	matrix<int> pow(matrix<int> const& base, int exp) {
		if(exp == 1) {
			return base;
		}

		int rows = base.size1(),
		    cols = base.size2();

		if(cols != rows)
			throw new std::length_error("Matrix must have a the right sizes to be powered");

		matrix<int> result = base;
		matrix<int> rest(rows, cols);

		for(int row = 0 ; row < rows ; ++row) {
			for(int col = 0 ; col < cols ; ++col) {
				if(row == col)
					rest(row, col) = 1;
				else
					rest(row, col) = 0;
			}
		}

		std::cout << rest << std::endl;

		while(exp > 1) {
			if(exp % 2 == 1) {
				rest *= result;
				--exp;
			}

			result *= result;

			exp /= 2;
		}

		return result * rest;
	}

}
