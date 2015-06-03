#ifndef _MAP_HPP_
#define _MAP_HPP_

class Map {
public:
	Map(int size);
	float eastCost(int coordX, int coordY) const;
	float northCost(int coordX, int coordY) const;
	float northEastCost(int coordX, int coordY) const;

private:
	int const size;
};

#endif
