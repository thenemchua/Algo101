#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

std::ostream& operator<<(std::ostream& os, std::vector<int> const& tab) {
	for(auto const& el : tab) {
		os << el << " ";
	}
	return os;
}

int schism(std::vector<int> & tab, int begin, int end) {
	int k=begin,
	    jp=k+1;		                        // I(k,jp)
	while(jp != end) {
		if(tab[k] < tab[jp]) {	            // I(k,jp+1)
			jp++;                           // I(k,jp)
		} else {
			std::swap(tab[k+1], tab[jp]);
			std::swap(tab[k]  , tab[k+1]);  //  I(k+1 , jp+1)
			k++, jp++;
		}	                                // I(k,jp)
	}
	return k;	
}

int pieme(std::vector<int> & tab, int begin, int end, int p, std::default_random_engine & random_engine, std::uniform_int_distribution<int> & distribution) {
	if(end - begin == 1 && p == 1)
		return tab[begin];

	std::swap(tab[begin], tab[(distribution(random_engine)%(end-begin)) + begin]);

	int pivot = schism(tab, begin, end);
	pivot -= begin;

	if(p <= pivot - begin) {
		return pieme(tab, begin, pivot, p, random_engine, distribution);
	} else {
		return pieme(tab, pivot, end, p - (pivot - begin), random_engine, distribution);
	}
}

int pieme(std::vector<int> tab, int p) {
	// Initialize random system
	std::default_random_engine random_engine((std::random_device()()));
	std::uniform_int_distribution<int> distribution(0, tab.size());

	return pieme(tab, 0, tab.size(), p, random_engine, distribution);
}

int main(int argc, char const* argv[]) {

	if(argc != 3) {
		std::cout << "Usage: " << argv[0] << " n p" << std::endl;
		return 64;
	}

	std::default_random_engine random_engine((std::random_device()()));
	std::uniform_int_distribution<int> distribution(0, 100);

	distribution(random_engine);

	std::vector<int> tab(std::stoi(argv[1]));

	for(int& el : tab) {
		el = distribution(random_engine);
	}

	std::vector<int> sortedTab = tab;
	std::sort(sortedTab.begin(), sortedTab.end());

	std::cout << tab << std::endl;
	std::cout << "> " << sortedTab << std::endl;
	std::cout << pieme(tab, std::stoi(argv[2])) << std::endl;

	return 0;
}
