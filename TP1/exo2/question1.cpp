#include <iostream>

#include "question1.hpp"

namespace question1 {

	int pairsum(std::vector<int> const& tab) {
		int result  = 0,
			tabSize = tab.size();

		int i = 0, j = 0;		                          // I(0,0)

		while(i < tabSize) {
			j = 0;
			while(j < tabSize) {
				if(isInVector(tab[i] + tab[j], tab)) {
					++result;
				}
				++j;                                      // I(i,j+1)
			}
			++i;	                                      // I(i+1,j)
		}
		return result;
	}

}
