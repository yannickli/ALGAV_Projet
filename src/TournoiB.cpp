/*
 * TournoiB.h
 *
 *  Created on: 28 nov. 2018
 *      Author: 3305496
 */

#ifndef SRC_TOURNOIB_CPP_
#define SRC_TOURNOIB_CPP_

#include "FileB.h"
#include "TournoiB.h"

TournoiB::TournoiB() :
		racine(nullptr) {
	fils = new std::list<TournoiB*>();
}

TournoiB::TournoiB(Clef * rac) :
		racine(rac) {
	fils = new std::list<TournoiB*>();
}

Clef *TournoiB::getRacine() {
	return racine;
}

std::list<TournoiB*>* TournoiB::getFils() {
	return fils;
}

void TournoiB::setRacine(Clef *c) {
	racine = c;
}

void TournoiB::setFils(std::list<TournoiB*> *lfils) {
	fils = lfils;
}

void TournoiB::addFils(TournoiB*t) {
	fils->push_front(t);
}

bool estVide(TournoiB*b) {
	if (b->getRacine() == nullptr)
		return true;
	return false;
}

int degre(TournoiB*b) {
	return b->getFils()->size();
}

//Union de 2 tournois de meme taille
TournoiB *union2Tid(TournoiB *t1, TournoiB *t2) {
	TournoiB * res = new TournoiB();
	if (*t1->getRacine() < *t2->getRacine()) {
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
// Renvoie la file binomiale obtenue en supprimant la racine du tournoi
FileB * decapite(TournoiB *t) {
	FileB* res = new FileB(t->getFils());
	return res;
}

FileB * toFile(TournoiB *t) {
	std::list<TournoiB *> *liste = new std::list<TournoiB*>();
	liste->push_back(t);
	FileB* res = new FileB(liste);
	return res;
}

void afficher(TournoiB *tb) {
	if (tb->racine) {
		tb->racine->afficher();
		for (TournoiB *b : *tb->getFils())
			afficher(b);
	}
}

#endif /* SRC_TOURNOIB_CPP_ */
