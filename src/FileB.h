/*
 * FileB.h
 *
 *  Created on: 28 nov. 2018
 *      Author: 3305496
 */

#ifndef SRC_FILEB_H_
#define SRC_FILEB_H_

#include "TournoiB.h"
#include <vector>

class FileB {
private:
	std::vector<TournoiB> file = { };
public:
	FileB() {
	}

	FileB(std::vector<TournoiB> file) :
			file(file) {
	}

	bool estVide() {
		return file.empty();
	}

	std::vector<TournoiB> getFile() {
		return file;
	}

	TournoiB minDef() {
		int min = file[0].degre();
		TournoiB mint = file[0];
		for (TournoiB t : file) {
			if (t.degre() < min) {
				min = t.degre();
				mint = t;
			}
		}
		return mint;
	}

	FileB reste() {
		int indice = 0;
		int indiceT = 0;
		int min = file[0].degre();
		TournoiB mint = file[0];
		for (TournoiB t : file) {
			if (t.degre() < min) {
				min = t.degre();
				mint = t;
				indiceT = indice;
			}
			indice++;
		}
		file.erase(file.begin() + indiceT);
		return this;
	}

	FileB ajoutMin(TournoiB t, FileB f) {
		f.getFile().emplace_back(t);
		return f;
	}
};

#endif /* SRC_FILEB_H_ */
