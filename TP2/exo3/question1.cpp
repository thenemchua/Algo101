#include <stdexcept>

#include "question1.hpp"

namespace question1 {

	std::pair<int, int> maxSubArray(std::vector<int> tab) {
		int tabSize = tab.size();

		if(tabSize == 0)
			throw new std::length_error("Empty vector");

		std::pair<int, int> maxSubArrayIndices(0,1),
		                    currentIndices(0,1);
		int max = tab[0],
		    sum = max;

		while(currentIndices.first < tabSize - 1 || currentIndices.second < tabSize) {
			if(currentIndices.second != tabSize) {
				int elBefore  = tab[currentIndices.first],
				    elAfter   = tab[currentIndices.second],
				    firstSum  = sum + elAfter,
				    secondSum = sum - elBefore;
				if(firstSum > secondSum || currentIndices.first == currentIndices.second - 1) {
					sum = firstSum;
					++currentIndices.second;
				} else {
					sum = secondSum;
					++currentIndices.first;
				}
			} else {
				sum = sum - tab[currentIndices.first];
				++currentIndices.first;
			}

			if(sum > max) {
				max = sum;
				maxSubArrayIndices = currentIndices;
			}
		}

		return maxSubArrayIndices;
	}

}
