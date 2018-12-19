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

ABR* sousArbreGauche(ABR*A) {
	return A->filsG;
}

ABR* sousArbreDroit(ABR*A) {
	return A->filsD;
}

ABR* ajout(ABR* A, std::string hash) {
	if (hash.compare("")){

	}

}
