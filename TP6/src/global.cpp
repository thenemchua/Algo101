#include "global.hpp"
#include "walle_matrix.hpp"
#include "printing.hpp"

#include <algorithm>

using boost::numeric::ublas::matrix;

namespace global {


	float minimize(Robot robot, Map const& map) {
		bool interactive = isInteractive();

		int size = map.getSize();
		// Initialise la matrice de direction et la matrice de coûts
		WallE_Matrix directionMat(size);
		matrix<float> costMat(size, size);

		// Base
		directionMat(0,0) = 2;
		costMat(0,0) = 0;

		// ∀ j ∈ ⟦0,taille⟧, m(0,j) = 0 ∧ M(0,j) = est
		for(int row = 1 ; row < size ; ++row) {
			directionMat(0, row) = EAST;
			costMat(0, row) = costMat(0, row - 1) + map.northCost(0, row - 1);
		}

		// ∀ i ∈ ⟦0,taille⟧, m(i,0) = 0 ∧ M(i,0) = nord
		for(int col = 1 ; col < size ; ++col) {
			directionMat(col, 0) = NORTH;
			costMat(col, 0) = costMat(col - 1, 0) + map.eastCost(col - 1, 0);
		}

		// ∀ (i,j) ∈ ⟦0,taille⟧², m(i,j) = min(m(i,j-1)+coûtNord, m(i-1,j)+coûtEst, m(i-1,j-1)+coûtNordEst)
		//                        M(i,j) = direction de l'origine du minimum
		for(int row = 1 ; row < size ; ++row) {
			for(int col = 1 ; col < size ; ++col) {

				std::vector<float> costs(4);
				costs[EAST]  = map.eastCost(col-1, row) + costMat(col-1, row);
				costs[NORTH] = map.northCost(col, row-1) + costMat(col, row-1);
				costs[WEST]  = map.westCost(col+1, row) + costMat(col+1, row);
				costs[SOUTH] = map.southCost(col, row+1) + costMat(col, row+1);
				
				// Calcul du minimum et assignation des valeurs des matrices
				auto el = std::min_element(costs.begin(), costs.end());
				switch(std::distance(costs.begin(), el)) {
					case EAST:
						directionMat(col, row) = EAST;
						costMat(col, row) = costs[EAST];
						break;
					case NORTH:
						directionMat(col, row) = NORTH;
						costMat(col, row) = costs[NORTH];
						break;
					case WEST:
						directionMat(col, row) = WEST;
						costMat(col, row) = costs[WEST];
						break;
					case SOUTH:
						directionMat(col, row) = SOUTH;
						costMat(col, row) = costs[SOUTH];
						break;
				}
			}
		}

		if(interactive) {
			std::cout << directionMat << std::endl;
			std::cout << costMat      << std::endl;
		}

		std::vector<int> reversed_directions;
		// Parcours de la matrice dans la méthode WallE_Matrix::iterator::operator++
		for(int direction : directionMat) {
			// Ajout dans un tableau qui contient les étapes à l'envers
			reversed_directions.push_back(direction);
		}

		if(interactive) {
			std::cout << map << robot;
		} else {
			std::cout << "Chemin du robot:" << std::endl
			          << robot << " ";
		}

		// Parcourt le tableau dans le sens inverse et fait avancer le robot dans la direction appropriée
		for(auto it = reversed_directions.rbegin() ; it != reversed_directions.rend() ; ++it) {
			if(*it == NORTH) {
				robot.goNorth();

				if(interactive) {
					std::cout << robot;
				} else {
					std::cout << robot << " ";
				}

			} else if(*it == EAST) {
				robot.goEast();

				if(interactive) {
					std::cout << robot;
				} else {
					std::cout << robot << " ";
				}

			} else {
				robot.goNorthEast();

				if(interactive) {
					std::cout << robot;
				} else {
					std::cout << robot << " ";
				}

			}
		}
		std::cout << std::endl;

		return robot.getTotalCost();
	}
}
