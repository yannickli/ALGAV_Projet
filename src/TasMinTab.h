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

	void supprMin() {
		tab[0] = tab[nbElement - 1];
		redescendre(0);
		nbElement--;
	}
	void redescendre(int i) {
		if (2 * i + 2 <= nbElement - 1) {
			if (tab[2 * i + 1] < tab[2 * i + 2]) {
				if (tab[2 * i + 1] < tab[i]) {
					swap(2 * i + 1, i);
					redescendre(2 * i + 1);
				}
			} else {
				if (tab[2 * i + 2] < tab[i]) {
					swap(2 * i + 2, i);
					redescendre(2 * i + 2);
				}
			}
		} else if (2 * i + 1 <= nbElement - 1) {
			if (tab[2 * i + 1] < tab[i]) {
				swap(2 * i + 1, i);
				redescendre(2 * i + 1);
			}
		}
	}
	void swap(int c1, int c2) {
		Clef tmp = tab[c1];
		tab[c1] = tab[c2];
		tab[c2] = tmp;
	}
	void Ajout(Clef c) {
		nbElement++;
		tab.push_back(c);
		remonter(nbElement - 1);
	}
	void remonter(int i) {
		if (i > 0) {
			if (i % 2) {
				if (tab[i] < tab[i / 2]) {
					swap(i, i / 2);
					remonter(i / 2);
				}
			} else {
				if (tab[i] < tab[(i - 2) / 2]) {
					swap(i, (i - 2) / 2);
					remonter((i - 2) / 2);
				}
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
	friend std::ostream& operator<<(std::ostream& os, const TasMinTab& t);
};

#endif /* TASMINTAB_H_ */
