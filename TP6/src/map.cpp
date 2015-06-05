#include "map.hpp"

#include <cmath>
#include <limits>

Map::Map(int size) : size(size) {
}

float Map::eastCost(int coordX, int coordY) const {
	if(coordX >= size-1)
		return std::numeric_limits<float>::infinity();

	return coordY;
}

float Map::northCost(int coordX, int coordY) const {
	if(coordY >= size-1)
		return std::numeric_limits<float>::infinity();

	return coordX*coordX;
}

float Map::northEastCost(int coordX, int coordY) const {
	if(coordX >= size-1 || coordY >= size-1)
		return std::numeric_limits<float>::infinity();

	return std::pow(coordY, coordX);
}

int Map::getSize() const {
	return size;
}
