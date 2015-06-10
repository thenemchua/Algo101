#ifndef _UTIL_HPP_
#define _UTIL_HPP_

#include "graph.hpp"

#include <set>
#include <functional>

void forEach(Graph g, std::function<void(Vertex&, Edge&)> func);
void forEach(Vertex& root, std::function<void(Vertex&, Edge&)> func);
void forEach(Vertex& root, std::function<void(Vertex&, Edge&)> func, std::set<int>& doneVertices);


// Fold incrementally (Vertex 1, Vertex 2, etc…)
template<typename T>
T& foldIncr(Graph g, T& value, std::function<T&(Vertex const&, Edge const&, T&)> func) {
	int graphSize = g.size();
	for(int i = 0 ;  i < graphSize ; ++i) {
		value = func(g[i], value);
	}
	return value;
}

template<typename T>
T& fold(Graph g, T& value, std::function<T&(Vertex const&, Edge const&, T&)> func) {
	//std::set<int> doneVertices;
	return fold(g[0], value, func);
			//, doneVertices);
}

template<typename T>
T& fold(Vertex const& root, T& value, std::function<T&(Vertex const&, Edge const&, T&)> func) {
	for(Edge branch : root) {
		value = func(root, branch, value);
		value = fold(branch.getDestination(), value, func);
	}
	return value;
}

#endif
