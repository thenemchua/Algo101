#ifndef _QUESTION1_HPP_
#define _QUESTION1_HPP_

#include <vector>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>

namespace question1 {

	/**
	 * Effectue un produit de matrices d'entiers.
	 */
	matrix<int> produit(matrix<int> A, matrix<int> B);

}

#endif
