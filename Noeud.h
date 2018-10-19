/*
 * Noeud.h
 *
 *  Created on: 13 oct. 2018
 *      Author: 3520328
 */

#ifndef NOEUD_H_
#define NOEUD_H_
#include "Clef.h"

class Noeud{
private:
	//bool rempli;
	Clef clef;
	Noeud filsG;
	Noeud filsD;

public:
	Noeud(Clef clef, Noeud filsG, Noeud filsD);
	bool getRempli();
	unsigned int getI1();
	unsigned int getI2();
	unsigned int getI3();
	unsigned int getI4();
	SupprMin(Noeud n);

};

bool inf(Noeud a1, Noeud a2);



#endif /* NOEUD_H_ */
