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
	Clef clef;
	Noeud racine;
	int nbElem;
	std::vector<int> instructions;

	//friend void SupprMin(Arbre a);
public:
	Arbre(Clef c, Noeud n) :
			instructions(1), clef(c), racine(n) {
		nbElem = 1;
	}
	/*unsigned int getI1();
	 unsigned int getI2();
	 unsigned int getI3();
	 unsigned int getI4();
	 bool eg(Arbre a1, Arbre a2);
	 bool inf(Arbre a1, Arbre a2);*/

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

	void SupprMin(Arbre a);

};

#endif /* ARBRE_H_ */
