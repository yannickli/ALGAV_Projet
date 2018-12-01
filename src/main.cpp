/*
 * main.cpp
 *
 *  Created on: 20 oct. 2018
 *      Author: 3520328
 */

#include "TasMinTab.h"
#include <iostream>
#include <fstream>
#include <vector>
#include "Clef.h"
#include <sstream>
#include "Noeud.h"
#include "TasMinArbre.h"

using namespace std;

int main() {
	//lireFichier();
	cout << "test" << endl;
	Clef *c1 = new Clef(1, 2, 3, 4);
	Noeud* filsG = new Noeud(*c1);
	Noeud* filsD = new Noeud(*new Clef(5, 6, 7, 8));
	Noeud* pere = new Noeud(*new Clef(9, 10, 11, 12));
	TasMinArbre arbre = *new TasMinArbre(pere);
	cout << "test" << endl;
	arbre.ajouter(filsG);
	cout << "test" << endl;
	bool test1 = filsG->suisJeLeFilsGauche();
	bool test2 = filsD->suisJeLeFilsDroit();
	cout << "test" << endl;
	cout << test1 << endl;
	cout << test2 << endl;
	return 0;
}

int lireFichier() {
	ifstream fichier("cles_alea/jeu_1_nb_cles_100.txt", ios::in);
	if (fichier) {
		string ligne;
		vector<Clef> tab;
		char ci1[11], ci2[11], ci3[11], ci4[11];
		unsigned int i1 = 0, i2 = 0, i3 = 0, i4 = 0;

		while (getline(fichier, ligne)) {
			stringstream ss1, ss2, ss3, ss4;
			int t1, t2, t3, t4;
			int taille = ligne.size() - 2;
			if (taille < 8) {
				t4 = taille;
				t3 = 0;
				t2 = 0;
				t1 = 0;
			} else {
				taille -= 8;
				if (taille < 8) {
					t4 = 8;
					t3 = taille;
					t2 = 0;
					t1 = 0;
				} else {
					taille -= 8;
					if (taille < 8) {
						t4 = 8;
						t3 = 8;
						t2 = taille;
						t1 = 0;
					} else {
						t4 = 8;
						t3 = 8;
						t2 = 8;
						t1 = taille - 8;
					}
				}
			}

			ligne.copy(ci1 + 2 + 8 - t1, t1, 2);
			ci1[0] = '0';
			ci1[1] = 'x';
			for (int i = 0; i < 8 - t1; i++) {
				ci1[2 + i] = '0';
			}
			ci1[10] = '\0';
			ss1 << std::hex << ci1;
			ss1 >> i1;

			ligne.copy((ci2 + 2 + 8 - t2), t2, 2 + t1);
			ci2[0] = '0';
			ci2[1] = 'x';
			for (int i = 0; i < 8 - t2; i++) {
				ci2[2 + i] = '0';
			}
			ci2[10] = '\0';
			ss2 << std::hex << ci2;
			ss2 >> i2;

			ligne.copy((ci3 + 2 + 8 - t3), t3, 2 + t1 + t2);
			ci3[0] = '0';
			ci3[1] = 'x';
			for (int i = 0; i < 8 - t3; i++) {
				ci3[2 + i] = '0';
			}
			ci3[10] = '\0';
			ss3 << std::hex << ci3;
			ss3 >> i3;

			ligne.copy((ci4 + 2 + 8 - t4), t4, 2 + t1 + t2 + t3);
			ci4[0] = '0';
			ci4[1] = 'x';
			for (int i = 0; i < 8 - t4; i++) {
				ci4[2 + i] = '0';
			}
			ci4[10] = '\0';
			ss4 << std::hex << ci4;
			ss4 >> i4;

			Clef * c = new Clef(i1, i2, i3, i4);
			tab.push_back(*c);
			cout << *c << endl;
		}
		fichier.close();
		TasMinTab * tasMinTab = new TasMinTab();
		tasMinTab->constIter(tab);
		//std::cout << *tasMinTab << endl;
	} else {
		cout << "Erreur de lecture" << endl;
	}
	return 0;
}

