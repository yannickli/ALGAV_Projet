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
#include "FileB.h"
#include "TournoiB.h"
#include "ABR.h"

using namespace std;

// Fonctionne meme si la cle n'est pas de 128 bits
vector<Clef*> *lireFichier(string file) {
	ifstream fichier(file, ios::in);
	if (fichier) {
		string ligne;
		vector<Clef*> *tab = new vector<Clef*>();
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
			tab->push_back(c);
		}
		fichier.close();
		return tab;
	} else {
		perror("Erreur de lecture Arbre");
		exit(4);
	}
	return nullptr;
}

void complexiteConsIterArbre() {
	string nom[8] = { "100", "200", "500", "1000", "5000", "10000", "20000",
			"50000" };
	for (string s1 : nom) {
		double cpt = 0;
		for (int i = 1; i <= 5; i++) {
			string s = "cles_alea/jeu_" + to_string(i) + "_nb_cles_" + s1
					+ ".txt";
			vector<Clef*> *tab = lireFichier(s);
			TasMinArbre * tas = new TasMinArbre();
			clock_t tStart = clock();
			tas->consIterArbre(tab);
			cpt += ((double) (clock() - tStart) / CLOCKS_PER_SEC);
			if (!tas->tester()) {
				perror("Probleme ConsIter Arbre");
				exit(100);
			}
		}
		cout << "Taille : " << s1 << " ; Temps : " << cpt / 5 << endl;
	}
}

void complexiteConsIterTab() {
	string nom[8] = { "100", "200", "500", "1000", "5000", "10000", "20000",
			"50000" };

	for (string s1 : nom) {
		double cpt = 0;
		for (int i = 1; i <= 5; i++) {
			string s = "cles_alea/jeu_" + to_string(i) + "_nb_cles_" + s1
					+ ".txt";
			vector<Clef*> *tab = lireFichier(s);
			TasMinTab * tas = new TasMinTab();
			clock_t tStart = clock();
			tas->consIterTab(tab);
			cpt += ((double) (clock() - tStart) / CLOCKS_PER_SEC);
			if (!tas->tester()) {
				perror("Probleme ConsIter Tab");
				exit(101);
			}
		}
		cout << "Taille : " << s1 << " ; Temps : " << cpt / 5 << endl;
	}
}

void complexiteUnionArbre() {
	string nom[8] = { "100", "200", "500", "1000", "5000", "10000", "20000",
			"50000" };

	for (string s1 : nom) {
		TasMinArbre *tas1 = new TasMinArbre();
		tas1->consIterArbre(
				lireFichier("cles_alea/jeu_1_nb_cles_" + s1 + ".txt"));
		TasMinArbre *tas2 = new TasMinArbre();
		tas2->consIterArbre(
				lireFichier("cles_alea/jeu_2_nb_cles_" + s1 + ".txt"));
		TasMinArbre *tas3 = new TasMinArbre();
		tas3->consIterArbre(
				lireFichier("cles_alea/jeu_3_nb_cles_" + s1 + ".txt"));
		TasMinArbre *tas4 = new TasMinArbre();
		tas4->consIterArbre(
				lireFichier("cles_alea/jeu_4_nb_cles_" + s1 + ".txt"));
		TasMinArbre *tas5 = new TasMinArbre();
		tas5->consIterArbre(
				lireFichier("cles_alea/jeu_5_nb_cles_" + s1 + ".txt"));

		clock_t tStart = clock();
		TasMinArbre *res = union2Arbre(tas1, tas2);
		res = union2Arbre(res, tas3);
		res = union2Arbre(res, tas4);
		res = union2Arbre(res, tas5);
		cout << "Taille : " << s1 << " ; Temps : "
				<< ((double) (clock() - tStart) / CLOCKS_PER_SEC) / 4 << endl;
		if (!res->tester()) {
			perror("Probleme Union Arbre");
			exit(102);
		}
	}
}

void complexiteUnionTab() {
	string nom[8] = { "100", "200", "500", "1000", "5000", "10000", "20000",
			"50000" };

	for (string s1 : nom) {
		TasMinTab *tas1 = new TasMinTab();
		tas1->consIterTab(
				lireFichier("cles_alea/jeu_1_nb_cles_" + s1 + ".txt"));
		TasMinTab *tas2 = new TasMinTab();
		tas2->consIterTab(
				lireFichier("cles_alea/jeu_2_nb_cles_" + s1 + ".txt"));
		TasMinTab *tas3 = new TasMinTab();
		tas3->consIterTab(
				lireFichier("cles_alea/jeu_3_nb_cles_" + s1 + ".txt"));
		TasMinTab *tas4 = new TasMinTab();
		tas4->consIterTab(
				lireFichier("cles_alea/jeu_4_nb_cles_" + s1 + ".txt"));
		TasMinTab *tas5 = new TasMinTab();
		tas5->consIterTab(
				lireFichier("cles_alea/jeu_5_nb_cles_" + s1 + ".txt"));

		clock_t tStart = clock();
		TasMinTab *res = union2Tab(*tas1, *tas2);
		res = union2Tab(*res, *tas3);
		res = union2Tab(*res, *tas4);
		res = union2Tab(*res, *tas5);
		cout << "Taille : " << s1 << " ; Temps : "
				<< ((double) (clock() - tStart) / CLOCKS_PER_SEC) / 4 << endl;
		if (!res->tester()) {
			perror("Probleme Union Tab");
			exit(103);
		}
	}
}

