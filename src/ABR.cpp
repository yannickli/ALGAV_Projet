/*
 * ABR.cpp
 *
 *  Created on: 19 déc. 2018
 *      Author: yannickli
 */

#include "ABR.h"

ABR::ABR() :
		clef(nullptr), filsG(nullptr), filsD(nullptr) {
}

ABR::ABR(Clef*x, ABR*A1, ABR*A2) :
		clef(x), filsG(A1), filsD(A2) {
}

bool estArbreVide(ABR*A) {
	return A->clef == nullptr;
}
Clef * racine(ABR*A) {
	return A->clef;
}

ABR* sousArbreGauche(ABR*A) {
	return A->filsG;
}

ABR* sousArbreDroit(ABR*A) {
	return A->filsD;
}
