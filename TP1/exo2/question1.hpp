#ifndef _QUESTION1_HPP_
#define _QUESTION1_HPP_

#include <vector>
#include "isInVector.hpp"

namespace question1 {

	/**
	 * Calcule le nombre de pairs dans un tableau dont la somme est dans ce tableau en θ(n²×log(n))
	 *
	 * Invariante I(i,j) : S(i,j) = compteurs des paires cherchées
	 *
	 * Initialisation I(0,0) : S(0,0) = 0
	 *
	 * Condition d'arrêt : i = n ∧ j = n
	 *
	 * Récurrence : Si E[i] + E[j] ∈ E alors on ajoute 1 au compteur.
	 * Ensuite on incrémente i et j.
	 * 
	 */
	int pairsum(std::vector<int> const& tab);

}

#endif
