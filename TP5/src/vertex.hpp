#ifndef _VERTEX_HPP_
#define _VERTEX_HPP_

#include <list>

class Vertex {
public:
	Vertex(const int value, std::list<Vertex> & adjacents);
	Vertex(const int value);
	Vertex();
	int getValue();

private:
	const int value;
	std::list<Vertex> adjacents;
};

#endif
