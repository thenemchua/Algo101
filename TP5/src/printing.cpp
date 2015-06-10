#include "printing.hpp"

#include <iostream>
#include <algorithm>

std::function<void(Vertex& root, Edge& branch)> dotPrint() {
	return [] (Vertex& root, Edge& branch) {
		std::cout << "\t" << root.getValue()
		          << " -> " << branch.getDestination().getValue()
		          << " [label=" << branch.getWeight() << "]" << std::endl;
	};
}

std::function<void(Vertex& root, Edge& branch)> dotPrintColored(std::vector<int> revPath) {
	return [&revPath] (Vertex& root, Edge& branch) {

		int branchName = branch.getDestination().getValue();

		auto rootIterator = std::find(revPath.begin(), revPath.end(), root.getValue());
		if(rootIterator != revPath.end() && *(--rootIterator) == branchName) {
			std::cout << "\t" << root.getValue()
			          << " -> " << branch.getDestination().getValue()
			          << " [label=" << branch.getWeight() << ", color=red]" << std::endl;
		} else {
			std::cout << "\t" << root.getValue()
			          << " -> " << branch.getDestination().getValue()
			          << " [label=" << branch.getWeight() << "]" << std::endl;
		}
	};
}
