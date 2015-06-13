#ifndef _MAP_HPP_
#define _MAP_HPP_

#include <iostream>
#include <iomanip>

class Map {
public:
	explicit Map(int size);
	float eastCost(int coordX, int coordY) const __attribute__((pure));
	float northCost(int coordX, int coordY) const __attribute__((pure));
	float westCost(int coordX, int coordY) const __attribute__((pure));
	float southCost(int coordX, int coordY) const __attribute__((pure));
	int getSize() const __attribute__((pure));

private:
	int const size;
};

#endif
