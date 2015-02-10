#include<iostream>
#include<vector>
#include<algorithm>

/**
 *
 */
bool isInVector(int number, std::vector<int> const& tab) {
	if(number < tab[0] || number > tab[tab.size() - 1])
		return false;

	int i = 0;
	int j = tab.size();

	while(i != j - 1) {
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

int main (int argc, char const* argv[]) {

	std::vector<int> tab(10);
	int i = 0;
	for(int& num : tab) {
		num = i+=2;
		std::cout << num << std::endl;
	}

	std::cout << isInVector(7, tab) << std::endl;
	std::cout << isInVector(42, tab) << std::endl;

	return 0;
}
