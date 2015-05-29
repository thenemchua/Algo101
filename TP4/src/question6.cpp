#include "question6.hpp"

using boost::numeric::ublas::matrix;

namespace question6 {

	std::vector<int> computeSpots(matrix<int> dynaMat) { // On pacours la matrice à l'envers pour retrouver les spots utilisés
		std::vector<int> spots;
		int row(dynaMat.size1() - 1),
		    col(dynaMat.size2() - 1);

		bool goUp = true;

		// goUp => On monte dans la matrice (Cas où le spot actuel n'est pas utilisé)

		while(row > 0) {
			if(col == 0) {
				break; // On s'arrête si on atteint la première colonne
			}

			int nextRow = (goUp) ? row-1 : row,
			    nextCol = (!goUp)? col-1 : col;

			if(dynaMat(row, col) > dynaMat(nextRow, nextCol)) { // Si la cellule actuelle est supérieure à la suivante, cela signifie qu'on change de cas
				if(goUp) {
					spots.push_back(row - 1); // On ce le spot actuelomptabilis
				}

				// On inverse la direction et on met la bonne cellule
				goUp = not goUp;
				nextRow = (goUp) ? row-1 : row;
				nextCol = (!goUp)? col-1 : col;
			}
			
			//Case suivante 
			row = nextRow;
			col = nextCol;
		}
		return spots;
	}

}
