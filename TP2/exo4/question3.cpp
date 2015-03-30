#include "question3.hpp"

namespace question3 {

	void envers(std::vector<int> const& tab, int begin, int end, bool first) {
		if(begin + 1 == end || begin == end) {
			std::cout << tab[begin] << " ";
			return;
		}

		question3::envers(tab, ((end-begin)/2)+begin, end, false);
		question3::envers(tab, begin,  ((end-begin)/2)+begin, false);
		if(first)
			std::cout << std::endl;
	}

	void envers(std::vector<int> const& tab, int begin, int end) {
		envers(tab, begin, end, true);
	}
}
