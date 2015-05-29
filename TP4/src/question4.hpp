#ifndef _QUESTION4_HPP_
#define _QUESTION4_HPP_

#include<boost/numeric/ublas/matrix.hpp>
#include<tuple>

using boost::numeric::ublas::matrix;

namespace question4 {

	matrix<int> computeMatrix(std::vector<std::tuple<int, int>> carnet, int slotLength);

}

#endif
