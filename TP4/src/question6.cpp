#include "question6.hpp"

using boost::numeric::ublas::matrix;

namespace question6 {

	std::vector<int> computeSpots(matrix<int> dynaMat) {
		std::vector<int> spots;
		int row(dynaMat.size1() - 1),
		    col(dynaMat.size2() - 1);

		bool goUp = true;

		while(row > 0) {
			if(col == 0) {
				break;
			}

			int nextRow = (goUp) ? row-1 : row,
			    nextCol = (!goUp)? col-1 : col;

			if(dynaMat(row, col) > dynaMat(nextRow, nextCol)) {
				if(goUp) {
					spots.push_back(row - 1);
				}

				// Invert direction and re-establish the next cell
				goUp = not goUp;
				nextRow = (goUp) ? row-1 : row;
				nextCol = (!goUp)? col-1 : col;
			}

			row = nextRow;
			col = nextCol;
		}
		return spots;
	}

}
