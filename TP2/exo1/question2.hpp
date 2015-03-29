#ifndef _QUESTION2_HPP_
#define _QUESTION2_HPP_

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>

using boost::numeric::ublas::matrix;

namespace question2 {

	/**
	 * Effectue un produit de matrices d'entiers.
	 */
	matrix<int> pow(matrix<int> const& base, int exp);

}

#endif
