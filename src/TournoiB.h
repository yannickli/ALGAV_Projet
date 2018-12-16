/*
 * TournoiB.h
 *
 *  Created on: 28 nov. 2018
 *      Author: 3305496
 */

#ifndef SRC_TOURNOIB_H_
#define SRC_TOURNOIB_H_

#include "NoeudT.h"
#include <vector>

class TournoiB {
private:
	int nbElem;
	NoeudT* racine;
	std::vector<NoeudT*> fils = { };
public:
	TournoiB() :
			nbElem(0), racine(nullptr) {

	}

	TournoiB(NoeudT* racine) :
			nbElem(1), racine(racine) {
		fils.emplace_back(racine);
	}

	std::vector<NoeudT*> getFils() {
		return fils;
	}

	bool estVide() {
		if (nbElem > 0)
			return false;
		return true;
	}

	int degre() {
		return nbElem;
	}

	void union2Tid(TournoiB t) {
		for (NoeudT* n : t.getFils()) {
			fils.emplace_back(n);
		}
		t.racine->setPere(racine);
		racine->ajout(t.racine);
		nbElem *= 2;
	}

	FileB decapite() {
		std::vector<TournoiB> tb;
		for (NoeudT nt : fils) {
			tb.emplace_back(new TournoiB(nt));
		}
		FileB fb(tb);
		return fb;
	}

	FileB file() {
		std::vector<TournoiB> tb = { racine };
		FileB fb(tb);
		return fb;
	}

};

#endif /* SRC_TOURNOIB_H_ */
