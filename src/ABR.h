/*
 * ABR.h
 *
 *  Created on: 19 déc. 2018
 *      Author: yannickli
 */

#ifndef SRC_ABR_H_
#define SRC_ABR_H_
#include "Clef.h"

class ABR {
	Clef * clef;
	ABR * filsG;
	ABR * filsD;
public:
	ABR();

	ABR(Clef*x, ABR*A1, ABR*A2);

	friend bool estArbreVide(ABR*A);

	friend Clef * racine(ABR*A);

	friend ABR* sousArbreGauche(ABR*A);

	friend ABR* sousArbreDroit(ABR*A);
};

bool estArbreVide(ABR*A);

Clef * racine(ABR*A);

ABR* sousArbreGauche(ABR*A);

ABR* sousArbreDroit(ABR*A);

#endif /* SRC_ABR_H_ */
