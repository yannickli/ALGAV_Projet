/*
 * Arbre.h
 *
 *  Created on: 12 oct. 2018
 *      Author: 3520328
 */

#ifndef ARBRE_H_
#define ARBRE_H_

#include "Noeud.h"
#include <vector>

class TasMinArbre {
private:
	Noeud *racine;
	int nbElem;
public:
	TasMinArbre() :
			racine(nullptr), nbElem(0) {
	}
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

	Noeud * echangeAvecFilsG(Noeud* pere) {
		Noeud * fg = pere->getFilsG();

		if (pere->pere) {
			if (pere->pere->estMonFilsGauche(pere))
				pere->pere->filsG = fg;
			else
				pere->pere->filsD = fg;
		}
		if (fg->filsG)
			fg->filsG->pere = pere;
		if (fg->filsD)
			fg->filsD->pere = pere;
		if (pere->filsD)
			pere->filsD->pere = fg;
		fg->setPere(pere->pere);
		pere->setPere(fg);
		pere->setFilsG(fg->filsG);
		fg->setFilsG(pere);

		Noeud * tmp = pere->getFilsD();
		pere->setFilsD(fg->getFilsD());
		fg->setFilsD(tmp);
		return fg;
	}

	Noeud * echangeAvecFilsD(Noeud * pere) {
		Noeud * fd = pere->getFilsD();

		if (pere->pere) {
			if (pere->pere->estMonFilsGauche(pere))
				pere->pere->filsG = fd;
			else
				pere->pere->filsD = fd;
		}
		if (fd->filsG)
			fd->filsG->pere = pere;
		if (fd->filsD)
			fd->filsD->pere = pere;
		if (pere->filsG)
			pere->filsG->pere = fd;

		fd->setPere(pere->pere);
		pere->setPere(fd);

		pere->setFilsD(fd->filsD);
		fd->setFilsD(pere);

		Noeud * tmp = pere->getFilsG();
		pere->setFilsG(fd->getFilsG());
		fd->setFilsG(tmp);
		return fd;
	}

	void tamiser_bas(Noeud *origine) {
		Noeud * retour;
		if (origine->getFilsG()
				&& (origine->getClef() > origine->getFilsG()->getClef())) {
			if (origine->getFilsD()
					&& (origine->getClef() > origine->getFilsD()->getClef())) {
				if (origine->getFilsG()->getClef()
						< origine->getFilsD()->getClef()) {
					retour = echangeAvecFilsG(origine);
					tamiser_bas(retour->filsG);
				} else {
					retour = echangeAvecFilsD(origine);
					tamiser_bas(retour->filsD);
				}
			} else {
				retour = echangeAvecFilsG(origine);
				tamiser_bas(retour->filsG);
			}
		} else {
			if (origine->getFilsD()
					&& origine->getClef() > origine->getFilsD()->getClef()) {
				retour = echangeAvecFilsD(origine);
				tamiser_bas(retour->filsD);
			}
		}
		if (racine == origine)
			racine = retour;
	}

	/*
	 * Supprime le plus petit element de notre arbre, ici on a un tas donc c'est la racine qu'il faut supprimer.
	 * Pour effectuer cette suppression, on echange la position de la racine avec le dernier element du tas,
	 * On supprime ensuite le nouveau dernier element et on descend la racine tant qu'elle est superieur à un de ses fils
	 */
	void supprMin() {
		Noeud* dernier = DonneMoiLeDernier();
		if (racine->getFilsG())
			racine->filsG->pere = dernier;
		if (racine->getFilsD())
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
		// On peut effacer l'ancienne racine pour liberer de la memoire
		tamiser_bas(racine);
		nbElem--;
	}

	void tamiser_haut(Noeud *origine) {
		Noeud * retour = racine;
		if (origine->pere && origine->pere->clef > origine->clef) {
			/*std::cout << "origine: " << origine->getClef() << std::endl;
			 std::cout << "son pere:" << origine->getPere()->getClef()
			 << std::endl;*/
			if (origine->pere->estMonFilsGauche(origine)) {
				retour = echangeAvecFilsG(origine->pere);
				tamiser_haut(origine);
			} else {
				if (origine->pere->estMonFilsDroit(origine)) {
					retour = echangeAvecFilsD(origine->pere);
					tamiser_haut(origine);
				} else {
					perror("Erreur dans tamiser_haut");
					exit(2);
				}
			}
		}
		if (!retour->pere)
			racine = retour;

	}

	void ajouter(Noeud *n) {
		Noeud *nlibre = DonnePereNoeudVide();
		//std::cout << nbElem << " : " << nlibre->getClef() << std::endl << "Ajout de " << n->clef << std::endl;
		if (nlibre->ajout(n) == false) {
			perror("Probleme dans ajout");
			exit(1);
		}
		nbElem++;
		tamiser_haut(n);
	}

	void afficher() {
		racine->afficher();
	}

// Faux constIter
	void constIter(std::vector<Clef> tab) {
		racine = new Noeud(tab.back());
		nbElem = 1;
		tab.pop_back();
		for (Clef c : tab) {
			ajouter(new Noeud(c));
		}
	}
}
;

#endif /* ARBRE_H_ */
