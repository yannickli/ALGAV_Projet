/*
 * TournoiB.h
 *
 *  Created on: 28 nov. 2018
 *      Author: 3305496
 */

#ifndef SRC_TOURNOIB_CPP_
#define SRC_TOURNOIB_CPP_

#include <list>
#include "Clef.h"
#include "TournoiB.h"
#include "FileB.h"

FileB * TournoiB::decapite(TournoiB *t) {
	FileB* res = new FileB(t->getFils());
	return res;
}

FileB * TournoiB::toFile(TournoiB *t) {
	std::list<TournoiB *> *liste = new std::list<TournoiB*>();
	liste->push_back(t);
	FileB* res = new FileB(liste);
	return res;
}

#endif /* SRC_TOURNOIB_CPP_ */
