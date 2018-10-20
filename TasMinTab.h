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
	std::vector<Noeud> tas;
public:
	TasMin_Tab(std::vector<Noeud> tab) :
			tas(tab) {
	}
};

#endif /* TASMINTAB_H_ */
