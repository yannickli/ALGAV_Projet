/*
 * NoeudT.h
 *
 *  Created on: 14 déc. 2018
 *      Author: 3520328
 */

#ifndef SRC_NOEUDT_H_
#define SRC_NOEUDT_H_

#include "Clef.h"
#include <iostream>
#include <typeinfo>

class NoeudT {
private:
	Clef *clef;
	NoeudT * pere;
	std::vector<NoeudT*> *fils;
	friend class TournoiB;
public:
	NoeudT(Clef *nclef) :
			clef(nclef), pere(nullptr) {
		fils = new std::vector<NoeudT*>();
	}
	NoeudT(Clef *nclef, NoeudT * npere) :
			clef(nclef), pere(npere) {
		fils = new std::vector<NoeudT*>();
	}
	Clef getClef() {
		return clef;
	}
	NoeudT* getPere() {
		return pere;
	}
	std::vector<NoeudT*> getFils() {
		return fils;
	}

	void setPere(NoeudT* nouv) {
		pere = nouv;
	}
	void setFils(std::vector<NoeudT*> nouv) {
		fils = nouv;
	}

	bool aUnFils() {
		if (fils->empty())
			return false;
		return true;
	}

	// Ajoute le Noeud n dans un des fils, retourne false s'il a deja deux fils
	void ajout(NoeudT *n) {
		fils->emplace_back(n);
	}
	/*bool estMonFilsGauche(Noeud *f) {
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
	 }*/
};

#endif /* SRC_NOEUDT_H_ */
