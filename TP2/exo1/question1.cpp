#include "question1.hpp"

namespace question1 {

	bool isInVector(int number, std::vector<int> const& tab) {
		if(number < tab[0] || number > tab[tab.size() - 1])
			return false;

		int i = 0, j = tab.size();		// I(0, n)

		while(i != j) {
			int k = ((j-i)/2) + i;

			if(tab[k] == number)
				return true;
			else if(tab[k] > number)
				j = k;                 // T(i, i + (j-1)/2)
			else
				i = k;                 // T(i + (j-1)/2, i)
		}
		return false;
	}

	std::vector<int> intersect(std::vector<int> const& tab1, std::vector<int> const& tab2) {
		int n1 = tab1.size();

		std::vector<int> result;
		int i = 0;		                      // I(0,0)

		while(i < n1) {
			int num = tab1[i];
			if(isInVector(num, tab2)) {
				result.push_back(num);        // I(i+1,j)
			}
			++i;	                          // I(i,j)
		}
		return result;
	}

}