void complexiteSupprMinArbre() {
	string nom[8] = { "100", "200", "500", "1000", "5000", "10000", "20000",
			"50000" };
	clock_t tStart;
	for (string s1 : nom) {
		double cpt = 0;
		for (int i = 1; i <= 5; i++) {
			string s = "cles_alea/jeu_" + to_string(i) + "_nb_cles_" + s1
					+ ".txt";
			vector<Clef*> *tab = lireFichier(s);

			TasMinArbre * tas = new TasMinArbre();
			tas->consIterArbre(tab);
			if (!tas->tester()) {
				perror("Probleme ConsIter Arbre");
				exit(100);
			}

			tStart = clock();
			for (int i = 0; i < stoi(s1); i++) {
				tas->supprMin();
			}
			cpt += ((double) (clock() - tStart) / CLOCKS_PER_SEC) / stoi(s1);
		}
		cout << "Taille : " << s1 << " ; Temps : " << cpt / 5 << endl;
	}
}

void complexiteSupprMinTab() {
	string nom[8] = { "100", "200", "500", "1000", "5000", "10000", "20000",
			"50000" };
	clock_t tStart;
	for (string s1 : nom) {
		double cpt = 0;
		for (int i = 1; i <= 5; i++) {
			string s = "cles_alea/jeu_" + to_string(i) + "_nb_cles_" + s1
					+ ".txt";
			vector<Clef*> *tab = lireFichier(s);

			TasMinTab * tas = new TasMinTab();
			tas->consIterTab(tab);
			if (!tas->tester()) {
				perror("Probleme ConsIter Arbre");
				exit(100);
			}

			tStart = clock();
			for (int i = 0; i < stoi(s1); i++) {
				tas->supprMin();
			}
			cpt += ((double) (clock() - tStart) / CLOCKS_PER_SEC) / stoi(s1);
		}
		cout << "Taille : " << s1 << " ; Temps : " << cpt / 5 << endl;
	}
}

void complexiteAjoutArbre() {
	string nom[8] = { "100", "200", "500", "1000", "5000", "10000", "20000",
			"50000" };
	clock_t tStart;
	for (string s1 : nom) {
		double cpt = 0;
		for (int i = 1; i <= 5; i++) {
			string s = "cles_alea/jeu_" + to_string(i) + "_nb_cles_" + s1
					+ ".txt";
			vector<Clef*> *tab = lireFichier(s);

			TasMinArbre * tas = new TasMinArbre();

			tStart = clock();
			for (Clef *c : *tab) {
				tas->ajout(new Noeud(c));
			}
			cpt += ((double) (clock() - tStart) / CLOCKS_PER_SEC) / tab->size();
			if (!tas->tester()) {
				perror("Probleme ConsIter Arbre");
				exit(100);
			}
		}
		cout << "Taille : " << s1 << " ; Temps : " << cpt / 5 << endl;
	}
}

void complexiteAjoutTab() {
	string nom[8] = { "100", "200", "500", "1000", "5000", "10000", "20000",
			"50000" };
	clock_t tStart;
	for (string s1 : nom) {
		double cpt = 0;
		for (int i = 1; i <= 5; i++) {
			string s = "cles_alea/jeu_" + to_string(i) + "_nb_cles_" + s1
					+ ".txt";
			vector<Clef*> *tab = lireFichier(s);

			TasMinTab * tas = new TasMinTab();
			tStart = clock();
			for (Clef *c : *tab) {
				tas->ajout(c);
			}
			cpt += ((double) (clock() - tStart) / CLOCKS_PER_SEC) / tab->size();
			if (!tas->tester()) {
				perror("Probleme ConsIter Arbre");
				exit(100);
			}
		}
		cout << "Taille : " << s1 << " ; Temps : " << cpt / 5 << endl;
	}
}

void testComplexiteTas() {
	cout << "ConsIterArbre (moyenne des 5 jeux): " << endl;
	complexiteConsIterArbre();
	cout << "ConstIterTab (moyenne des 5 jeux):" << endl;
	complexiteConsIterTab();
	cout << "UnionArbre (moyenne des 4 union des 5 jeux):" << endl;
	complexiteUnionArbre();
	cout << "UnionTab (moyenne des 4 union des 5 jeux):" << endl;
	complexiteUnionTab();
	cout << "SupprMinArbre (1 operation): " << endl;
	complexiteSupprMinArbre();
	cout << "SupprMinTab (1 operation):" << endl;
	complexiteSupprMinTab();
	cout << "AjoutArbre (1 operation): " << endl;
	complexiteAjoutArbre();
	cout << "AjoutTab (1 operation):" << endl;
	complexiteAjoutTab();
}

