/*
 * AVL.h
 *
 *  Created on: 19 déc. 2018
 *      Author: yannickli
 */

#ifndef SRC_AVL_H_
#define SRC_AVL_H_

#include "ABR.h"
#include "Clef.h"

class AVL {
	ABR* arbre;
public:
	AVL();

	AVL(ABR* A);

	void rotationD();

	void rotationG();

	void rotationDG();

	void rotationGD();

	friend int hauteur(AVL*A);

	friend ABR * equilibrage(AVL*A);

	friend ABR * avl_Ajout(Clef *x, ABR *A);


};

int hauteur(AVL*A);

ABR * equilibrage(AVL*A);

ABR * avl_Ajout(Clef *x, ABR *A);

#endif /* SRC_AVL_H_ */
