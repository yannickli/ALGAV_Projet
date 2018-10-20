/*
 * Arbre.h
 *
 *  Created on: 12 oct. 2018
 *      Author: 3520328
 */

#ifndef ARBRE_H_
#define ARBRE_H_

#include "Noeud.h"
#include "vector"

class Arbre {
private:
	Noeud racine;
	int nbElem;
	std::vector<int> instructions;
public:
	Arbre(Noeud n) :
			racine(n), nbElem(1) {
		instructions = new std::vector(1);
	}

	void CheminDernierElem() {
		//std::vector<int> instructions(1);
		int cpt = nbElem;
		while (cpt != 1) {
			instructions.push_back(cpt % 2);
			cpt -= (int) cpt / 2;
		}
		//return instructions;

	}

	void Ajouter(Noeud n) {
		//std::vector<int> instructions = CheminDernierElem();
	}

	void SupprMin() {
		Arbre temp;
		if (racine.filsD != nullptr) {
			if (racine.filsG != nullptr) {
				if (inf(racine.filsG.clef, racine.filsD.clef)) { //Fils gauche est plus petit
					temp = racine.filsG;
					racine.filsG = racine.filsG.filsG;

				} else {
					if (eg(racine.filsG.clef, racine.filsD.clef)) {

					}
				}
			} else {

			}
		}

	}

};

#endif /* ARBRE_H_ */
