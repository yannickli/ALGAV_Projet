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
#include <cstring>

using namespace std;

// Fonctionne meme si la cle n'est pas de 128 bits
TasMinArbre *lireFichierArbre(string file) {
	ifstream fichier(file, ios::in);
	if (fichier) {
		string ligne;
		vector<Clef*> tab;
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
			tab.push_back(c);
		}
		fichier.close();
		TasMinArbre * tas = new TasMinArbre();
		tas->constIter(&tab);
		return tas;
	} else {
		perror("Erreur de lecture Arbre");
		exit(4);
	}
	return nullptr;
}

TasMinTab *lireFichierTab(string file) {
	ifstream fichier(file, ios::in);
	if (fichier) {
		string ligne;
		vector<Clef*> tab;
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
			tab.push_back(c);
			//cout << *c << endl;
		}
		fichier.close();
		TasMinTab * tas = new TasMinTab();
		tas->constIter(tab);
		return tas;
	} else {
		perror("Erreur de lecture Tab");
		exit(5);
	}
	return nullptr;
}

int main() {
	TasMinArbre *t1 = lireFichierArbre("cles_alea/jeu_1_nb_cles_100.txt");
	t1->supprMin();
	t1->supprMin();
	t1->ajout(new Noeud(new Clef(3999999999, 0, 0, 0)));
	t1->supprMin();
	t1->afficher();

	TasMinArbre *t2 = lireFichierArbre("cles_alea/jeu_1_nb_cles_1000.txt");
	cout << "Erreur incomming" << endl;
	t2->supprMin();
	cout << "Pas d'erreur" << endl;
	t2->supprMin();
	t2->ajout(new Noeud(new Clef(3999999999, 4, 0, 1)));
	t2->supprMin();
	t2->afficher();
	cout << t2->tester() << endl;

	TasMinArbre *t3 = union2Arbre(t1, t2);
	t3->supprMin();
	t3->supprMin();
	t3->ajout(new Noeud(new Clef(3999999999, 5, 0, 2)));
	t3->supprMin();
	t3->afficher();
	cout << t3->tester() << endl;
	return 0;

}

