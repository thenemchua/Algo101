#include "graph.hpp"

Graph::Graph() : vertexMap() {
}

// Copy constructor
Graph::Graph(Graph const& other) : vertexMap() {
	// Copy the vertices
	std::unordered_map<int, Vertex*> otherVertexMap = other.getVertexMap();
	for(auto const& keyValue : otherVertexMap) {
		vertexMap[keyValue.first] = new Vertex(*keyValue.second);
	}
}

// Move constructor
Graph::Graph(Graph&& other) : vertexMap() {
	std::unordered_map<int, Vertex*> otherVertexMap = other.getVertexMap();
	for(auto keyValue : otherVertexMap) {
		vertexMap[keyValue.first] = keyValue.second;
	}
}

// Copy assignment operator
Graph& Graph::operator=(const Graph& other) {
	if(&other != this) {
		for(auto keyValue : vertexMap) {
			delete vertexMap[keyValue.first];
		}
		for(auto const& keyValue : other.getVertexMap()) {
			vertexMap[keyValue.first] = new Vertex(*keyValue.second);
		}
	}
	return *this;
}

// Move assignment operator
Graph& Graph::operator=(Graph&& other) {
	if(&other != this) {
		for(auto keyValue : vertexMap) {
			delete vertexMap[keyValue.first];
		}
		for(auto& keyValue : other.getVertexMap()) {
			vertexMap[keyValue.first] = keyValue.second;
			keyValue.second = nullptr;
		}
	}
	return *this;
}

// Destructor
Graph::~Graph() {
	// Delete all vertices (because manually allocated)
	for(std::pair<int, Vertex*> p : vertexMap) {
		delete p.second;
	}
}

Vertex& Graph::operator[](int index) {
	return *(vertexMap[index]);
}

void Graph::addVertex(int name) {
	vertexMap[name] = new Vertex(name);
}

void Graph::addEdge(int sourceName, int destinationName, int weight) {
	Edge e(weight, *vertexMap[destinationName]);
	vertexMap[sourceName]->addAdjacent(e);
}

std::unordered_map<int, Vertex*> Graph::getVertexMap() const {
	return vertexMap;
}

int Graph::size() const {
	return vertexMap.size();
}
