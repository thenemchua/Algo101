#ifndef _QUESTION2_HPP_
#define _QUESTION2_HPP_

#include <vector>

namespace question2 {

	/**
	 * Fait une recherche arrière dans un tableau à deux dimensions strictement
	 * croissant sur les deux dimensions.
	 */
	int backwardSearch(int const& number, std::vector<std::vector<int>> const& tab);

	/**
	 * Calcule le nombre de pairs dans un tableau dont la somme est dans ce tableau en θ(n²)
	 *
	 * Invariante I₁(i,j) : S[i,j] = E[i] + E[j]
	 *       puis I₂(i)   : S(i) = pairs cherchée contenant les éléments de E[0:i]
	 *
	 * Initialisation I₁(0,0) : S[0,0] = E[0] + E[0]
	 *           puis I₂(0)   : S(0) = ∅
	 *
	 * Condition d'arrêt : i = n ∧ j = n
	 *              puis : i = n
	 *
	 * Récurrence :
	 *  - On insère E[i] + E[j] dans S tout en parcourant le tableau à deux dimensions.
	 *  - On fait un recherche arrière dans le tableau de sommes sur l'élément
	 *    actuel (E[i]). On incrémente le compteur du résultat de la recherche.
	 *
	 */
	int pairsum(std::vector<int> const& tab);

}

#endif
