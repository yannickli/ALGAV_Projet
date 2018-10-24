/*
 * Noeud.h
 *
 *  Created on: 13 oct. 2018
 *      Author: 3520328
 */

#ifndef NOEUD_H_
#define NOEUD_H_

#include "Clef.h"
#include "Arbre.h"

class Noeud {
private:
	Clef clef;
	Noeud * pere;
	Noeud * filsG;
	Noeud * filsD;
	friend class Arbre;
public:
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

	// Ajout dans le fils direct du noeud, retourne false s'il a deja deux fils
	bool Ajout(Noeud origine, Noeud n) {
		if (origine.filsG == nullptr) {
			origine.filsG = &n; //on place dans le fils droit
			return true;
		}
		if (origine.filsD == nullptr) {
			origine.filsD = &n; //on place dans le fils gauche
			return true;
		}
		return false;
	}
	bool estFilsGauche(Noeud *f) {
		if (filsG == f)
			return true;
		return false;
	}
	bool estFilsDroit(Noeud *f) {
		if (filsD == f)
			return true;
		return false;
	}

//std::vector<int> instructions(1);
//cpt/2 -> 0 ou 1 dans le tab, selon si le res est pair ou impair
//on lit le tableau à l'envres pour avoir le chemin de la racine au dernier element

};

#endif /* NOEUD_H_ */
