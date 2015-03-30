#include <iostream>
#include <vector>

std::pair<int, int> pplstc(std::vector<int> tab) {
	int size = tab.size();
	std::pair<int, int> pplstcIndices(0,0);

	if(size == 0)
		return pplstcIndices;

	pplstcIndices.second = 1;
	std::pair<int, int> currentIndices = pplstcIndices;
	int constant = tab[0];

	for(int i = 1 ; i < size ; ++i) {
		if(tab[i] == constant) {
			currentIndices.second = i+1;
			if(currentIndices.second - currentIndices.first > pplstcIndices.second - pplstcIndices.first) {
				pplstcIndices = currentIndices;
			}
		} else {
			constant = tab[i];
			currentIndices.first = i;
			currentIndices.second = i+1;
		}
	}

	return pplstcIndices;
}

int main() {
	std::vector<int> tab{1,1, 2,2,2,2,2, 3,3,3,3,3, 4,4,4,4};
	std::pair<int, int> result = pplstc(tab);
	
	std::cout << result.first << ", " << result.second << std::endl;

	return 0;
}
