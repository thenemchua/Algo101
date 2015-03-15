#ifndef _QUESTION2_HPP_
#define _QUESTION2_HPP_

#include<vector>

namespace question2 {

	/**
	 * Calcule l'intersection de deux tableaux croissants en θ(n₁+n₂).
	 * Invariante I(i,j,k): E[0:i] ∪ (E₁[j:n₁] ∩ E₂[k:n₂]) = E₁[0:n₁] ∩ E₂[0:n₂]
	 *
	 * Initialisation : I(0,0,0) : E[0:0] ∪ (E₁[0:n₁] ∩ E₂[0:n₂]) = E₁[0:n₁] ∩ E₂[0:n₂]
	 *
	 * Récurrence : Si E₁[i] = E₂[j] alors insère cet élément dans le tableau E.
	 * Sinon, si E₁[i] > E₂[j], alors on incrémente i. Sinon E₁[i] < E₂[j] et
	 * on incrémente j.
	 *
	 */
	std::vector<int> intersect(std::vector<int> const& tab1, std::vector<int> const& tab2);

}

#endif
