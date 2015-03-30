#include <iostream>

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
	std::vector<int> tab{5,4,3,2,1,2,3,4,5,4,3,2,1};
	std::cout << tab << std::endl;
	std::cout << "Minimum récursif :" << std::endl;
	std::cout << question1::min(tab, 0, tab.size()) << std::endl;
	std::cout << "Affichage récursif :" << std::endl;
	question2::print(tab, 0, tab.size());
	std::cout << "Affichage & l'envers récursif :" << std::endl;
	question3::envers(tab, 0, tab.size());
}
