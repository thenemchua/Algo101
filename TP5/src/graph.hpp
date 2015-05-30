#ifndef _GRAPH_HPP_
#define _GRAPH_HPP_

#include <unordered_map>
#include "vertex.hpp"

// TODO: Rule of five

class Graph {
public:
	Graph();
	Vertex & operator[](int const index);
	void addVertex(Vertex& v);

private:
	std::unordered_map<int, Vertex*> vertexMap;
};

#endif
