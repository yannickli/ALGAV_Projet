/*
 * FileB.h
 *
 *  Created on: 28 nov. 2018
 *      Author: 3305496
 */

#ifndef SRC_FILEB_H_
#define SRC_FILEB_H_

#include "TournoiB.h"
#include <list>

class FileB {
private:
	std::list<TournoiB *> *file;
public:
	FileB() {
		file = new std::list<TournoiB*>();
	}

	FileB(std::list<TournoiB *> *liste) {
		file = liste;
	}

	std::list<TournoiB*> * getFile() {
		return file;
	}

	friend bool estVide(FileB *f) {
		return f->getFile()->size() == 0;
	}

	friend TournoiB *minDeg(FileB *f) {
		std::list<TournoiB*> *liste = f->getFile();
		TournoiB * mint = liste->back();
		int min = degre(mint);

		for (TournoiB *t : liste) {
			if (degre(t) < min) {
				mint = t;
				mint = degre(t);
			}
		}
		return mint;
	}

	friend FileB *reste(FileB *f) {
		FileB *ff = f;
		ff->getFile()->remove(minDeg(&f));
		return ff;
	}

	FileB ajoutMin(TournoiB t, FileB f) {
		f.getFile().emplace_back(t);
		return f;
	}
};

#endif /* SRC_FILEB_H_ */
