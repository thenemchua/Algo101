#include "robot.hpp"

Robot::Robot(Map const& map) : coordX(0), coordY(0), totalCost(0), map(map) {
}

float Robot::getEastCost() const {
	return map.eastCost(coordX, coordY);
}

// Va à l'est et calcul le sous-total du poids
float Robot::goEast() {
	float cost = map.eastCost(coordX, coordY);
	coordX++;
	totalCost += cost;
	return cost;
}

float Robot::getNorthCost() const {
	return map.northCost(coordX, coordY);
}

// Va au nord et calcul le sous-total du poids
float Robot::goNorth() {
	float cost = map.northCost(coordX, coordY);
	coordY++;
	totalCost += cost;
	return cost;
}

float Robot::getWestCost() const {
	return map.westCost(coordX, coordY);
}

// Va à l'ouest et calcul le sous-total du poids
float Robot::goWest() {
	float cost = map.westCost(coordX, coordY);
	coordX--;
	totalCost += cost;
	return cost;
}

float Robot::getSouthCost() const {
	return map.southCost(coordX, coordY);
}

// Va au sud et calcul le sous-total du poids
float Robot::goSouth() {
	float cost = map.southCost(coordX, coordY);
	coordY--;
	totalCost += cost;
	return cost;
}

float Robot::getTotalCost() const {
	return totalCost;
}

int Robot::getCoordX() const {
	return coordX;
}

int Robot::getCoordY() const {
	return coordY;
}

Map const& Robot::getMap() const {
	return map;
}
