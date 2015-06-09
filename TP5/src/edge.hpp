#ifndef _EDGE_HPP_
#define _EDGE_HPP_

// Dependency problem
class Edge;

#include "vertex.hpp"

class Edge {
public:
	Edge(const int weight, Vertex& destination);
	int getWeight() const;
	Vertex& getDestination() const;

private:
	int weight;
	Vertex& destination;
};

#endif
