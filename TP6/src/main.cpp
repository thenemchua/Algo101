#include <iostream>

#include "map.hpp"
#include "robot.hpp"

int main(int argc, char const* argv[]) {
	if(argc != 2) {
		std::cout << "Usage: " << argv[0] << " n" << std::endl;
		return 64;
	}

	Map map(std::stoi(argv[1]));
	Robot robot(map);

	std::cout << robot.goEast() << std::endl;

	return 0;
}
