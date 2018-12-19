/*
 * TasMinTab.h
 *
 *  Created on: 15 oct. 2018
 *      Author: 3305496
 */

#ifndef TASMINTAB_H_
#define TASMINTAB_H_

#include "Noeud.h"
#include <vector>
#include <cmath>
#include <ctgmath>
#include <iostream>

class TasMinTab {
private:
	std::vector<Clef*> tab;
	int nbElem;
public:
	TasMinTab() :
			nbElem(0) {
	}
	int getNbElem() {
		return nbElem;
	}
	int pere(int i) {
		return (i - 1) / 2;
	}
	int filsG(int i) {
		return 2 * i + 1;
	}
	int filsD(int i) {
		return 2 * i + 2;
	}
	void supprMin() {
		tab[0] = tab[nbElem - 1];
		tab.pop_back();
		nbElem--;
		redescendre(0);
	}
	void redescendre(int i) {
		if (filsD(i) <= nbElem - 1) {
			if (*(tab[filsG(i)]) < *(tab[filsD(i)])) {
				if (*(tab[filsG(i)]) < *(tab[i])) {
					swap(filsG(i), i);
					redescendre(filsG(i));
				}
			} else {
				if (*(tab[filsD(i)]) < *(tab[i])) {
					swap(filsD(i), i);
					redescendre(filsD(i));
				}
			}
		} else if (filsG(i) <= nbElem - 1) {
			if (*(tab[filsG(i)]) < *(tab[i])) {
				swap(filsG(i), i);
				redescendre(filsG(i));
			}
		}
	}
	void swap(int c1, int c2) {
		Clef *tmp = tab[c1];
		tab[c1] = tab[c2];
		tab[c2] = tmp;
	}
	void ajout(Clef *c) {
		tab.push_back(c);
		nbElem++;
		remonter(nbElem - 1);
	}
	void remonter(int i) {
		if (i > 0) {
			if (*(tab[i]) < *(tab[pere(i)])) {
				swap(i, pere(i));
				remonter(pere(i));
			}
		}
	}
	void consIterTab(std::vector<Clef*> *elm) {
		for (Clef *it : *elm) {
			tab.push_back(it);
			nbElem++;
		}
		int hauteur = log2(nbElem);
		for (int i = pow(2, hauteur) - 2; i >= 0; i--) {
			redescendre(i);
		}
	}
	friend TasMinTab* union2Tab(TasMinTab t1, TasMinTab t2) {
		std::vector<Clef*> v1 = t1.tab;
		std::vector<Clef*> v2 = t2.tab;
		TasMinTab * res = new TasMinTab();
		v1.insert(v1.end(), v2.begin(), v2.end());
		res->consIterTab(&v1);
		return res;
	}
	void afficher() {
		for (int i = 0; i < nbElem; i++)
			tab[i]->afficher();
		std::cout << "Il y a " << nbElem << " cles." << std::endl;
	}
	bool testN(int i, int *nb) {
		int fg = filsG(i);
		int fd = filsD(i);
		(*nb)++;
		if (fg < nbElem) {
			if (fd < nbElem) {
				/*std::cout << "Je suis : " << tab[i] << "; Mon fils gauche : "
				 << tab[fg] << "; Mon fils droit : " << tab[fd]
				 << std::endl;*/
				if (*(tab[i]) < *(tab[fg]) && *(tab[i]) < *(tab[fd])) {
					if (testN(fg, nb) && testN(fd, nb)) {
						return true;
					} else {
						return false;
					}
				} else {
					return false;
				}
			} else {
				if (*(tab[i]) < *(tab[fg])) {
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
// La fonction retourne le nombre de noeud teste
	int tester() {
		int cpt = 0;
		if (testN(0, &cpt)) {
			if (cpt != nbElem) {
				std::cout << "pb ici" << std::endl;
				std::cout << "On a teste " << cpt << "/" << nbElem << " cles."
						<< std::endl;
				return 0;
			}
			//std::cout << "Structure OK" << std::endl;
			return cpt == nbElem;
		} else {
			std::cout << "On a teste " << cpt << "/" << nbElem << " cles."
					<< std::endl;
			return 0;
		}
	}

};

#endif /* TASMINTAB_H_ */
