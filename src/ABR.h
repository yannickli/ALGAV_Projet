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

class ABR {
	std::string etiq;
	ABR * filsG;
	ABR * filsD;
public:
	ABR(std::string s, ABR*A1, ABR*A2);

	friend bool estFeuille(ABR*A);

	friend std::string getEtiquette(ABR*A);

	friend ABR* sousArbreGauche(ABR*A);

	friend ABR* sousArbreDroit(ABR*A);

	friend ABR* ajout(ABR* A, std::string hash);
};

bool estFeuille(ABR*A);

std::string getEtiquette(ABR*A);

ABR* sousArbreGauche(ABR*A);

ABR* sousArbreDroit(ABR*A);

ABR* ajout(ABR* A, std::string hash);

#endif /* SRC_ABR_H_ */
