#ifndef _ROBOT_HPP_
#define _ROBOT_HPP_

#include "map.hpp"

class Robot {
public:
	Robot(Map const& map);
	float goEast();
	float goNorth();
	float goNorthEast();

private:
	int coordX;
	int coordY;
	float totalCost;
	Map const& map;
};

#endif
