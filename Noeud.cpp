/*
 * Noeud.cpp
 *
 *  Created on: 13 oct. 2018
 *      Author: 3520328
 */

#include "Noeud.h"
#include <vector>

static int cpt = 1;

Noeud(int n1, int n2, int n3, int n4, Noeud nfilsG,
		Noeud nfilsD) {
	bool rempli = false; //ne vaut true que si le noeud possède 2 fils
	int id = cpt;
	cpt ++;
	i1 = n1;
	i2 = n2;
	i3 = n3;
	i4 = n4;
	filsG = nfilsG;
	filsD = nfilsD;

	if(filsG != nullptr || filsD != nullptr) {
		rempli = true;
	}
}

bool getRempli() {
	return rempli;
}

unsigned int getI1() {
	return i1;
}

unsigned int getI2() {
	return i2;
}

unsigned int getI3() {
	return i3;
}

unsigned int getI4() {
	return i4;
}

bool eg(Noeud a1, Noeud a2) {
	if (a1.getI1() == a2.getI1())
		if (a1.getI2() == a2.getI2())
			if (a1.getI3() == a2.getI3())
				if (a1.getI4() == a2.getI4())
					return true;
	return false;
}

bool inf(Noeud a1, Noeud a2) {
	if (a1.getI1() < a2.getI1())
		return true;
	if (a1.getI1() > a2.getI1())
		return false;
	if (a1.getI2() < a2.getI2())
		return true;
	if (a1.getI2() > a2.getI2())
		return false;
	if (a1.getI3() < a2.getI3())
		return true;
	if (a1.getI3() > a2.getI3())
		return false;
	if (a1.getI4() < a2.getI4())
		return true;
	if (a1.getI4() > a2.getI4())
		return false;
	return false;
}

void Ajout(Noeud racine, Noeud n) { //marche pas encore
	/*if(!racine.rempli){
	 if(racine.filsG != nullptr){
	 racine.filsD = n; //on place dans le fils droit
	 }else{
	 racine.filsG = n; //on place dans le fils gauche
	 }
	 }else{
	 Ajout(racine.filsG, n);
	 }*/

	std::vector<int> instructions(1);
	//cpt/2 -> 0 ou 1 dans le tab, selon si le res est pair ou impair
	//on lit le tableau à l'envres pour avoir le chemin de la racine au dernier element

}

void SupprMin(Noeud n) {
	Noeud gauche = n.filsG;
	Noeud droit = n.filsD;
	Noeud temp = n;

	if (!n.rempli) {
		if (n.filsG != nullptr) {

		} else {

		}
	}

	1
	2
	3
	4
	5
	6
	7
	8
	9
	10
	11
	12
	13
	14
	15

//void SupprMin(Noeud a) {
	Noeud temp;
	if (a.filsD != nullptr) {
		if (a.filsG != nullptr) {
			if (inf(a.filsG, a.filsD)) {	//Fils gauche est plus petit
				temp = a.filsG;
				a.filsG = a.filsG.filsG;
			a.

		} else {
			if (eg(a.filsG, a.filsD)) {

			}
		}
	} else {

	}
}

}
