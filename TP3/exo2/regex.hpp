#include <string>
#include <algorithm>

bool match(std::string base, std::string pattern);
bool match(std::string const& base,
           std::string::iterator baseBegin,    std::string::iterator baseEnd,
		   std::string const& pattern,
		   std::string::iterator patternBegin, std::string::iterator patternEnd);
