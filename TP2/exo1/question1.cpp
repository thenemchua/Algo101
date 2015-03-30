#include "question1.hpp"

using boost::numeric::ublas::matrix;

namespace question1 {

	matrix<int> operator*(matrix<int> const& A, matrix<int> const& B) {
		int rowsA = A.size1(), colsA = A.size2(),
		    rowsB = B.size1(), colsB = B.size2();

		if(colsA != rowsB) // Vérification de la taille
			throw new std::length_error("Matrices must have a the right sizes to be multiplicated");

		matrix<int> result(rowsA, colsB); 

		for(int row = 0 ; row < rowsA ; ++row) { // Traitement des lignes
			for(int col = 0 ; col < colsB ; ++col) { // Traitement des colonnes
				int el = 0;
				for(int i = 0 ; i < colsA ; ++i) { // Un élément est la somme des produits des lignes de A par les colonnes de B
					el += A(row, i)*B(i, col);
				}
				result(row, col) = el;
			}
		}

		return result;
	}

}
