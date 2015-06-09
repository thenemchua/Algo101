#ifndef _VERTEX_HPP_
#define _VERTEX_HPP_

#include <list>

// Dependency problem
class Vertex;

#include "edge.hpp"

class Vertex {
public:
	Vertex(const int value, std::list<Edge> & adjacents);
	Vertex(const int value);
	Vertex();
	int getValue() const;
	void addAdjacent(Edge e);

	 typedef std::list<Edge>::iterator iterator;
	 typedef std::list<Edge>::const_iterator const_iterator;
	 iterator begin();
	 iterator end();
	 const_iterator begin() const;
	 const_iterator end() const;

private:
	const int value;
	std::list<Edge> adjacents;
};

#endif
