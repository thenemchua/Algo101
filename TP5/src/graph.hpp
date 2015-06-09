#ifndef _GRAPH_HPP_
#define _GRAPH_HPP_

#include <unordered_map>
#include "vertex.hpp"

class Graph {
public:
	Graph();

	// Rule of five

	// Copy constructor
	Graph(Graph const& other);
	// Move constructor
	Graph(Graph&& other);
	// Copy assignment operator
	Graph& operator=(const Graph& other);
	// Move assignment operator
	Graph& operator=(Graph&& other);
	// Destructor
	~Graph();

	Vertex & operator[](int const index);
	void addVertex(int name);
	void addEdge(int sourceName, int destinationName, int weight);
	std::unordered_map<int, Vertex*> getVertexMap() const;
	int size() const;

private:
	std::unordered_map<int, Vertex*> vertexMap;
};

#endif
