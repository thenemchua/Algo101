#include "question2.hpp"

namespace question2 {

	void print(std::vector<int> const& tab, int begin, int end, bool first) {
		if(begin + 1 == end || begin == end) {
			std::cout << tab[begin] << " ";
			return;
		}

		question2::print(tab, begin,  ((end-begin)/2)+begin, false);
		question2::print(tab, ((end-begin)/2)+begin, end, false);
		if(first)
			std::cout << std::endl;
	}

	void print(std::vector<int> const& tab, int begin, int end) {
		print(tab, begin, end, true);
	}
}
