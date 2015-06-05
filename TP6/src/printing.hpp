#ifndef _PRINTING_HPP_
#define _PRINTING_HPP_

#include "map.hpp"
#include "robot.hpp"
#include "walle_matrix.hpp"

#include <iostream>
#include <iomanip>

using boost::numeric::ublas::matrix;

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

inline std::ostream& operator<<(std::ostream& os, matrix<int> mat) {
	int rows = mat.size1(),
		cols = mat.size2();

	for(int row = rows - 1 ; row >= 0 ; --row) {
		for(int col = 0 ; col < cols ; ++col) {
			if(col == 0) {
				if(row == rows - 1) {
					os << "⎡ ";
				} else if(row == 0) {
					os << "⎣ ";
				} else {
					os << "⎢ ";
				}
			}

			os << std::setw(4) << mat(row, col) << " ";

			if(col == cols - 1) {
				if(row == rows - 1) {
					os << "⎤" << std::endl;
				} else if(row == 0) {
					os << "⎦" << std::endl;
				} else {
					os << "⎥" << std::endl;
				}
			}
		}
	}

	return os;
}

inline std::ostream& operator<<(std::ostream& os, WallE_Matrix mat) {
	int rows = mat.size1(),
		cols = mat.size2();

	// Matrice's origins are top left
	for(int row = rows - 1 ; row >= 0 ; --row) {
		for(int col = 0 ; col < cols ; ++col) {
			if(col == 0) {
				if(row == rows - 1) {
					os << "⎡ ";
				} else if(row == 0) {
					os << "⎣ ";
				} else {
					os << "⎢ ";
				}
			}

			int value = mat(row, col);
			switch(value) {
				case EAST:
					os << "←" << " ";
					break;
				case NORTH:
					os << "↓" << " ";
					break;
				case NORTH_EAST:
					os << "↙" << " ";
					break;
				default:
					std::cerr << "Wrong value in WallE_Matrix" << std::endl;
					std::abort();
			}

			if(col == cols - 1) {
				if(row == rows - 1) {
					os << "⎤" << std::endl;
				} else if(row == 0) {
					os << "⎦" << std::endl;
				} else {
					os << "⎥" << std::endl;
				}
			}
		}
	}

	return os;
}

#endif
