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
	Noeud *racine;
	int nbElem;
	std::vector<int> instructions;
public:
	Arbre(Noeud *n) :
			racine(n), nbElem(1), instructions(1) {
	}

	void CheminDernierElem(int dern) { //dern vaut soit nbElem si on veut le dernier élément,
		int cpt = dern;	//soit nbElem+1 si on veut avoir la première postion libre
		while (cpt != 1) {
			instructions.push_back(cpt % 2);
			cpt -= (int) cpt / 2;
		}
		//le vecteur "instructions" possède maintenant le chemin

	}

	void Ajouter(Noeud *n) {
		Noeud *courrant = racine;
		int inst;
		CheminDernierElem(nbElem + 1);  //on cherche la premiere place libre
		while (!instructions.empty()) {
			inst = instructions.back();
			instructions.pop_back();
			if (inst == 0) {
				courrant = racine->getFilsG();
			} else {
				courrant = racine->getFilsD();
			}
		}
		if (nbElem == 1) {
			n = racine->getFilsG();
		} else {
			n = courrant;
		}
	}

	void SupprMin() {
		Noeud *courrant = racine;
		int inst;
		CheminDernierElem(nbElem);  //on cherche le dernier element de l'arbre
		while (!instructions.empty()) {
			inst = instructions.back();
			instructions.pop_back();
			if (inst == 0) {
				courrant = racine->getFilsG();
			} else {
				courrant = racine->getFilsD();
			}
		}
		Noeud *tmp = racine;
		racine = courrant;
		courrant = nullptr;
		while (courrant) {

		}

		/*Arbre temp;
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
		 }*/

	}

};

#endif /* ARBRE_H_ */
