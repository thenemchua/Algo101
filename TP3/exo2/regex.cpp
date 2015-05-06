#include "regex.hpp"

bool match(std::string base, std::string pattern) {
	return match(base.begin(), base.end(), pattern.begin(), pattern.end()); // We use iterators to traverse the arrays
}

bool match(std::string::iterator baseBegin,    std::string::iterator baseEnd,
		   std::string::iterator patternBegin, std::string::iterator patternEnd) {

	if(patternBegin == patternEnd)
		return baseBegin == baseEnd; // If the pattern is empty, return true if the base is too

	if(baseBegin == baseEnd) // If the base is empty, return true if the pattern is empty or contains only "*"
		return std::all_of(patternBegin, patternEnd, [](char c){return c == '*';});

	if(*patternBegin != '*' && *patternBegin != '%') { // If it's not a special character
		return (*patternBegin == *baseBegin) // Return true if the character is identical 
			&& match(baseBegin + 1, baseEnd, patternBegin + 1, patternEnd); // And if the rest of the pattern matches
	} else if(*patternBegin == '*') {
		return match(baseBegin,     baseEnd, patternBegin + 1, patternEnd) // The "*" matches no character
			|| match(baseBegin + 1, baseEnd, patternBegin,     patternEnd); // The "*" matches the next character
	// We have a '%' here !
	} else {
		return match(baseBegin + 1,    baseEnd,
		             patternBegin + 1, patternEnd); // We skip to the next char
	}
}
