#include "regex.hpp"

bool match(std::string base, std::string pattern) {
	return match(base, base.begin(), base.end(), pattern, pattern.begin(), pattern.end());
}

bool match(std::string const& base,
           std::string::iterator baseBegin,    std::string::iterator baseEnd,
		   std::string const& pattern,
		   std::string::iterator patternBegin, std::string::iterator patternEnd) {

	if(pattern.empty())
		return base.empty();

	if(base.empty())
		return std::all_of(patternBegin, patternEnd, [](char c){return c == '*';});

	std::string::iterator firstSpecialCharacter(
			std::find_if(patternBegin, patternEnd, [](char c){return (c == '*') || (c == '%');})
		);

	if(std::equal(patternBegin, firstSpecialCharacter, baseBegin)) {
		// Now the fun begins
		std::string::iterator baseNewPosition(baseBegin + std::distance(patternBegin, firstSpecialCharacter));

		// No special characters
		if(firstSpecialCharacter == patternEnd) {

			if(baseNewPosition == baseEnd)
				return true;
			else
				return false;

		} else if(*firstSpecialCharacter == '%') {

			// No room for the last '%'
			if(baseNewPosition == baseEnd)
				return false;
			else
				return match(base,    baseNewPosition + 1,       baseEnd,
				             pattern, firstSpecialCharacter + 1, patternEnd);

		// We have a '*' here!
		} else {
			// Go at the end of the '*' streak
			std::string::iterator endOfStarStreak(
				std::find_if(firstSpecialCharacter, patternEnd, [](char c){return c != '*';})
			);

			if(endOfStarStreak == patternEnd) {
				return true;
			} else {
				char const& requiredCharacter(*endOfStarStreak);
				baseNewPosition = std::find(baseNewPosition, baseEnd, requiredCharacter);

				if(baseNewPosition == baseEnd)
					return false;
				else
					return match(base,    baseNewPosition + 1, baseEnd,
					             pattern, endOfStarStreak + 1, patternEnd);

			}
		}
	} else {
		return false;
	}
}
