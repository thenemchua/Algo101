#include <iostream>

#include "regex.hpp"

int main(int argc, char const* argv[]) {
	if(argc != 3) {
		std::cout << "Usage : " << argv[0] << " string RegEx" << std::endl;
		return 64;
	}

	std::cout << (match(argv[1], argv[2])? "Match" : "Does not match") << std::endl;

	return 0;
}
