#include <stdexcept>

#include "question1.hpp"

namespace question1 {

	std::pair<int, int> maxSubArray(std::vector<int> tab) {
		int size = tab.size();
		// T[d:f], de somme s, est le premier sous-tableau de T[0:n], de somme maximum.
		int d = 0 , f = 0, s = tab[0],
		    i = 1, dp = i, somme = 0;

		for(i = 1 ; i < size ; ++i) {
			if(somme < 0) {
				somme = 0;
				dp=i;
			}

			somme += tab[i];

			if(somme > s) {
				s = somme;
				d = dp;
				f = i+1;	
			}
		}

		std::pair<int, int> df(d,f);
		return df;
	}

}
