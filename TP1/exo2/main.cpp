#include <iostream>
#include <vector>

#include "question1.hpp"
#include "question2.hpp"

int main(int argc, char const* argv[]) {
	if(argc == 1) {
		std::cout << "Usage: " << argv[0] << " n" << std::endl;
		return 64;
	}

	std::vector<int> tab(std::stoi(argv[1]));

	int i = 0;
	for(int& el : tab) {
		el = i;
		++i;
	}

	std::cout << question2::pairsum(tab) << std::endl;

	return 0;
}
