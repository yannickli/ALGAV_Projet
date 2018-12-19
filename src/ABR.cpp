/*
 * ABR.cpp
 *
 *  Created on: 19 déc. 2018
 *      Author: yannickli
 */

#include "ABR.h"

ABR::ABR() {

}

ABR::ABR(Clef*x, ABR*A1, ABR*A2) {

}

friend bool estArbreVide(ABR*A) {
	return false;
}
friend Clef * racine(ABR*A) {
	Clef * res = new Clef();

	return res;
}

friend ABR* sousArbreGauche(ABR*A) {
	return A->filsG;
}

friend ABR* sousArbreDroit(ABR*A) {
	return A->filsD;
}
