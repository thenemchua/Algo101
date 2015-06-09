#include "vertex.hpp"

Vertex::Vertex(const int value, std::list<Edge> & adjacents)
	: value(value), adjacents(adjacents) {
}

Vertex::Vertex(const int value)
	: value(value), adjacents() {
}

Vertex::Vertex()
	: value(0), adjacents() {
}

int Vertex::getValue() const {
	return value;
}

void Vertex::addAdjacent(Edge e) {
	adjacents.push_back(e);
}

Vertex::iterator Vertex::begin() {
	return adjacents.begin();
}

Vertex::iterator Vertex::end() {
	return adjacents.end();
}

Vertex::const_iterator Vertex::begin() const {
	return adjacents.begin();
}

Vertex::const_iterator Vertex::end() const {
	return adjacents.end();
}
