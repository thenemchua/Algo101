#include <iostream>

#include "question1.hpp"

namespace question1 {

	int pairsum(std::vector<int> const& tab) {
		int result  = 0,
		    tabSize = tab.size();

		for(int i = 0 ; i < tabSize ; ++i) {
			for(int j = 0 ; j < tabSize ; ++j) {
				if(isInVector(tab[i] + tab[j], tab)) {
					++result;
				}
			}
		}
		return result;
	}

}
