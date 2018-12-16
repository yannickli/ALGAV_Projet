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
	Noeud * getRacine() {
		return racine;
	}
	// Renvoie le dernier noeud de notre tas
	// Valide
	Noeud* DonneMoiLeDernier() {
		std::vector<int> *instructions = new std::vector<int>();
		int cpt = nbElem;
		while (cpt >= 2) {
			instructions->push_back(cpt % 2);
			cpt /= 2;
		}
		Noeud *tmp = racine;
		while (!instructions->empty()) {
			if (instructions->back()) { // back() renvoie la valeur du dernier element de instructions
				tmp = tmp->getFilsD();

			} else {
				tmp = tmp->getFilsG();
			}
			instructions->pop_back();
		}
		return tmp;
	}

// Donne le pere du premier noeud vide
// Valide
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

// Echange la position du noeud pere avec son fils gauche
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

// Echange la position du noeud pere avec son fils droit
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

	void tamiser_racine() {
		if (racine->getFilsG()
				&& (racine->getClef() > racine->getFilsG()->getClef())) {
			if (racine->getFilsD()
					&& racine->getClef() > racine->getFilsD()->getClef()) {
				if (racine->getFilsG()->getClef()
						< racine->getFilsD()->getClef()) {
					racine = echangeAvecFilsG(racine);
					tamiser_bas(racine->filsG);
				} else {
					racine = echangeAvecFilsD(racine);
					tamiser_bas(racine->filsD);
				}
			} else {
				racine = echangeAvecFilsG(racine);
				tamiser_bas(racine->filsG);
			}
		} else {
			if (racine->getFilsD()
					&& racine->getClef() > racine->getFilsD()->getClef()) {
				racine = echangeAvecFilsD(racine);
				tamiser_bas(racine->filsD);
			}
		}
	}

// Permet de retablir les proprietes de tas min en descendant a partir du noeud origine
// Utilise pour la supression de la racine
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
	}

	/*
	 * Supprime le plus petit element de notre arbre, ici on a un tas donc c'est la racine qu'il faut supprimer.
	 * Pour effectuer cette suppression, on echange la position de la racine avec le dernier element du tas,
	 * On supprime ensuite le nouveau dernier element et on descend la racine tant qu'elle est superieur à un de ses fils
	 */
	void supprMin() {
		Noeud* dernier = DonneMoiLeDernier();
		if (dernier->pere && dernier->pere->estMonFilsDroit(dernier)) {
			dernier->pere->filsD = nullptr;
		} else if (dernier->pere && dernier->pere->estMonFilsGauche(dernier)) {
			dernier->pere->filsG = nullptr;
		}

		dernier->pere = nullptr;
		dernier->filsG = racine->filsG;
		dernier->filsD = racine->filsD;

		if (racine->getFilsG())
			racine->filsG->pere = dernier;
		if (racine->getFilsD())
			racine->filsD->pere = dernier;

		racine = dernier;
		nbElem--;
		tamiser_racine();

	}

// Permet de retablir les proprietes de tas min en remontant a partir du dernier noeud
// Utilise pour l'ajout
	void tamiser_haut(Noeud *origine) {
		Noeud * retour = racine;
		if (origine->pere && origine->pere->clef > origine->clef) {
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

// Ajoute le noeud n a notre tas
	void ajout(Noeud *n) {
		Noeud *nlibre = DonnePereNoeudVide();
		if (nlibre->ajout(n) == false) {
			perror("Probleme dans ajout");
			exit(1);
		}
		nbElem++;
		tamiser_haut(n);
	}

// Affichage en parcours prefixe
	void afficher() {
		racine->afficher();
	}

// Permet de construire un tas min a partir de tab
	void constIter(std::vector<Clef*> *tab) {
		std::vector<Noeud *> tmp;
		for (Clef *c : *tab) {
			tmp.push_back(new Noeud(c));
			nbElem++;
		}
		racine = tmp[0];
		int hauteur = log2(nbElem);
		if (nbElem >= 3) {
			tmp[0]->setFilsG(tmp[1]);
			tmp[0]->setFilsD(tmp[2]);
		} else {
			if (nbElem == 2)
				tmp[0]->setFilsG(tmp[1]);
		}
		for (int i = 1; i < pow(2, hauteur) - 1; i++) {
			tmp[i]->setPere(tmp[(i - 1) / 2]);
			if (2 * i + 1 < nbElem)
				tmp[i]->setFilsG(tmp[2 * i + 1]);
			if (2 * i + 2 < nbElem)
				tmp[i]->setFilsD(tmp[2 * i + 2]);
		}
		for (int i = pow(2, hauteur) - 1; i < nbElem; i++) {
			tmp[i]->setPere(tmp[(i - 1) / 2]);
		}
		for (int i = pow(2, hauteur) - 2; i >= 0; i--) {
			tamiser_bas(tmp[i]);
		}
	}

// constIter naif
	void constIterNaif(std::vector<Clef*> *tab) {
		racine = new Noeud(tab->back());
		nbElem = 1;
		tab->pop_back();
		for (Clef * c : *tab) {
			ajout(new Noeud(c));
		}
	}

// Ajoute la cle du noeud n au vecteur vec
	void addToVector(Noeud *n, std::vector<Clef*>* vec) {
		if (n == nullptr)
			return;
		vec->push_back(n->getClef());
		addToVector(n->filsG, vec);
		addToVector(n->filsD, vec);
	}

// Transforme notre arbre en vecteur
	std::vector<Clef*> *toVector() {
		std::vector<Clef*> * res = new std::vector<Clef*>();
		addToVector(racine, res);
		return res;
	}

// Fonction qui fait l'union des deux tas passes en parametres
	friend TasMinArbre* union2Arbre(TasMinArbre *t1, TasMinArbre *t2) {
		std::vector<Clef*> *v1 = t1->toVector();
		std::vector<Clef*> *v2 = t2->toVector();
		TasMinArbre * res = new TasMinArbre();
		v1->insert(v1->end(), v2->begin(), v2->end());
		res->constIter(v1);
		return res;
	}

// Test si un noeud respecte les proprietes du tas min i.e. si la cle du noeud est plus petite que celle de ses fils
	bool testN(Noeud * n, int *nb) {
		Noeud * fg = n->filsG;
		Noeud * fd = n->filsD;
		(*nb)++;
		if (fg) {
			if (fd) {
				if (n->clef < fg->clef && n->clef < fd->clef) {
					if (testN(fg, nb) && testN(fd, nb)) {
						return true;
					} else {
						return false;
					}
				} else {
					return false;
				}
			} else {
				if (n->clef < fg->clef) {
					if (testN(fg, nb)) {
						return true;
					} else {
						return false;
					}
				} else
					return false;
			}
		} else {
			return true;
		}
	}

// Permet de tester que notre TasMin est bien implementé
// Grace a testN, on verifie que pour tous les noeuds, on est bien inferieur a nos deux fils
// La fonction retourne 1 si notre tas verifie bien les proprietes de tas min et que l'on a bien teste le bon nombre de noeud
	int tester() {
		int cpt = 0;
		if (testN(racine, &cpt)) {
			std::cout << "On a teste " << cpt << "/" << nbElem << " cles."
					<< std::endl;
			return cpt == nbElem;
		} else {
			std::cout << "On a teste " << cpt << "/" << nbElem << " cles."
					<< std::endl;
			return 0;
		}
	}

}
;

#endif /* ARBRE_H_ */
