#include "util.hpp"

void forEach(Graph graph, std::function<void(Vertex&, Edge&)> func) {
	std::set<int> doneVertices;
	forEach(graph[0], func, doneVertices);
}


void forEach(Vertex& root, std::function<void(Vertex&, Edge&)> func) {
	std::set<int> doneVertices;
	forEach(root, func, doneVertices);
}

void forEach(Vertex& root, std::function<void(Vertex&, Edge&)> func, std::set<int>& doneVertices) {
	const int rootName = root.getValue();
	if(doneVertices.find(rootName) == doneVertices.end()) {

		doneVertices.insert(rootName);

		//std::cerr << "Inserting: " << rootName << std::endl;

		for(Edge branch : root) {

			//std::cerr << "Doing: " <<  rootName << " -> " << branch.getDestination().getValue() << std::endl;

			func(root, branch);

			forEach(branch.getDestination(), func, doneVertices);
		}
	}
}
