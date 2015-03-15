#include "isInVector.hpp"

/**
 * Invariant  I(i,j) : T[i] ≤ number < T[j]
 * Initialisation : Si number est inférieur à la borne inférieure ou supérieur
 * à la borne supérieure, alors il n'est pas dans le tableau, sinon on pose i=0
 * et j=n.
 *
 * Récurrence : Si number est inférieur à
 */
bool isInVector(int number, std::vector<int> const& tab) {
	if(number < tab[0] || number > tab[tab.size() - 1])
		return false;

	int i = 0;
	int j = tab.size();

	while(i != j) {
		int k = ((j-i)/2) + i;

		if(tab[k] == number)
			return true;
		else if(tab[k] > number)
			j = k;                 // T(i, k)
		else
			i = k;                 // T(k, i)
	}
	return false;
}
