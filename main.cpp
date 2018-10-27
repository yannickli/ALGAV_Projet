/*
 * main.cpp
 *
 *  Created on: 20 oct. 2018
 *      Author: 3520328
 */

#include "Arbre.h"
#include "TasMinTab.h"
#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream fichier("cles_alea/jeu_1_nb_cles_100.txt", ios::in);
	if (fichier) {
		string ligne;

		while (getline(fichier, ligne)) {
			cout << ligne << endl;

		}
		fichier.close();
	} else {
		cout << "Erreur de lecture" << endl;
	}
	return 0;
}

