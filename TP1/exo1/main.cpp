#include<iostream>
#include<vector>

#include "question1.hpp"
#include "question2.hpp"

std::ostream& operator<<(std::ostream& os, std::vector<int> const& tab) {
	for(auto const& el : tab) {
		os << el << " ";
	}
	return os;
}

/**
 * Cette fonction prends deux paramètres via la ligne de commande (hormis le
 * nom du programme même), à savoir la taille des tableaux E₁ et E₂.
 *
 * Ensuite, il crée ces tableaux et les initialise : E₁ avec des
 * multiples de 2 et E₂ avec des multiples de 3.
 * 
 * Il appelle enfin la méthode question2::intersect et affiche le tableau
 * résultant.
 *
 *
 * Exemple d'exécution :
 *	Paramètres : n₁=6 n₂=4
 * 		
 * 		tab1   = {2, 4, 6, 8, 10, 12}
 * 		tab2   = {3, 6, 9, 12}
 * 		result = ∅
 *
 *		i = 0, j = 0
 *		2 < 3 ⇒ i = 1, j = 0
 *		4 > 3 ⇒ i = 1, j = 1
 *		4 < 5 ⇒ i = 2, j = 1
 *		6 > 5 ⇒ i = 2, j = 2
 *		6 = 6 ⇒ i = 3, j = 3, result = {6}
 *		8 < 9 ⇒ i = 4, j = 3
 *		10> 9 ⇒ i = 4, j = 4
 *		10<12 ⇒ i = 5, j = 5
 *		12=12 ⇒ i = 6, i = 6, result = {6, 12}
 *
 *
 */
int main(int argc, char const* argv[]) {

	if(argc <= 2) {
		std::cout << "Usage: " << argv[0] << " m n" << std::endl;
		return 64;
	}

	std::vector<int> tab1(std::stoi(argv[1]));
	std::vector<int> tab2(std::stoi(argv[2]));

	int i = 0;
	for(int& num : tab1) {
		num = i+=2;
	}

	i = 0;
	for(int& num : tab2) {
		num = i+=3;
	}

	std::cout << question2::intersect(tab1, tab2) << std::endl;
	// question2::intersect(tab1, tab2);

	return 0;
}
