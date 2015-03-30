#include "question1.hpp"

#include <limits>
#include <iostream>

namespace question1 {

	int min(std::vector<int> const& tab, int begin, int end) {
		if(begin == end)
			return std::numeric_limits<int>::max();

		if(begin + 1 == end)
			return tab[begin];

		int firstMin  = question1::min(tab, begin,  ((end-begin)/2)+begin),
		    secondMin = question1::min(tab, ((end-begin)/2)+begin, end);
		return (firstMin < secondMin) ? firstMin : secondMin;
	}

}
