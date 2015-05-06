#include <iostream>
#include <vector>

bool existeSsdsx(std::vector<int>::iterator begin, std::vector<int>::iterator end,
		int x) {
	if(x == 0)
		return true;
	else if(begin == end)
		return false;
	else {
		for(auto i  = begin ; i != end ; ++i) {
			int sum = *i;
			if(sum == x)
				return true;
			for(auto j = begin + 1 ; j != end ; ++j) {
				sum += *j;
				if(sum == x)
					return true;
				else if(sum > x)
					break;
			}
		}
		return false;
	}
}

int main() {
	std::vector<int> tab{1,2,3,4,5,6,7,8,9,0};
	std::cout << std::boolalpha << existeSsdsx(tab.begin(), tab.end(), 17) << std::endl;
	return 0;
}
