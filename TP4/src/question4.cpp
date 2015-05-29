#include "question4.hpp"

using boost::numeric::ublas::matrix;

namespace question4 {

	matrix<int> allonsY(std::vector<std::tuple<int, int>> carnet,
	                    int slotLength) {
		int spotCount(carnet.size()); // K

		matrix<int> dynaMat(spotCount+1, slotLength+1);

		for(int i = 0 ; i <= slotLength ; ++i) {
			dynaMat(0, i) = 0;
		}

		for(int i = 1 ; i <= spotCount ; ++i) {

			int spotDuration, spotProfit;
			std::tie(spotDuration, spotProfit) = carnet[i-1];

			for(int j = 0 ; j <= slotLength ; j++) {
				if(spotDuration <= j) {
					dynaMat(i,j) = std::max(dynaMat(i-1,j-spotDuration) + spotProfit,
							dynaMat(i-1,j));
				} else {
					dynaMat(i,j) = dynaMat(i-1,j);
				}
			}
		}

		return dynaMat;
	}

}
