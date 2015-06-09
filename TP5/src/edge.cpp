#include "edge.hpp"

Edge::Edge(const int weight, Vertex& destination)
	: weight(weight), destination(destination) {
}

int Edge::getWeight() const {
	return weight;
}

Vertex& Edge::getDestination() const {
	return destination;
}
