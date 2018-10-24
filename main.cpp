/*
 * main.cpp
 *
 *  Created on: 20 oct. 2018
 *      Author: 3520328
 */

#include "Arbre.h"

using namespace std;

int main() {
	Clef clef(1, 2, 3, 4);
	Noeud *racine(clef, (Noeud *) nullptr, (Noeud *) nullptr,
			(Noeud *) nullptr);
	Arbre arbre(racine);
}

