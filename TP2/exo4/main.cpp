#include <iostream>
#include <random>

#include "question1.hpp"
#include "question2.hpp"
#include "question3.hpp"

std::ostream& operator<<(std::ostream& os, std::vector<int> const& tab) {
	for(auto const& el : tab) {
		os << el << " ";
	}
	return os;
}

int main(int argc, char const* argv[]) {

	if(argc == 1) {
		std::cout << "Usage: " << argv[0] << " n" << std::endl;
		return 63;
	}

	std::default_random_engine random_engine((std::random_device()()));
	std::uniform_int_distribution<int> distribution(-100, 100);

	distribution(random_engine);

	std::vector<int> tab(std::stoi(argv[1]));

	for(int& el : tab) {
		el = distribution(random_engine);
	}

	std::cout << tab << std::endl;
	std::cout << "Minimum récursif :" << std::endl;
	std::cout << question1::min(tab, 0, tab.size()) << std::endl;
	std::cout << "Affichage récursif :" << std::endl;
	question2::print(tab, 0, tab.size());
	std::cout << "Affichage & l'envers récursif :" << std::endl;
	question3::envers(tab, 0, tab.size());
}
