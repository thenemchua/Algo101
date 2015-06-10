#include "local.hpp"
#include "printing.hpp"

#include <iostream>

namespace local {
	float minimize(Robot robot, Map const& map) {
		bool interactive = isInteractive();

		int size = map.getSize();

		if(interactive) {
			std::cout << map << robot;
		} else {
			std::cout << "Chemin du robot: " << std::endl
			          << robot << " ";
		}

		// Tant que le robot n'est pas arrivé (condition d'arrêt)
		while(robot.getCoordX() < size - 1 || robot.getCoordY() < size - 1) {

			// Calcul du minimum + aller dans la direction du minimum
			// Le robot somme automatiquement lorsqu'il va dans une direction
			// (cf. Robot::goEast, Robot::goNorth, Robot::goNorthEast)
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

			// Afficher le robot
			if(interactive) {
				std::cout << robot;
			} else {
				std::cout << robot << " ";
			}
		}
		std::cout << std::endl;
		return robot.getTotalCost();
	}
}
