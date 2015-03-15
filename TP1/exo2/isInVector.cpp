#include "isInVector.hpp"

bool isInVector(int number, std::vector<int> const& tab) {
	if(number < tab[0] || number > tab[tab.size() - 1])
		return false;

	int i = 0, j = tab.size();

	while(i != j) {
		int k = ((j-i)/2) + i;

		if(tab[k] == number)
			return true;
		else if(tab[k] > number)
			j = k;
		else
			i = k;
	}
	return false;
}
