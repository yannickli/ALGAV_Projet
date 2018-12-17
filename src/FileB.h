/*
 * FileB.h
 *
 *  Created on: 28 nov. 2018
 *      Author: 3305496
 */

#ifndef SRC_FILEB_H_
#define SRC_FILEB_H_

#include <list>
#include "TournoiB.h"

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
		return f->getFile()->back();
	}

	friend FileB *reste(FileB *f) {
		std::list<TournoiB *> *liste = f->getFile();
		liste->pop_back();
		return new FileB(liste);
	}

	friend FileB *ajoutMin(TournoiB *t, FileB *f) {
		FileB * ff = f;
		ff->getFile()->push_back(t);
		return ff;
	}

	friend FileB * unionFile(FileB * F1, FileB * F2) {
		TournoiB * T = new TournoiB();
		FileB * b = uFret(F1, F2, T);
		return b;
	}

	friend FileB * uFret(FileB *F1, FileB *F2, TournoiB *T) {
		if (estVide(T)) {
			if (estVide(F1))
				return F2;
			if (estVide(F2))
				return F1;
			TournoiB *T1 = minDeg(F1);
			TournoiB *T2 = minDeg(F2);
			if (degre(T1) < degre(T2))
				return ajoutMin(T1, unionFile(reste(F1), F2));
			if (degre(T2) < degre(T1))
				return ajoutMin(T2, unionFile(reste(F2), F1));
			if (degre(T1) == degre(T2))
				return uFret(reste(F1), reste(F2), union2Tid(T1, T2));
		} else {
			if (estVide(F1))
				return unionFile(toFile(T), F2);
			if (estVide(F2))
				return unionFile(toFile(T), F1);
			TournoiB *T1 = minDeg(F1);
			TournoiB *T2 = minDeg(F2);
			if (degre(T) < degre(T1) && degre(T) < degre(T2))
				return ajoutMin(T, unionFile(F1, F2));
			if (degre(T) == degre(T1) && degre(T) == degre(T2))
				return ajoutMin(T,
						uFret(reste(F1), reste(F2), union2Tid(T1, T2)));
			if (degre(T) == degre(T1) && degre(T) < degre(T2))
				return uFret(reste(F1), F2, union2Tid(T1, T));
			if (degre(T) == degre(T2) && degre(T) < degre(T1))
				return uFret(reste(F2), F1, union2Tid(T2, T));
		}
		perror("Probleme UFret");
		exit(70);
		return nullptr;
	}

};

#endif /* SRC_FILEB_H_ */
