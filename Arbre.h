/*
 * Arbre.h
 *
 *  Created on: 12 oct. 2018
 *      Author: 3520328
 */

#ifndef ARBRE_H_
#define ARBRE_H_

class Arbre{
private:
	Clef clef;
	Noeud racine;

	//friend void SupprMin(Arbre a);
public:
	Arbre(Clef clef, Noeud n);
	int nbElem;
	unsigned int getI1();
	unsigned int getI2();
	unsigned int getI3();
	unsigned int getI4();
	bool eg(Arbre a1, Arbre a2);
	bool inf(Arbre a1, Arbre a2);
	void SupprMin(Arbre a);

};




#endif /* ARBRE_H_ */
