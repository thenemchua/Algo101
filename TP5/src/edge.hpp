#ifndef _EDGE_HPP_
#define _EDGE_HPP_

#include "vertex.hpp"

class Edge {
public:
	Edge(const int weight, Vertex const& destination);
	int getWeight();

private:
	int weight;
	Vertex const* destination;
};

#endif
