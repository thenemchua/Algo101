#ifndef _PRINTING_HPP_
#define _PRINTING_HPP_

#include "map.hpp"
#include "robot.hpp"

#include <iostream>
#include <iomanip>

inline std::ostream& operator<<(std::ostream& os, Map m) {
	int line = m.getSize() - 1;
	os << "   ┌";
	for(int i = 1 ; i < m.getSize() ; ++i) {
		os << "───┬";
	}
	os << "───┐" << std::endl;

	for(int i = 1 ; i < m.getSize() ; ++i) {
		os << std::right << std::setw(2) << line--
		   << " │";
		for(int j = 1 ; j < m.getSize() ; ++j) {
			os << "   │";
		}
		os <<  "   │" << std::endl << "   ├";
		for(int j = 1 ; j < m.getSize() ; ++j) {
			os << "───┼";
		}
		os << "───┤" << std::endl;
	}

	os << std::right << std::setw(4) << " 0 │";
	for(int j = 1 ; j < m.getSize() ; ++j) {
		os << "   │";
	}
	os << "   │" << std::endl << "   └";
	for(int i = 1 ; i < m.getSize() ; ++i) {
		os << "───┴";
	}
	os << "───┘" << std::endl
	   << "  ";
	for(int i = 0 ; i < m.getSize() ; ++i) {
		os << std::setw(4) << i;
	}
	os << std::endl;
	return os;
}

inline std::ostream& operator<<(std::ostream& os, Robot r) {
	// Go right
	std::cout << "\x1b[" << (4*r.getCoordX() + 5) << "C"
	// Go up
	          << "\x1b[" << (2*r.getCoordY() + 3) << "A"
	          << "⬤"
	// Re go left (+1)
	          << "\x1b[" << (4*r.getCoordX() + 6) << "D"
	// Re go down
	          << "\x1b[" << (2*r.getCoordY() + 3) << "B";

	return os;
}

#endif
