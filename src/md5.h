/*
 * md5.h
 *
 *  Created on: 10 déc. 2018
 *      Author: yannickli
 */

#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>

#include "Clef.h"

using namespace std;

string md5(string message) {
	//Note : Toutes les variables sont sur 32 bits

	//Définir r
	unsigned int k[64];
	unsigned int r[64] = { 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12,
			17, 22, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 4,
			11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 6, 10, 15,
			21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21 };

	//MD5 utilise des sinus d'entiers pour ses constantes :
	for (int i = 0; i < 64; i++) {
		k[i] = (unsigned int) (abs(sin(i + 1)) * pow(2, 32));
	}

	//Préparation des variables :
	unsigned int h0 = 0x67452301;
	unsigned int h1 = 0xEFCDAB89;
	unsigned int h2 = 0x98BADCFE;
	unsigned int h3 = 0x10325476;

	//Préparation du message (padding) :
	unsigned char *res = NULL;

	//ajouter le bit "0" jusqu'à ce que la taille du message en bits soit égale à 448 (mod 512)
	int resTaille = message.length() * 8 + 1;
	while (resTaille % 512 != 448)
		resTaille++;
	resTaille /= 8;
	int lim = resTaille / 64;
	res = (unsigned char*) calloc(resTaille + 8, 1);
	memcpy(res, message.c_str(), message.length());

	//ajouter le bit "1" au message
	res[message.length()] = (unsigned char) 0x80;

	unsigned int messagetaillebit = 8 * message.length();

	//ajouter la taille du message initial(avant le padding) codée en 64-bit little-endian au message
	memcpy(res + resTaille, &messagetaillebit, 4);
	//Découpage en blocs de 512 bits :
	int i;
	for (i = 0; i <= lim; i++) {
		//subdiviser en 16 mots de 32 bits en little-endian w[i], 0 ≤ i ≤ 15
		unsigned int *w = (unsigned int *) (res + i * 64);

		//initialiser les valeurs de hachage :
		unsigned int a = h0;
		unsigned int b = h1;
		unsigned int c = h2;
		unsigned int d = h3;

		//Boucle principale :
		unsigned int f = 0, g = 0;
		for (int i = 0; i < 64; i++) {
			if (0 <= i and i <= 15) {
				f = ((b & c) | ((~b) & d));
				g = i;
			} else if (16 <= i and i <= 31) {
				f = ((d & b) | ((~d) & c));
				g = (5 * i + 1) % 16;
			} else if (32 <= i and i <= 47) {
				f = (b ^ c ^ d);
				g = (3 * i + 5) % 16;
			} else if (48 <= i and i <= 64) {
				f = (c ^ (b | (~d)));
				g = (7 * i) % 16;
			}

			unsigned tmp = d;
			d = c;
			c = b;
			b = (((a + f + k[i] + w[g]) << r[i])
					| ((a + f + k[i] + w[g]) >> (32 - r[i]))) + b;
			a = tmp;
		}

		//ajouter le résultat au bloc précédent :
		h0 = h0 + a;
		h1 = h1 + b;
		h2 = h2 + c;
		h3 = h3 + d;
	}

	unsigned int * empreinte = (unsigned int *) malloc(16);
	empreinte[0] = h0;
	empreinte[1] = h1;
	empreinte[2] = h2;
	empreinte[3] = h3;

	string retour;
	for (i = 0; i < 4; i++) {
		char c[9];
		unsigned char *e;
		e = (unsigned char *) &empreinte[i];
		sprintf(c, "%02x%02x%02x%02x", e[0], e[1], e[2], e[3]);
		retour += c;
	}
	return retour;
}
