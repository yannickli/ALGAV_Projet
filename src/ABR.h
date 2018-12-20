/*
 * ABR.h
 *
 *  Created on: 19 déc. 2018
 *      Author: yannickli
 */

#ifndef SRC_ABR_H_
#define SRC_ABR_H_
#include "Clef.h"
#include <vector>
#include <cstring>
#include <list>
#include <algorithm>
#include <iterator>
#include <iostream>

class ABR {
	std::string etiq;
	ABR * filsG;
	ABR * filsD;
public:
	ABR(std::string s, ABR*A1, ABR*A2);

	friend bool estFeuille(ABR*A);

	friend std::string getEtiquette(ABR*A);

	friend ABR* getSousArbreGauche(ABR*A);

	friend ABR* getSousArbreDroit(ABR*A);

	friend void setEtiquette(ABR*A, std::string s);

	friend void setSousArbreGauche(ABR*A, std::string s);

	friend void setSousArbreDroit(ABR*A, std::string s);

	friend void ajout(ABR* A, std::string hash);

	friend void ajout(ABR* A, std::string hash, std::string s,
			std::list<std::string>*l);

	friend ABR* consIterABR(std::vector<Clef *>* vec);

	friend ABR* consIterABR(std::vector<std::string>* vec,
			std::list<std::string> *l);

	friend void afficher(ABR *A);
};

bool estFeuille(ABR*A);

std::string getEtiquette(ABR*A);

ABR* getSousArbreGauche(ABR*A);

ABR* getSousArbreDroit(ABR*A);

void setEtiquette(ABR*A, std::string s);

void setSousArbreGauche(ABR*A, std::string s);

void setSousArbreDroit(ABR*A, std::string s);

void ajout(ABR* A, std::string hash);

void ajout(ABR* A, std::string hash, std::string s, std::list<std::string>*l);

ABR* consIterABR(std::vector<Clef *>* vec);

ABR* consIterABR(std::vector<std::string>* vec, std::list<std::string> *l);

void afficher(ABR *A);

int testMD5();

#endif /* SRC_ABR_H_ */
