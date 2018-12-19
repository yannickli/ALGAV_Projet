/*
 * FileB.cpp
 *
 *  Created on: 18 déc. 2018
 *      Author: yannickli
 */

#ifndef SRC_FILEB_CPP_
#define SRC_FILEB_CPP_

#include "FileB.h"
#include "TournoiB.h"
#include <stdio.h>
#include <cmath>

using namespace std;

FileB::FileB() {
	file = new std::list<TournoiB*>();
}

FileB::FileB(std::list<TournoiB *> *liste) {
	file = liste;
}

std::list<TournoiB*> * FileB::getFile() {
	return file;
}

bool estVide(FileB *f) {
	return f->getFile()->size() == 0;
}

// Renvoie le tournoi de degre minimal dans la file
TournoiB *minDeg(FileB *f) {
	return f->getFile()->back();
}

// Renvoie la file privee de son tournoi de degre minimal
FileB *reste(FileB *f) {
	std::list<TournoiB *> *liste = f->getFile();
	liste->pop_back();
	return new FileB(liste);
}

// Hypothese : le tournoi de degre inferieur au MinDeg de la file
// Renvoie la file obtenue en ajoutant le tournoi comme
// tournoi de degre minimal de la file initiale.
FileB *ajoutMin(TournoiB *t, FileB *f) {
	FileB * ff = f;
	ff->getFile()->push_back(t);
	return ff;
}

FileB * unionFile(FileB * F1, FileB * F2) {
	TournoiB * T = new TournoiB();
	FileB * b = uFret(F1, F2, T);
	return b;
}

FileB * uFret(FileB *F1, FileB *F2, TournoiB *T) {
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
			return ajoutMin(T, uFret(reste(F1), reste(F2), union2Tid(T1, T2)));
		if (degre(T) == degre(T1) && degre(T) < degre(T2))
			return uFret(reste(F1), F2, union2Tid(T1, T));
		if (degre(T) == degre(T2) && degre(T) < degre(T1))
			return uFret(reste(F2), F1, union2Tid(T2, T));
	}
	perror("Probleme UFret");
	exit(70);
	return nullptr;
}

void afficher(FileB*F) {
	for (TournoiB * tb : *F->getFile()) {
		//cout << tb->getFils()->size() << endl;
		cout << ">>" << endl;
		afficher(tb);
	}
}

void afficherTaille(FileB*F) {
	int cpt = 0;
	for (TournoiB * tb : *F->getFile()) {
		cpt += pow(2, tb->getFils()->size());
		cout << tb->getFils()->size() << endl;
	}
	cout << "cpt = " << cpt << endl;
}

FileB * supprMin(FileB * F) {
	FileB * res = new FileB();
	TournoiB* tb = minDeg(F);
	FileB* fb = reste(F);
	res = unionFile(fb, decapite(tb));
	return res;
}

FileB* ajout(FileB * F, Clef *C) {
	FileB * res = new FileB();
	TournoiB *tb = new TournoiB(C);
	res = unionFile(F, toFile(tb));
	return res;
}

FileB* consIterFileB(std::vector<Clef *>* v) {
	FileB * res = new FileB();
	for (Clef *c : *v) {
		FileB *nouv = toFile(new TournoiB(c));
		res = unionFile(res, nouv);
	}
	return res;
}

#endif /* SRC_FILEB_CPP_ */
