#include "edge.hpp"

Edge::Edge(const int weight, Vertex const& destination)
	: weight(weight), destination(&destination) {
}

int Edge::getWeight() {
	return weight;
}
