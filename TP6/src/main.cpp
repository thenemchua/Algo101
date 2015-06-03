#include <iostream>
#include <limits>

#include "printing.hpp"
#include "local.hpp"
#include "map.hpp"
#include "robot.hpp"

int main(int argc, char const* argv[]) {
	if(argc != 2) {
		std::cout << "Usage: " << argv[0] << " n" << std::endl;
		return 64;
	}

	int size = std::stoi(argv[1]);

	Map map(size);
	Robot robot(map);

	float localCost = local::minimize(robot, map);

	std::cout << std::endl
	          << "Coût total (minimisation locale): "
	          << localCost << std::endl;

	return 0;
}
