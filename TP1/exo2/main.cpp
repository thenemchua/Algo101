#include <iostream>
#include <vector>

#include "question1.hpp"
#include "question2.hpp"

/**
 * Cette fonction prends un seul paramètre via la ligne de commande (hormis le
 * nom du programme même), à savoir la taille du tableau E.
 *
 * Ensuite il crée ce tableau avec la taille demandée et l'initialise avec la
 * suite arithmétique de premier terme 0 et de raison 1.
 *
 * Il appelle ensuite la méthode question2::pairsum et affiche le résultat.
 *
 *
 * Exemple d'exécution :
 *	Paramètres : n = 3
 *
 *		E        = {0, 1, 2}
 *		résultat = 0
 *
 *		  i ╔═══╦═══╦═══╗
 *		j   ║ 0 ║ 1 ║ 2 ║
 *		╔═══╬═══╩═══╩═══╣ ⎫
 *		║ 0 ║ 0 │ 1 │ 2 ║ ⎪
 *		╠═══╣───┼───┼───╢ ⎪
 *		║ 1 ║ 1 │ 2 │ 3 ║ ⎬ Sommes
 *		╠═══╣───┼───┼───╢ ⎪
 *		║ 2 ║ 2 │ 3 │ 4 ║ ⎪
 *		╚═══╩═══╧═══╧═══╝ ⎭
 *
 *		On cherche 0 dans ce tableau :
 *
 *		Étape 1 :      Étape 2 :      Étape 3 :      Étape 4 :
 *      i = 0, j = 2   i = 0, j = 1   i = 0, j = 0   i = 1, j = 0
 *      compteur = 0   compteur = 0   compteur = 1   compteur = 1
 *		┌───┬───┬───┐  ┌───┬───┬───┐  ┌───┬───┬───┐  ┌───┬───┬───┐
 *		│ 0 │ 1 │ 2 │  │ 0 │ 1 │ 2 │  │>0<│ 1 │ 2 │  │ 0 │>1<│ 2 │
 *		├───┼───┼───┤  ├───┼───┼───┤  ├───┼───┼───┤  ├───┼───┼───┤
 *		│ 1 │ 2 │ 3 │  │>1<│ 2 │ 3 │  │ 1 │ 2 │ 3 │  │ 1 │ 2 │ 3 │
 *		├───┼───┼───┤  ├───┼───┼───┤  ├───┼───┼───┤  ├───┼───┼───┤
 *		│>2<│ 3 │ 4 │  │ 2 │ 3 │ 4 │  │ 2 │ 3 │ 4 │  │ 2 │ 3 │ 4 │
 *		└───┴───┴───┘  └───┴───┴───┘  └───┴───┴───┘  └───┴───┴───┘
 *
 *		On cherche 1 dans le tableau :
 *
 *		Étape 1 :      Étape 2 :      Étape 3 :      Étape 4 :      Étape 5 :
 *      i = 0, j = 2   i = 0, j = 1   i = 1, j = 1   i = 1, j = 0   i = 2, j = 0
 *      compteur = 0   compteur = 1   compteur = 1   compteur = 2   compteur = 2
 *      ┌───┬───┬───┐  ┌───┬───┬───┐  ┌───┬───┬───┐  ┌───┬───┬───┐  ┌───┬───┬───┐
 *      │ 0 │ 1 │ 2 │  │ 0 │ 1 │ 2 │  │ 0 │ 1 │ 2 │  │ 0 │>1<│ 2 │  │ 0 │ 1 │>2<│
 *      ├───┼───┼───┤  ├───┼───┼───┤  ├───┼───┼───┤  ├───┼───┼───┤  ├───┼───┼───┤
 *      │ 1 │ 2 │ 3 │  │>1<│ 2 │ 3 │  │ 1 │>2<│ 3 │  │ 1 │ 2 │ 3 │  │ 1 │ 2 │ 3 │
 *      ├───┼───┼───┤  ├───┼───┼───┤  ├───┼───┼───┤  ├───┼───┼───┤  ├───┼───┼───┤
 *      │>2<│ 3 │ 4 │  │ 2 │ 3 │ 4 │  │ 2 │ 3 │ 4 │  │ 2 │ 3 │ 4 │  │ 2 │ 3 │ 4 │
 *      └───┴───┴───┘  └───┴───┴───┘  └───┴───┴───┘  └───┴───┴───┘  └───┴───┴───┘
 *
 *      On cherche 2 dans le tableau :
 *
 *		Étape 1 :      Étape 2 :      Étape 3 :      Étape 4 :      Étape 5 :
 *      i = 0, j = 2   i = 1, j = 0   i = 1, j = 1   i = 1, j = 0   i = 2, j = 0
 *      compteur = 1   compteur = 1   compteur = 2   compteur = 2   compteur = 3
 *      ┌───┬───┬───┐  ┌───┬───┬───┐  ┌───┬───┬───┐  ┌───┬───┬───┐  ┌───┬───┬───┐
 *      │ 0 │ 1 │ 2 │  │ 0 │ 1 │ 2 │  │ 0 │ 1 │ 2 │  │ 0 │>1<│ 2 │  │ 0 │ 1 │>2<│
 *      ├───┼───┼───┤  ├───┼───┼───┤  ├───┼───┼───┤  ├───┼───┼───┤  ├───┼───┼───┤
 *      │ 1 │ 2 │ 3 │  │ 1 │ 2 │ 3 │  │ 1 │>2<│ 3 │  │ 1 │ 2 │ 3 │  │ 1 │ 2 │ 3 │
 *      ├───┼───┼───┤  ├───┼───┼───┤  ├───┼───┼───┤  ├───┼───┼───┤  ├───┼───┼───┤
 *      │>2<│ 3 │ 4 │  │ 2 │>3<│ 4 │  │ 2 │ 3 │ 4 │  │ 2 │ 3 │ 4 │  │ 2 │ 3 │ 4 │
 *      └───┴───┴───┘  └───┴───┴───┘  └───┴───┴───┘  └───┴───┴───┘  └───┴───┴───┘
 *
 *      On cherche 3 dans le tableau :
 *
 *		Étape 1 :      Étape 2 :      Étape 3 :      Étape 4 :      Étape 5 :
 *      i = 0, j = 2   i = 1, j = 0   i = 2, j = 0   i = 2, j = 1   i = 2, j = 0
 *      compteur = 0   compteur = 1   compteur = 2   compteur = 2   compteur = 2
 *      ┌───┬───┬───┐  ┌───┬───┬───┐  ┌───┬───┬───┐  ┌───┬───┬───┐  ┌───┬───┬───┐
 *      │ 0 │ 1 │ 2 │  │ 0 │ 1 │ 2 │  │ 0 │ 1 │ 2 │  │ 0 │ 1 │ 2 │  │ 0 │ 1 │>2<│
 *      ├───┼───┼───│  ├───┼───┼───┤  ├───┼───┼───┤  ├───┼───┼───┤  ├───┼───┼───┤
 *      │ 1 │ 2 │ 3 │  │ 1 │ 2 │ 3 │  │ 1 │ 2 │ 3 │  │ 1 │ 2 │>3<│  │ 1 │ 2 │ 3 │
 *      ├───┼───┼───┤  ├───┼───┼───┤  ├───┼───┼───┤  ├───┼───┼───┤  ├───┼───┼───┤
 *      │>2<│ 3 │ 4 │  │ 2 │>3<│ 4 │  │ 2 │ 3 │>4<│  │ 2 │ 3 │ 4 │  │ 2 │ 3 │ 4 │
 *      └───┴───┴───┘  └───┴───┴───┘  └───┴───┴───┘  └───┴───┴───┘  └───┴───┴───┘
 *
 *      On a donc pour résultat 1 + 2 + 3 + 2 = 6
 */
int main(int argc, char const* argv[]) {
	if(argc == 1) {
		std::cout << "Usage: " << argv[0] << " n" << std::endl;
		return 64;
	}

	std::vector<int> tab(std::stoi(argv[1]));

	int i = 0;
	for(int& el : tab) {
		el = i++;
	}

	std::cout << question2::pairsum(tab) << std::endl;

	return 0;
}
