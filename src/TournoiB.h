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

class FileB;

class TournoiB {
	Clef * racine;
	std::list<TournoiB*> *fils;
public:
	TournoiB();

	TournoiB(Clef * rac);

	Clef *getRacine();

	std::list<TournoiB*>* getFils();

	void setRacine(Clef *c);

	void setFils(std::list<TournoiB*> *lfils);

	void addFils(TournoiB*t);

	friend bool estVide(TournoiB*b);

	friend int degre(TournoiB*b);

	//Union de 2 tournois de meme taille
	friend TournoiB *union2Tid(TournoiB *t1, TournoiB *t2);

	friend FileB *decapite(TournoiB *t);

	friend FileB *toFile(TournoiB *t);

	friend void afficher(TournoiB *tb);
};

bool estVide(TournoiB*b);

int degre(TournoiB*b);

//Union de 2 tournois de meme taille
TournoiB *union2Tid(TournoiB *t1, TournoiB *t2);

FileB *decapite(TournoiB *t);

FileB *toFile(TournoiB *t);

void afficher(TournoiB *tb);

#endif /* SRC_TOURNOIB_H_ */
