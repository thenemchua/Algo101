#ifndef _QUESTION1_HPP_
#define _QUESTION1_HPP_

#include<vector>

namespace question1 {

	/**
	 * Vérifie dans un tableau trié par ordre croissant si un élément y est présent.
	 *
	 * Invariante I(i,j): T[i] ≤ number < T[j]
	 *
	 * Initialisation : Si number est inférieur à la borne inférieure ou
	 * supérieur à la borne supérieure, alors il n'est pas dans le tableau,
	 * sinon on pose i=0 et j=n.
	 *
	 * Condition d'arrêt : i = j
	 *
	 * Récurrence : Si number est égal à l'élément actuel, alors on stoppe. Si
	 * number est inférieur à l'élément actuel, alors on recommence en prenant
	 * du début du sous tableau actuel jusqu'à sa moitié, soit
	 * I(i, i + (j-1)/2). Sinon, number est supérieur à l'élément
	 * actuel et on recommence en prenant de la moitié du sous-tableau jusqu'à
	 * sa fin, soit I(i + (j-1)/2, j).
	 *
	 */
	bool isInVector(int number, std::vector<int> const& tab);


	/**
	 * Calcule l'intersection de deux tableaux croissants en θ(n₁×log(n₂)).
	 *
	 * Invariante I(i,j) : E[0:i] = E₁[0:j] ∩ E2[0:j]
	 *
	 * Initialisation : I(0,0) : E[0:0] = E₁[0:0] ∩ E₂[0:0]
	 * 
	 * Condition d'arrêt : i = n₁
	 *
	 * Récurrence : Si le i-ème élément actuel dans le tableau E₁ est dans le E₂
	 * alors on le rajoute dans le tableau E. On incrémente ensuite j.
	 *
	 */
	std::vector<int> intersect(std::vector<int> const& tab1, std::vector<int> const& tab2);

}

#endif
