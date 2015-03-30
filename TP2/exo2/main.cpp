#include <iostream>
#include <vector>

/**
 *	Cette fonction renvoie le premier plus long sous-tableau constant
 *
 *	Invariant : I(d, f, d', k) 
 *	⇒ tab[d :f] est le pplstc du tableau tab [0:k]
 *	⇒ tab[d':k] est le suffixe constant le plus long du tableau tab [0:k]
 *
 *	Initialisation :
 *	d = f = d' = 0;
 *	Si n ≠ 0
 *		k = 1
 *	Sinon
 *		k = 0
 *
 *	Arrêt :
 *	k == n
 *	(n est la longeur de tab)
 *
 *	Progression :
 *	I(d, f, d', k) ∧ tab[k + 1] = tab[d'] ∧ d' - k + 1 > f - d ⇒ I(d', k+1, d' , k+1) (1)
 *	I(d, f, d', k) ∧ tab[k + 1] = tab[d'] ∧ d' - k + 1 ≤ f - d ⇒ I(d , f  , d' , k+1) (2)
 *	I(d, f, d', k) ∧ tab[k + 1] ≠ tab[d']                      ⇒ I(d , f  , k+1, k+1) (3)
 */

std::pair<int, int> pplstc(std::vector<int> tab) {

	int size = tab.size(); // n est la longeur de tab

	// Initialisation //

	std::pair<int, int> pplstcIndices(0,0);	

	if(size == 0)
		return pplstcIndices;

	pplstcIndices.second = 1;
	std::pair<int, int> currentIndices = pplstcIndices;
	int constant = tab[0];

	// Progression //
	for(int i = 1 ; i < size ; ++i) {
		if(tab[i] == constant) {
			currentIndices.second = i+1;
			if(currentIndices.second - currentIndices.first > pplstcIndices.second - pplstcIndices.first) { 
				// Cas (1)
				pplstcIndices = currentIndices;
			} // Sinon Cas (2)
		} else { 
			// Cas (3)
			constant = tab[i];
			currentIndices.first = i;
			currentIndices.second = i+1;
		}
	}

	return pplstcIndices;
}

int main(int argc, char const *	argv[]) {
	std::vector<int> tab{1,1, 2,2,2,2,2, 3,3,3,3,3, 4,4,4,4};
	std::pair<int, int> result = pplstc(tab);
	
	std::cout << result.first << ", " << result.second << std::endl;

	return 0;
}
