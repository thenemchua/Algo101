#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <limits>

#include "graph.hpp"
#include "util.hpp"
#include "printing.hpp"

int main() {
    Graph g;

	for(int i = 0 ; i <= 13 ; ++i) {
		g.addVertex(i);
	}

	for(int i = 1 ; i <= 5 ; ++i) {
		// addEdge(child, parent, weight)
		g.addEdge(0, i, 0);
	}
	g.addEdge( 1,  6,  8);
	g.addEdge( 1,  7,  8);
	g.addEdge( 2,  7, 15);
	g.addEdge( 3,  8, 10);
	g.addEdge( 4,  8,  2);
	g.addEdge( 4, 10,  2);
	g.addEdge( 5, 11, 30);
	g.addEdge( 6,  9, 15);
	g.addEdge( 6, 11, 15);
	g.addEdge( 7,  9,  5);
	g.addEdge( 8,  9, 20);
	g.addEdge( 9, 10,  5);
	g.addEdge(10, 11,  3);
	g.addEdge(11, 12,  5);
	g.addEdge(12, 13, 20);

	std::cout << "digraph G {" << std::endl;

	std::cout << "\trankdir=LR" << std::endl;

	forEach(g, dotPrint());

	std::cout << "}" << std::endl;

	// =============================== Smallest Dates ==========================

	std::vector<int> smallestDates(14),
	                 origins(14);
	std::fill(smallestDates.begin(), smallestDates.end(), std::numeric_limits<int>::max());
	std::fill(origins.begin(), origins.end(), -1);

	smallestDates[0] = 0;

	typedef std::tuple<std::vector<int>&, std::vector<int>&> Tabs;

	std::function<Tabs& (Vertex const&, Edge const&, Tabs&)> calcSmallestDates = [] (Vertex const& v, Edge const& e, Tabs& tabs) -> Tabs& {

		std::vector<int> smallestDates(14), origins(14);
		std::tie(smallestDates, origins) = tabs;

		int vertexName = v.getValue(),
		    nextVertexName = e.getDestination().getValue(),
			contestantValue = smallestDates[vertexName] + e.getWeight();

		if(origins[nextVertexName] == -1
				|| smallestDates[nextVertexName] > contestantValue) {
			smallestDates[nextVertexName] = contestantValue;
			origins[nextVertexName] = vertexName;
		}

		tabs = std::tie(smallestDates, origins);
		return tabs;
	};

	Tabs tabs = std::tie(smallestDates, origins);
	tabs = fold(g, tabs, calcSmallestDates);
	std::tie(smallestDates, origins) = tabs;

	std::cout << std::endl
	          << "digraph G {" << std::endl;

	std::cout << "\trankdir=LR" << std::endl;

	std::vector<int> revPath;

	int i = *(origins.end()-1);
	revPath.push_back(origins.size() - 1);

	while(origins[i] != -1) {
		revPath.push_back(i);
		i = origins[i];
	}
	revPath.push_back(i);

	forEach(g, dotPrintColored(revPath));

	for(int i : revPath) {
		std::cout << "\t" << i << " [color=red]" << std::endl;
	}

	std::cout << "}" << std::endl;

	// =============================== Highest Dates ==========================

	std::vector<int> highestDates(14),
	                 maxOrigins(14);
	std::fill(highestDates.begin(), highestDates.end(), std::numeric_limits<int>::min());
	std::fill(maxOrigins.begin(), maxOrigins.end(), -1);

	highestDates[0] = 0;

	typedef std::tuple<std::vector<int>&, std::vector<int>&> Tabs;

	std::function<Tabs& (Vertex const&, Edge const&, Tabs&)> calcHighestDates = [] (Vertex const& v, Edge const& e, Tabs& tabs) -> Tabs& {

		std::vector<int> highestDates(14), maxOrigins(14);
		std::tie(highestDates, maxOrigins) = tabs;

		int vertexName = v.getValue(),
		    nextVertexName = e.getDestination().getValue(),
			contestantValue = highestDates[vertexName] + e.getWeight();

		if(maxOrigins[nextVertexName] == -1
				|| highestDates[nextVertexName] < contestantValue) {
			highestDates[nextVertexName] = contestantValue;
			maxOrigins[nextVertexName] = vertexName;
		}

		tabs = std::tie(highestDates, maxOrigins);
		return tabs;
	};

	tabs = std::tie(highestDates, maxOrigins);
	tabs = fold(g, tabs, calcHighestDates);
	std::tie(highestDates, maxOrigins) = tabs;

	std::cout << std::endl
	          << "digraph G {" << std::endl;

	std::cout << "\trankdir=LR" << std::endl;

	std::vector<int> maxRevPath;

	i = *(maxOrigins.end()-1);
	maxRevPath.push_back(maxOrigins.size() - 1);

	while(maxOrigins[i] != -1) {
		maxRevPath.push_back(i);
		i = maxOrigins[i];
	}
	maxRevPath.push_back(i);

	forEach(g, dotPrintColored(maxRevPath));

	for(int i : maxRevPath) {
		std::cout << "\t" << i << " [color=red]" << std::endl;
	}

	std::cout << "}" << std::endl;

	return 0;
}
