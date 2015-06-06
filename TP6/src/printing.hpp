#ifndef _PRINTING_HPP_
#define _PRINTING_HPP_

#include "map.hpp"
#include "robot.hpp"
#include "walle_matrix.hpp"

#include <iostream>

using boost::numeric::ublas::matrix;

bool isInteractive();
std::ostream& operator<<(std::ostream& os, Map m);
std::ostream& operator<<(std::ostream& os, Robot r);
std::ostream& operator<<(std::ostream& os, matrix<float> mat);
std::ostream& operator<<(std::ostream& os, WallE_Matrix mat);

#endif
