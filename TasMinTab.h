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

class TasMin_Tab {
private:
	std::vector<Noeud> tab;
	int nbElement;
public:
	TasMin_Tab(int i) :
			tab(i) {
	}
	TasMin_Tab(std::vector<Noeud> tab) :
			tab(tab) {
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
	void swap(int s1, int s2) {

	}
};

#endif /* TASMINTAB_H_ */
