#include "question2.hpp"

using boost::numeric::ublas::matrix;
using boost::numeric::ublas::identity_matrix;
using boost::numeric::ublas::prod;

namespace question2 {
/**
 *	Cette fonction permet d'élever une matrice A à la puissance B
 *
 *	Invariant : I(M,R,c) 
 *	⇒ A^b = M * A^c * R
 *
 *	Initialisation :
 *	M = R = Identité(n) (n est la taille de A)
 *	c = b
 *	
 *
 *	Arrêt :
 *	c == 1
 *
 *	Progression :
 *	I(M,c) ∧ c pair   ⇒ I(M*M,c/2) (1)
 *	I(M,c) ∧ c impair ⇒ I(M*M, (c-1)/2 , R * M) (2)
 */
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
		matrix<int> rest = identity_matrix<int>(rows);

		std::cout << rest << std::endl;

		while(exp > 1) {
			if(exp % 2 == 1) { // Si la puissance est impaire , on stocke le reste pour l'ajouter à la fin, Cas (2)
				rest *= result;
				--exp;
			}

			result *= result;

			exp /= 2;
		}

		return result * rest;
	}

}
