#include "local.hpp"
#include "printing.hpp"

#include <iostream>

namespace local {
	float minimize(Robot robot, Map const& map) {
		int size = map.getSize();

		std::cout << map << robot;
		while(robot.getCoordX() < size - 1 || robot.getCoordY() < size - 1) {
			if(robot.getNorthCost() < robot.getEastCost()) {
				if(robot.getNorthCost() < robot.getNorthEastCost()) {
					robot.goNorth();
				} else {
					robot.goNorthEast();
				}
			} else if(robot.getEastCost() < robot.getNorthEastCost()) {
				robot.goEast();
			} else {
				robot.goNorthEast();
			}
			std::cout << robot;
		}
		return robot.getTotalCost();
	}
}
