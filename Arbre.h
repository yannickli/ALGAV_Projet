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
	Noeud *dernier;
	std::vector<int> instructions;
public:
	Arbre(Noeud *n) :
			racine(n), nbElem(1), dernier(n) {
	}

	/*
	 * met a jour le pointeur sur le dernier noeud
	 */
	void majDernier() {
		std::vector<int> instructions;
		int cpt = nbElem;
		while (cpt >= 2) {
			instructions.push_back(cpt % 2);
			cpt /= 2;
		}
		Noeud *tmp = racine;
		while (!instructions.empty()) {
			if (instructions.back()) {
				tmp = racine->getFilsD();
			} else {
				tmp = racine->getFilsG();
			}
			instructions.pop_back();
		}
		dernier = tmp;
	}

	/*
	 * Supprime le plus petit element de notre arbre, ici on a un tas donc c'est le racine qu'il faut supprimer.
	 * Pour effectuer cette suppression, on echange la position de la racine avec le dernier element du tas,
	 * On supprime ensuite le nouveau dernier element et on descend la racine tant qu'elle est superieur à un de ses fils
	 */
	void supprMin() {

		racine->filsG->pere = dernier;
		racine->filsD->pere = dernier;

		dernier->filsG = racine->filsG;
		dernier->filsD = racine->filsD;

		if (dernier->pere->estFilsDroit(dernier)) {
			dernier->pere->filsD = nullptr;
		} else if (dernier->pere->estFilsGauche(dernier)) {
			dernier->pere->filsG = nullptr;
		}
		dernier->pere = nullptr;
		racine = dernier;

		//Il faut redescendre la racine si un de ses fils est plus petit;


		majDernier();
	}

	/*
	 *dern vaut soit nbElem si on veut le dernier élément,
	 *soit nbElem+1 si on veut avoir la première postion libre
	 */
	void CheminDernierElem(int dern) {
		int cpt = dern;
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

};

#endif /* ARBRE_H_ */
