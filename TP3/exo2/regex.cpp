#include "regex.hpp"

bool match(std::string base, std::string pattern) {

	if(pattern.empty())
		return base.empty();

	if(base.empty())
		return std::all_of(pattern.begin(), pattern.end(), [](char c){return c == '*';});

	std::string::iterator firstSpecialCharacter(
			std::find_if(pattern.begin(), pattern.end(), [](char c){return (c == '*') || (c == '%');})
		);

	if(std::equal(pattern.begin(), firstSpecialCharacter, base.begin())) {
		// Now the fun begins
	} else {
		return false;
	}
}
