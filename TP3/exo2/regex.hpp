#include <string>
#include <algorithm>

bool match(std::string base, std::string pattern);
bool match(std::string::iterator baseBegin,    std::string::iterator baseEnd,
		   std::string::iterator patternBegin, std::string::iterator patternEnd);
