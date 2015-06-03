#include "robot.hpp"

Robot::Robot(Map const& map) : coordX(0), coordY(0), totalCost(0), map(map) {
}

float Robot::goEast() {
	coordX++;
	int cost = map.eastCost(coordX, coordY);
	return cost;
}

float Robot::goNorth() {
	coordX++;
	float cost = map.northCost(coordX, coordY);
	return cost;
}

float Robot::goNorthEast() {
	coordX++;
	float cost = map.northEastCost(coordX, coordY);
	return cost;
}