void complexiteConsIterFileB() {
	string nom[8] = { "100", "200", "500", "1000", "5000", "10000", "20000",
			"50000" };
	for (string s1 : nom) {
		double cpt = 0;
		for (int i = 1; i <= 5; i++) {
			string s = "cles_alea/jeu_" + to_string(i) + "_nb_cles_" + s1
					+ ".txt";
			vector<Clef*> *vec = lireFichier(s);
			clock_t tStart = clock();
			FileB * fb = consIterFileB(vec);
			cpt += ((double) (clock() - tStart) / CLOCKS_PER_SEC);
		}
		cout << "Taille : " << s1 << " ; Temps : " << cpt / 5 << endl;
	}
}

void complexiteUnionFileB() {
	string nom[8] = { "100", "200", "500", "1000", "5000", "10000", "20000",
			"50000" };
	for (string s1 : nom) {
		FileB *fb1 = consIterFileB(
				lireFichier("cles_alea/jeu_1_nb_cles_" + s1 + ".txt"));
		FileB *fb2 = consIterFileB(
				lireFichier("cles_alea/jeu_2_nb_cles_" + s1 + ".txt"));
		FileB *fb3 = consIterFileB(
				lireFichier("cles_alea/jeu_3_nb_cles_" + s1 + ".txt"));
		FileB *fb4 = consIterFileB(
				lireFichier("cles_alea/jeu_4_nb_cles_" + s1 + ".txt"));
		FileB *fb5 = consIterFileB(
				lireFichier("cles_alea/jeu_5_nb_cles_" + s1 + ".txt"));

		clock_t tStart = clock();
		FileB *res = unionFile(fb1, fb2);
		res = unionFile(res, fb3);
		res = unionFile(res, fb4);
		res = unionFile(res, fb5);
		cout << "Taille : " << s1 << " ; Temps : "
				<< ((double) (clock() - tStart) / CLOCKS_PER_SEC) / 4 << endl;
	}
}

void complexiteSupprMinFileB() {
	string nom[8] = { "100", "200", "500", "1000", "5000", "10000", "20000",
			"50000" };
	clock_t tStart;
	for (string s1 : nom) {
		double cpt = 0;
		for (int i = 1; i <= 5; i++) {
			string s = "cles_alea/jeu_" + to_string(i) + "_nb_cles_" + s1
					+ ".txt";
			vector<Clef*> *vec = lireFichier(s);

			FileB* fb = consIterFileB(vec);

			tStart = clock();
			for (int i = 0; i < stoi(s1); i++) {
				fb = supprMin(fb);
			}
			cpt += ((double) (clock() - tStart) / CLOCKS_PER_SEC) / stoi(s1);
		}
		cout << "Taille : " << s1 << " ; Temps : " << cpt / 5 << endl;
	}
}

void complexiteAjoutFileB() {
	string nom[8] = { "100", "200", "500", "1000", "5000", "10000", "20000",
			"50000" };
	clock_t tStart;
	for (string s1 : nom) {
		double cpt = 0;
		for (int i = 1; i <= 5; i++) {
			string s = "cles_alea/jeu_" + to_string(i) + "_nb_cles_" + s1
					+ ".txt";
			vector<Clef*> *tab = lireFichier(s);

			FileB*fb = new FileB();
			tStart = clock();
			for (Clef *c : *tab) {
				fb = ajout(fb, c);
			}
			cpt += ((double) (clock() - tStart) / CLOCKS_PER_SEC) / tab->size();
		}
		cout << "Taille : " << s1 << " ; Temps : " << cpt / 5 << endl;
	}
}

void testComplexiteFileB() {
	cout << "ConsIterFileB (moyenne des 5 jeux): " << endl;
	complexiteConsIterFileB();
	cout << "UnionFileB (moyenne des 4 union des 5 jeux):" << endl;
	complexiteUnionFileB();
	cout << "SupprMinFileB (1 operation): " << endl;
	complexiteSupprMinFileB();
	cout << "AjoutFileB (1 operation):" << endl;
	complexiteAjoutFileB();
}

vector<string> *lireFichierShakespeare(string file) {
	ifstream fichier(file, ios::in);
	if (fichier) {
		string ligne;
		vector<string> *res = new vector<string>();
		while (getline(fichier, ligne)) {
			res->push_back(ligne);
		}
		fichier.close();
		return res;
	} else {
		perror("Erreur de lecture Shakespeare");
		exit(5);
	}
	return nullptr;
}

void testStructureABR() {
	list<string> *occurences = new list<string>();
	ABR * res = consIterABR(lireFichierShakespeare("Shakespeare/toto"),
			occurences);
	//afficher(res);
	cout << "Liste des mots : " << endl;
	for (string s : *occurences)
		cout << s << endl;
	cout << "Nb mots : " << occurences->size() << endl;
}

int main() {
	testComplexiteTas();
	testComplexiteFileB();
	/*cout << "Test de MD5 : " << endl;
	testMD5();
	cout << "Test de la structure ABR : " << endl;
	testStructureABR();*/
	return 0;
}

