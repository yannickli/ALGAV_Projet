/*
 * ABR.cpp
 *
 *  Created on: 19 déc. 2018
 *      Author: yannickli
 */

#include "ABR.h"

using namespace std;

ABR::ABR(string s, ABR*A1, ABR*A2) :
		etiq(s), filsG(A1), filsD(A2) {
}

bool estFeuille(ABR*A) {
	return ((A->filsG) == nullptr && (A->filsD) == nullptr);
}

std::string getEtiquette(ABR*A) {
	return A->etiq;
}

ABR* getSousArbreGauche(ABR*A) {
	return A->filsG;
}

ABR* getSousArbreDroit(ABR*A) {
	return A->filsD;
}

void setEtiquette(ABR*A, string s) {
	A->etiq = s;
}

void setSousArbreGauche(ABR*A, string s) {
	A->filsG = new ABR(s, nullptr, nullptr);
}

void setSousArbreDroit(ABR*A, string s) {
	A->filsD = new ABR(s, nullptr, nullptr);
}

void ajout(ABR* A, std::string hash) {
	if (hash.compare(A->etiq) < 0) {
		if (getSousArbreGauche(A)) {
			ajout(getSousArbreGauche(A), hash);
		} else {
			setSousArbreGauche(A, hash);
		}
		return;
	}
	if (hash.compare(A->etiq) > 0) {
		if (getSousArbreDroit(A)) {
			ajout(getSousArbreDroit(A), hash);
		} else {
			setSousArbreDroit(A, hash);
		}
		return;
	}
}

ABR* consIterABR(vector<Clef *>* vec) {
	ABR * res = new ABR(
			to_string(vec->back()->getI1()) + "."
					+ to_string(vec->back()->getI2()) + "."
					+ to_string(vec->back()->getI3()) + "."
					+ to_string(vec->back()->getI4()), nullptr, nullptr);
	vec->pop_back();
	for (Clef* c : *vec) {
		ajout(res,
				to_string(c->getI1()) + "." + to_string(c->getI2()) + "."
						+ to_string(c->getI3()) + "." + to_string(c->getI4()));
	}
	return res;
}

void afficher(ABR *A) {
	if (A == nullptr)
		return;
	afficher(A->filsG);
	cout << A->etiq << endl;
	afficher(A->filsD);
}
