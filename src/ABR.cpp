/*
 * ABR.cpp
 *
 *  Created on: 19 déc. 2018
 *      Author: yannickli
 */

#include "ABR.h"
#include "md5.h"

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

void ajout(ABR* A, std::string hash, string s, list<string>*l) {
	if (hash.compare(A->etiq) < 0) {
		if (getSousArbreGauche(A)) {
			ajout(getSousArbreGauche(A), hash, s, l);
		} else {
			setSousArbreGauche(A, hash);
			l->push_back(s);
		}
		return;
	}
	if (hash.compare(A->etiq) > 0) {
		if (getSousArbreDroit(A)) {
			ajout(getSousArbreDroit(A), hash, s, l);
		} else {
			setSousArbreDroit(A, hash);
			l->push_back(s);
		}
		return;
	}
}

ABR* consIterABR(vector<Clef *>* vec) {
	ABR * res = new ABR(
			md5(
					to_string(vec->back()->getI1()) + "."
							+ to_string(vec->back()->getI2()) + "."
							+ to_string(vec->back()->getI3()) + "."
							+ to_string(vec->back()->getI4())), nullptr,
			nullptr);
	vec->pop_back();
	for (Clef* c : *vec) {
		ajout(res,
				md5(
						to_string(c->getI1()) + "." + to_string(c->getI2())
								+ "." + to_string(c->getI3()) + "."
								+ to_string(c->getI4())));
	}
	return res;
}

ABR* consIterABR(vector<string>* vec, list<string> *l) {
	//reverse(begin(vec), end(vec));
	ABR * res = new ABR(md5(vec->front()), nullptr, nullptr);
	l->push_back(vec->front());
	for (string s : *vec) {
		ajout(res, md5(s), s, l);
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

int testMD5() {
	string message = "The quick brown fox jumps over the lazy dog";
	cout << message << endl << md5(message) << endl;
	return 0;
}
