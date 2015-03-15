#include "question2.hpp"

namespace question2 {

	std::vector<int> intersect(std::vector<int> const& tab1, std::vector<int> const& tab2) {
		int i1 = 0, i2 = 0,
		    m = tab1.size(), n = tab2.size();

		std::vector<int> result;

		while(i1 < m && i2 < n) {
			int num1 = tab1[i1],
			    num2 = tab2[i2];

			if(num1 == num2) {
				result.push_back(num1);
				++i1;
				++i2;
			} else if(num1 > num2) {
				++i2;
			} else if(num1 < num2) {
				++i1;
			} else {
				++i1;
				++i2;
			}

		}
		return result;
	}

}
