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
#include <vector>
#include "Clef.h"
#include <sstream>
#include "Noeud.h"

using namespace std;


int main() {
	ifstream fichier("cles_alea/jeu_1_nb_cles_100.txt", ios::in);
	if (fichier) {
		string ligne;
		vector<Clef> tab;
		char ci1[11], ci2[11], ci3[11], ci4[11];
		unsigned int i1 = 0, i2 = 0, i3 = 0, i4 = 0;

		while (getline(fichier, ligne)) {
			stringstream ss1, ss2, ss3, ss4;
			ligne.copy(ci1, 10, 0);
			ci1[10] = '\0';
			ss1 << std::hex << ci1;
			ss1 >> i1;

			ligne.copy((ci2 + 2), 8, 10);
			ci2[0] = '0';
			ci2[1] = 'x';
			ci2[10] = '\0';
			ss2 << std::hex << ci2;
			ss2 >> i2;

			ligne.copy((ci3 + 2), 8, 18);
			ci3[0] = '0';
			ci3[1] = 'x';
			ci3[10] = '\0';
			ss3 << std::hex << ci3;
			ss3 >> i3;

			ligne.copy((ci4 + 2), 8, 26);
			ci4[0] = '0';
			ci4[1] = 'x';
			ci4[10] = '\0';
			ss4 << std::hex << ci4;
			ss4 >> i4;

			Clef * c = new Clef(i1, i2, i3, i4);
			tab.push_back(*c);
			//cout << *c << endl;
		}
		fichier.close();
		TasMinTab * tasMinTab = new TasMinTab();
		tasMinTab->constIter(tab);
		std::cout << *tasMinTab << endl;
	} else {
		cout << "Erreur de lecture" << endl;
	}
	return 0;
}

