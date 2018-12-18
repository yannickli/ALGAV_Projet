/*
 * FileB.h
 *
 *  Created on: 28 nov. 2018
 *      Author: 3305496
 */

#ifndef SRC_FILEB_H_
#define SRC_FILEB_H_

#include <list>

class TournoiB;

class FileB {
	std::list<TournoiB *> *file;
public:
	FileB();

	FileB(std::list<TournoiB *> *liste);

	std::list<TournoiB*> * getFile();

	friend bool estVide(FileB *f);

	friend TournoiB *minDeg(FileB *f);

	friend FileB *reste(FileB *f);

	friend FileB *ajoutMin(TournoiB *t, FileB *f);

	friend FileB * unionFile(FileB * F1, FileB * F2);

	friend FileB * uFret(FileB *F1, FileB *F2, TournoiB *T);

	friend void afficher(FileB*F);

	friend void afficherTaille(FileB*F);
};

#endif /* SRC_FILEB_H_ */
