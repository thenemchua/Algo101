#include <iostream>

#include "graph.hpp"
#include "vertex.hpp"

std::ostream& operator<<(std::ostream& os, Vertex v) {
	os << "(" << v.getValue() << ")";
	return os;
}

int main() {
	Graph g;
	for(int i = 0 ; i <= 13 ; ++i) {
		Vertex* v = new Vertex(i);
		g.addVertex(*v);
	}

	std::cout << g[1] << std::endl;
}
