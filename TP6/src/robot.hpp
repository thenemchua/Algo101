#ifndef _ROBOT_HPP_
#define _ROBOT_HPP_

#include "map.hpp"

class Robot {
public:
	Robot(Map const& map);

	float getEastCost() const __attribute__((pure));
	float goEast();
	float getNorthCost() const __attribute__((pure));
	float goNorth();
	float getNorthEastCost() const __attribute__((pure));
	float goNorthEast();

	float getTotalCost() const __attribute__((pure));

	int getCoordX() const __attribute__((pure));
	int getCoordY() const __attribute__((pure));
	Map const& getMap() const __attribute__((pure));

private:
	int coordX;
	int coordY;
	float totalCost;
	Map const& map;
};

#endif
