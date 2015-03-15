#include<iostream>
#include<vector>
#include<algorithm>

#include "estMembre.hpp"

std::ostream& operator<<(std::ostream& os, std::vector<int> const& tab) {
	for(auto const& el : tab) {
		os << el << " ";
	}
	return os;
}

int main(int argc, char const* argv[]) {

	if(argc <= 2) {
		std::cout << "Usage: " << argv[0] << " m n" << std::endl;
		return 64;
	}

	std::vector<int> tab1(std::stoi(argv[1]));
	std::vector<int> tab2(std::stoi(argv[2]));
	int i = 0;
	for(int& num : tab1) {
		num = i+=2;
	}

	i = 0;
	for(int& num : tab2) {
		num = i+=3;
	}

	std::cout << sortie(tab1, tab2) << std::endl;

	return 0;
}
