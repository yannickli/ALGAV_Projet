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
	std::vector<Clef> tab;
	int nbElement;
public:
	TasMinTab() :
			nbElement(0) {
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
		tab[0] = tab[nbElement - 1];
		tab.pop_back();
		nbElement--;
		redescendre(0);
	}
	void redescendre(int i) {
		if (filsD(i) <= nbElement - 1) {
			if (tab[filsG(i)] < tab[filsD(i)]) {
				if (tab[filsG(i)] < tab[i]) {
					swap(filsG(i), i);
					redescendre(filsG(i));
				}
			} else {
				if (tab[filsD(i)] < tab[i]) {
					swap(filsD(i), i);
					redescendre(filsD(i));
				}
			}
		} else if (filsG(i) <= nbElement - 1) {
			if (tab[filsG(i)] < tab[i]) {
				swap(filsG(i), i);
				redescendre(filsG(i));
			}
		}
	}
	void swap(int c1, int c2) {
		Clef tmp = tab[c1];
		tab[c1] = tab[c2];
		tab[c2] = tmp;
	}
	void ajout(Clef c) {
		tab.push_back(c);
		nbElement++;
		remonter(nbElement - 1);
	}
	void remonter(int i) {
		if (i > 0) {
			if (tab[i] < tab[pere(i)]) {
				swap(i, pere(i));
				remonter(pere(i));
			}
		}
	}
	void constIter(std::vector<Clef> elm) {
		for (Clef it : elm) {
			tab.push_back(it);
		}
		int hauteur = log2(nbElement);
		for (int i = pow(2, hauteur) - 2; i >= 0; i--) {
			redescendre(i);
		}
	}
	void unionTas(TasMinTab t) {
		constIter(t.tab);
	}
	void afficher() {
		std::cout << *this << std::endl;
	}
	bool testN(int i, int *nb) {
		int fg = filsG(i);
		int fd = filsD(i);
		(*nb)++;
		if (fg) {
			if (fd) {
				if (tab[i] < tab[fg] && tab[i] < tab[fd]) {
					if (testN(fd, nb) && testN(fg, nb)) {
						return true;
					} else {
						return false;
					}
				} else {
					return false;
				}
			} else {
				if (tab[i] < tab[fg]) {
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
		int nbNoeud = 0;
		if (testN(0, &nbNoeud))
			return nbNoeud;
		else
			return 0;
	}

	friend std::ostream& operator<<(std::ostream& os, const TasMinTab& t);
};

#endif /* TASMINTAB_H_ */
