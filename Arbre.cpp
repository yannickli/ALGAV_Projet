/*
 * Arbre.cpp
 *
 *  Created on: 12 oct. 2018
 *      Author: 3520328
 */

#include "Noeud.h"
#include "Arbre.h"

Arbre(Clef c, Noeud n) {
	Clef clef = c;
	Noeud racine = n;
	nbElem = 1;
}

unsigned int Arbre::getI1() {
	return clef.i1;
}

unsigned int Arbre::getI2() {
	return clef.i2;
}

unsigned int Arbre::getI3() {
	return clef.i3;
}

unsigned int Arbre::getI4() {
	return clef.i4;
}

bool eg(Arbre a1, Arbre a2) {
	if (a1.getI1() == a2.getI1())
		if (a1.getI2() == a2.getI2())
			if (a1.getI3() == a2.getI3())
				if (a1.getI4() == a2.getI4())
					return true;
	return false;
}

bool inf(Arbre a1, Arbre a2) {
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

void ajout(Noeud n) {
	nbElem++;

}

/*Arbre::Arbre(int n1, int n2, int n3, int n4, Arbre npere, Arbre nfilsG,
 Arbre nfilsD) {
 //bool rempli;
 i1 = n1;
 i2 = n2;
 i3 = n3;
 i4 = n4;
 //pere = npere;
 filsG = nfilsG;
 filsD = nfilsD;
 }

 unsigned int Arbre::getI1() {
 return i1;
 }

 unsigned int Arbre::getI2() {
 return i2;
 }

 unsigned int Arbre::getI3() {
 return i3;
 }

 unsigned int Arbre::getI4() {
 return i4;
 }

 bool eg(Arbre a1, Arbre a2) {
 if (a1.getI1() == a2.getI1())
 if (a1.getI2() == a2.getI2())
 if (a1.getI3() == a2.getI3())
 if (a1.getI4() == a2.getI4())
 return true;
 return false;
 }

 bool inf(Arbre a1, Arbre a2) {
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

 void TrouvePlace()

 void SupprMin(Arbre a) {
 Arbre temp;
 if (a.filsD != nullptr) {
 if (a.filsG != nullptr) {
 if (inf(a.filsG, a.filsD)) {	//Fils gauche est plus petit
 temp=a.filsG;
 a.filsG=a.filsG.filsG;
 a.

 } else {
 if (eg(a.filsG, a.filsD)) {

 }
 }
 } else {

 }
 }

 }*/
