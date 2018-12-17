/*
 * TournoiB.h
 *
 *  Created on: 28 nov. 2018
 *      Author: 3305496
 */

#ifndef SRC_TOURNOIB_H_
#define SRC_TOURNOIB_H_

#include <list>
#include "Clef.h"
#include "FileB.h"

class TournoiB {
private:
	Clef * racine;
	std::list<TournoiB*> *fils;
public:
	TournoiB() :
			racine(nullptr) {
		fils = new std::list<TournoiB*>();
	}

	TournoiB(Clef * rac) :
			racine(rac) {
		fils = new std::list<TournoiB*>();
	}

	Clef *getRacine() {
		return racine;
	}

	std::list<TournoiB*>* getFils() {
		return fils;
	}

	void setRacine(Clef *c) {
		racine = c;
	}

	void setFils(std::list<TournoiB*> *lfils) {
		fils = lfils;
	}

	void addFils(TournoiB*t) {
		fils->push_front(t);
	}

	friend bool estVide(TournoiB*b) {
		if (b->getRacine() == nullptr)
			return true;
		return false;
	}

	friend int degre(TournoiB*b) {
		return b->getFils()->size();
	}

	//Union de 2 tournois de meme taille
	friend TournoiB *union2Tid(TournoiB *t1, TournoiB *t2) {
		TournoiB * res = new TournoiB();
		if (t1->getRacine() < t2->getRacine()) {
			res->setRacine(t1->getRacine());
			res->setFils(t1->getFils());
			res->addFils(t2);
		} else {
			res->setRacine(t2->getRacine());
			res->setFils(t2->getFils());
			res->addFils(t1);
		}
		return res;
	}

	friend FileB *decapite(TournoiB *t);

	friend FileB *toFile(TournoiB *t);

};

#endif /* SRC_TOURNOIB_H_ */
