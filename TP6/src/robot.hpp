#ifndef _ROBOT_HPP_
#define _ROBOT_HPP_

#include "map.hpp"

class Robot {
public:
	Robot(Map const& map);

	float getEastCost() const;
	float goEast();
	float getNorthCost() const;
	float goNorth();
	float getNorthEastCost() const;
	float goNorthEast();

	float getTotalCost() const;

	int getCoordX() const;
	int getCoordY() const;
	Map const& getMap() const;

private:
	int coordX;
	int coordY;
	float totalCost;
	Map const& map;
};

#endif
