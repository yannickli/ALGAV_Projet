/*
 * Noeud.h
 *
 *  Created on: 13 oct. 2018
 *      Author: 3520328
 */

#ifndef NOEUD_H_
#define NOEUD_H_

#include "Clef.h"
#include <iostream>
#include <typeinfo>

class Noeud {
private:
	Clef clef;
	Noeud * pere;
	Noeud * filsG;
	Noeud * filsD;
	friend class TasMinArbre;
public:
	Noeud(Clef nclef) :
			clef(nclef), pere(nullptr), filsG(nullptr), filsD(nullptr) {
	}
	Noeud(Clef nclef, Noeud * npere, Noeud * nfilsG, Noeud * nfilsD) :
			clef(nclef), pere(npere), filsG(nfilsG), filsD(nfilsD) {
	}
	Clef getClef() {
		return clef;
	}
	Noeud* getPere() {
		return pere;
	}
	Noeud* getFilsG() {
		return filsG;
	}
	Noeud* getFilsD() {
		return filsD;
	}
	void setPere(Noeud* nouv) {
		pere = nouv;
	}
	void setFilsG(Noeud* nouv) {
		filsG = nouv;
	}
	void setFilsD(Noeud* nouv) {
		filsD = nouv;
	}
	// Ajoute le Noeud n dans un des fils, retourne false s'il a deja deux fils
	bool ajout(Noeud *n) {
		if (filsG == nullptr) {
			filsG = n; //on place dans le fils gauche
			n->setPere(this);
			return true;
		}
		if (filsD == nullptr) {
			filsD = n; //on place dans le fils droit
			n->setPere(this);
			return true;
		}
		return false;
	}
	bool estMonFilsGauche(Noeud *f) {
		if (filsG == nullptr) {
			return false;
		}
		if (filsG->getClef() == f->getClef()) {
			return true;
		}
		return false;
	}
	bool estMonFilsDroit(Noeud *f) {
		if (filsD == nullptr)
			return false;
		if (filsD->getClef() == f->getClef())
			return true;
		return false;
	}
	void afficher() {
		clef.afficher();
		if (filsG != nullptr) {
			filsG->afficher();
		}
		if (filsD != nullptr) {
			filsD->afficher();
		}
	}
};

#endif /* NOEUD_H_ */
