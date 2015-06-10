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

	std::vector<int> smallestDates(14), // Contient pour tout noeud i (de 0 à 13) la durée du chemin le plus court menant à lui
	                 origins(14); // Contient pour tout noeud i (de 0 à 13) le noeud parent dans le chemin le plus court menant à lui. Kamoulox.

	// Remplissage des noeuds parents avec -1	
	std::fill(origins.begin(), origins.end(), -1);

	smallestDates[0] = 0;

	typedef std::tuple<std::vector<int>&, std::vector<int>&> Tabs; // Un Tabs contient le couple (smallestDates,origins)

	// calcSmallestDates est une fonction qui renvoie un Tabs et prend en paramètre (Vertex const& v, Edge const& e, Tabs& tabs)
	// Elle prend en paramètre un noeud, l'arc suivant et l'état actuel des chemins les plus courts (Sous la forme d'un Tabs)
	// Elle retourne le couple (smallestDates,origins) contenant le chemin le plus court menant au noeud suivant le noeud passé en paramètre
	// ,après analyse du chemin incluant le noeud passé en paramètre
	std::function<Tabs& (Vertex const&, Edge const&, Tabs&)> calcSmallestDates = [] (Vertex const& v, Edge const& e, Tabs& tabs) -> Tabs& {

		std::vector<int> smallestDates(14), origins(14);
		std::tie(smallestDates, origins) = tabs; //

		int vertexName = v.getValue(), // Numéro du noeud analysé
		    nextVertexName = e.getDestination().getValue(), // Numéro du noeud suivant
			contestantValue = smallestDates[vertexName] + e.getWeight(); // Valeur à comparer avec le meilleur poids actuel

		if(origins[nextVertexName] == -1
				|| smallestDates[nextVertexName] > contestantValue) { // Si il n'y a pas encore de plus court chemin OU si le nouveau chemin est meilleur
			// On définit le plus court chemin comme étant le nouveau
			smallestDates[nextVertexName] = contestantValue;
			origins[nextVertexName] = vertexName;
		}

		tabs = std::tie(smallestDates, origins); // On créé le nouveau tabs
		return tabs;
	};

	Tabs tabs = std::tie(smallestDates, origins);
	tabs = fold(g, tabs, calcSmallestDates);// On applique calcSmallestDates à tous les éléments.
	std::tie(smallestDates, origins) = tabs;

	// Impression du graphe (parcours à l'envers, depuis l'origine)
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
	// Fin de l'impression du graphe

	// =============================== Highest Dates ==========================

	std::vector<int> highestDates(14),
	                 maxOrigins(14);
	// Remplissage des noeuds parents avec -1	
	std::fill(maxOrigins.begin(), maxOrigins.end(), -1);

	highestDates[0] = 0;

	typedef std::tuple<std::vector<int>&, std::vector<int>&> Tabs; // Un Tabs contient le couple (smallestDates,origins)

	// calcHighestDates est une fonction qui renvoie un Tabs et prend en paramètre (Vertex const& v, Edge const& e, Tabs& tabs)
	//Elle prend en paramètre un noeud, l'arc suivant et l'état actuel des chemins les plus longs (Sous la forme d'un Tabs)
	// Elle retourne le couple (highestDates,origins) contenant le chemin le plus long menant au noeud suivant le noeud passé en paramètre
	// ,après analyse du chemin incluant le noeud passé en paramètre
	std::function<Tabs& (Vertex const&, Edge const&, Tabs&)> calcHighestDates = [] (Vertex const& v, Edge const& e, Tabs& tabs) -> Tabs& {

		std::vector<int> highestDates(14), maxOrigins(14);
		std::tie(highestDates, maxOrigins) = tabs;

		int vertexName = v.getValue(), // Numéro du noeud analysé
		    nextVertexName = e.getDestination().getValue(),  // Numéro du noeud suivant
			contestantValue = highestDates[vertexName] + e.getWeight(); // Valeur à comparer avec le meilleur poids actuel

		if(maxOrigins[nextVertexName] == -1
				|| highestDates[nextVertexName] < contestantValue) { // Si il n'y a pas encore de plus long chemin OU si le nouveau chemin est plus long
			// On définit le plus long chemin comme étant le nouveau
			highestDates[nextVertexName] = contestantValue;
			maxOrigins[nextVertexName] = vertexName;
		}

		tabs = std::tie(highestDates, maxOrigins);  // On créé le nouveau tabs
		return tabs;
	};

	tabs = std::tie(highestDates, maxOrigins);
	tabs = fold(g, tabs, calcHighestDates); // On applique calcHighestDates à tous les éléments.
	std::tie(highestDates, maxOrigins) = tabs;

	// Impression du graphe (parcours à l'envers, depuis l'origine)
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
	// Fin de l'impression du graphe
	return 0;
}
