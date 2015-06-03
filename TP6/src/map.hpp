#ifndef _MAP_HPP_
#define _MAP_HPP_

#include <iostream>
#include <iomanip>

class Map {
public:
	Map(int size);
	float eastCost(int coordX, int coordY) const;
	float northCost(int coordX, int coordY) const;
	float northEastCost(int coordX, int coordY) const;
	int getSize() const;

private:
	int const size;
};

#endif
