#include "vertex.hpp"

Vertex::Vertex(const int value, std::list<Vertex> & adjacents)
	: value(value), adjacents(adjacents) {
}

Vertex::Vertex(const int value)
	: value(value), adjacents() {
}

Vertex::Vertex()
	: value(0), adjacents() {
}

int Vertex::getValue() {
	return value;
}
