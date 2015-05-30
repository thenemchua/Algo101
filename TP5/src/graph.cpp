#include "graph.hpp"

Graph::Graph() : vertexMap() {
}

Vertex& Graph::operator[](int const index) {
	return *(vertexMap[index]);
}

void Graph::addVertex(Vertex& v) {
	vertexMap[v.getValue()] = &v;
}
