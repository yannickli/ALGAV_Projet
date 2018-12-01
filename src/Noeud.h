/*
 * Noeud.h
 *
 *  Created on: 13 oct. 2018
 *      Author: 3520328
 */

#ifndef NOEUD_H_
#define NOEUD_H_

#include "Clef.h"

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
	// Ajoute le Noeud n dans un des fils, retourne false s'il a deja deux fils
	bool ajout(Noeud *n) {
		if (filsG == nullptr) {
			filsG = n; //on place dans le fils droit
			return true;
		}
		if (filsD == nullptr) {
			filsD = n; //on place dans le fils gauche
			return true;
		}
		return false;
	}
	bool estMonFilsGauche(Noeud *f) {
		if (filsG == f)
			return true;
		return false;
	}
	bool estMonFilsDroit(Noeud *f) {
		if (filsD == f)
			return true;
		return false;
	}

	bool suisJeLeFilsGauche() {
		std::cout << "test filsG" << std::endl;
		if (pere->filsG == this) {
			std::cout << "test filsG" << std::endl;
			return true;
		}
		std::cout << "test filsG" << std::endl;
		return false;
	}

	bool suisJeLeFilsDroit() {
		std::cout << "test filsD" << std::endl;
		if (pere->filsD == this) {
			std::cout << "test filsD" << std::endl;
			return true;
		}
		std::cout << "test filsD" << std::endl;
		return false;
	}
};

#endif /* NOEUD_H_ */
