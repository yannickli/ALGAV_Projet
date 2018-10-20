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
	Noeud pere;
	Noeud filsG;
	Noeud filsD;
public:
	Noeud(Clef nclef, Noeud npere, Noeud nfilsG, Noeud nfilsD) :
			clef(nclef), pere(npere), filsG(nfilsG), filsD(nfilsD) {
	}

	void Ajout(Noeud racine, Noeud n) { //marche pas encore
		/*if (!racine.rempli) {
			if (racine.filsG != nullptr) {
				racine.filsD = n; //on place dans le fils droit
			} else {
				racine.filsG = n; //on place dans le fils gauche
			}
		} else {
			Ajout(racine.filsG, n);
		}*/

		//std::vector<int> instructions(1);
		//cpt/2 -> 0 ou 1 dans le tab, selon si le res est pair ou impair
		//on lit le tableau à l'envres pour avoir le chemin de la racine au dernier element
	}
};

#endif /* NOEUD_H_ */
