#include "regex.hpp"

bool match(std::string base, std::string pattern) {
	return match(base.begin(), base.end(), pattern.begin(), pattern.end());
}

bool match(std::string::iterator baseBegin,    std::string::iterator baseEnd,
		   std::string::iterator patternBegin, std::string::iterator patternEnd) {

	if(patternBegin == patternEnd)
		return baseBegin == baseEnd;

	if(baseBegin == baseEnd)
		return std::all_of(patternBegin, patternEnd, [](char c){return c == '*';});

	if(*patternBegin != '*' && *patternBegin != '%') {
		return (*patternBegin == *baseBegin)
			&& match(baseBegin + 1, baseEnd, patternBegin + 1, patternEnd);
	} else if(*patternBegin == '*') {
		return match(baseBegin,     baseEnd, patternBegin + 1, patternEnd)
			|| match(baseBegin + 1, baseEnd, patternBegin,     patternEnd);
	// We have a '%' here !
	} else {
		return match(baseBegin + 1,    baseEnd,
		             patternBegin + 1, patternEnd);
	}
}
