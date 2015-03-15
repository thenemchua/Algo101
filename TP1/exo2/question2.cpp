#include <iostream>

#include "question2.hpp"

namespace question2 {

	int backwardSearch(int const& number, std::vector<std::vector<int>> const& tab) {
		int tabSize = tab.size(), subTabSize = tab[0].size();
		int i = 0, j = subTabSize - 1;
		int searchCount = 0;

		while(true) {
			int currentNumber = tab[i][j];
			if(currentNumber == number) {
				++searchCount;
				if(i != subTabSize - 1)
					++i;
				else if(j != 0)
					++j;
				else
					break;
			} else if(currentNumber > number) {
				if(j != 0)
					--j;
				else
					break;
			} else {
				if(i != tabSize - 1)
					++i;
				else
					break;
			}
		}

		return searchCount;
	}

	int pairsum(std::vector<int> const& tab) {
		int result  = 0,
		    tabSize = tab.size();

		std::vector<std::vector<int>> sums(tabSize);

		for(int i = 0 ; i < tabSize ; ++i) {
			sums[i] = std::vector<int>(tabSize);
			for(int j = 0 ; j < tabSize ; ++j) {
				sums[i][j] = tab[i] + tab[j];
			}
		}

		for(int i = 0 ; i < tabSize ; ++i) {
			result += backwardSearch(tab[i], sums);
		}

		return result;
	}

}
