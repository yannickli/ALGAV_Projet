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

class TasMinArbre {
private:
	Noeud *racine;
	int nbElem;
public:
	TasMinArbre(Noeud *n) :
			racine(n), nbElem(1) {
	}

	/*
	 * DonneMoiLeDernierNoeud
	 */
	Noeud* DonneMoiLeDernier() {
		std::vector<int> instructions;
		int cpt = nbElem;
		while (cpt >= 2) {
			instructions.push_back(cpt % 2);
			cpt /= 2;
		}
		Noeud *tmp = racine;
		while (!instructions.empty()) {
			if (instructions.back()) { // back() renvoie la valeur du dernier element de instructions
				tmp = tmp->getFilsD();
			} else {
				tmp = tmp->getFilsG();
			}
			instructions.pop_back();
		}
		return tmp;
	}

	/*
	 * Donne le pere du premier noeud vide
	 */
	Noeud* DonnePereNoeudVide() {
		std::vector<int> instructions;
		int cpt = nbElem + 1;
		while (cpt >= 2) {
			instructions.push_back(cpt % 2);
			cpt /= 2;
		}
		Noeud *tmp = racine;
		while (!instructions.empty()) {
			if (instructions.back()) { // back() renvoie la valeur du dernier element de instructions
				if (!tmp->getFilsD()) {
					return tmp;
				}
				tmp = tmp->getFilsD();
			} else {
				if (!tmp->getFilsG())
					return tmp;
				tmp = tmp->getFilsG();
			}
			instructions.pop_back();
		}
		return tmp;
	}

	/*
	 * Supprime le plus petit element de notre arbre, ici on a un tas donc c'est la racine qu'il faut supprimer.
	 * Pour effectuer cette suppression, on echange la position de la racine avec le dernier element du tas,
	 * On supprime ensuite le nouveau dernier element et on descend la racine tant qu'elle est superieur à un de ses fils
	 */
	void supprMin() {

		Noeud* dernier = DonneMoiLeDernier();

		racine->filsG->pere = dernier;
		racine->filsD->pere = dernier;

		dernier->filsG = racine->filsG;
		dernier->filsD = racine->filsD;

		if (dernier->pere->estMonFilsDroit(dernier)) {
			dernier->pere->filsD = nullptr;
		} else if (dernier->pere->estMonFilsGauche(dernier)) {
			dernier->pere->filsG = nullptr;
		}
		dernier->pere = nullptr;
		racine = dernier;
		//penser a delete ancienne racine
	}

	void ajouter(Noeud *n) {
		Noeud *nlibre = DonnePereNoeudVide();
		if (nlibre->ajout(n) == false) {
			printf("GROS PROBLEME!");
		}
	}



};

#endif /* ARBRE_H_ */
