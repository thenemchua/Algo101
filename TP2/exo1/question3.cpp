#include "question3.hpp"

#include "question2.hpp"

using boost::numeric::ublas::matrix;
using boost::numeric::ublas::prod;

namespace question3 {
	/**
	 *	Cette fonction permet de trouver le nombre de fibonacci d'indice n, en un temps Θ(log n)
	 */
	int fibonacci(int n) {

		// Cas pathologiques
		if(n == 0) {
			return 0;
		} else if(n == 1) {
			return 1;
		}


		matrix<int> mult(2,2);
		// i = 1
		mult(0,0) = 1;
		mult(0,1) = 1;
		// i = 0
		mult(1,0) = 1;
		mult(1,1) = 0;

		// i ++
		mult = question2::pow(mult, n-1);

		return mult(0,0);
	}

}
