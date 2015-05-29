#ifndef _QUESTION5_HPP_
#define _QUESTION5_HPP_

#include<boost/numeric/ublas/matrix.hpp>
#include<vector>

using boost::numeric::ublas::matrix;

namespace question5 {

	std::vector<int> computeSpots(matrix<int> dynaMat);

}

#endif
