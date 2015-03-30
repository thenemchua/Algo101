#include <iostream>
#include <vector>
#include <random>

#include "question1.hpp"

std::ostream& operator<<(std::ostream& os, std::vector<int> const& tab) {
	for(auto const& el : tab) {
		os << el << " ";
	}
	return os;
}

int main (int argc, char const* argv[]) {

	if(argc == 1) {
		std::cout << "Usage: " << argv[0] << " n" << std::endl;
		return 64;
	}

	std::default_random_engine random_engine((std::random_device()()));
	std::uniform_int_distribution<int> distribution(-100, 100);

	distribution(random_engine);

	std::vector<int> tab(std::stoi(argv[1]));

	for(int& el : tab) {
		el = distribution(random_engine);
	}

	std::pair<int, int> maxSubArrayIndices = question1::maxSubArray(tab);

	// std::cout << tab << std::endl;
	std::cout << maxSubArrayIndices.first << ", " << maxSubArrayIndices.second << std::endl;

	return 0;
}
