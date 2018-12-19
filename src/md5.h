/*
 * md5.h
 *
 *  Created on: 11 déc. 2018
 *      Author: yannickli
 */

#ifndef SRC_MD5_H_
#define SRC_MD5_H_

#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>

std::string little_endian32(std::string s) {
	std::string res = "";

	std::cout << "taille : " << sizeof(int) << std::endl;

	return s;
}

std::string little_endian64(std::string s) {
	std::string res = "";

	return res;
}

int my_md5(std::string message) {
	int k[64];
	int r[64] = { 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 5,
			9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 4, 11, 16, 23,
			4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 6, 10, 15, 21, 6, 10,
			15, 21, 6, 10, 15, 21, 6, 10, 15, 21 };

	for (int i = 0; i < 64; i++) {
		k[i] = floor(abs(sin(i + 1)) * pow(2, 32));
	}

	int h0 = 0x67452301;
	int h1 = 0xEFCDAB89;
	int h2 = 0x98BADCFE;
	int h3 = 0x10325476;

	std::cout << message << std::endl;
	message.push_back('1');
	std::cout << message << std::endl;
	int taille = 448 - (message.size() % 512);
	if (taille < 0)
		taille += 512;
	for (int i = 0; i < taille; i++)
		message.push_back('0');
	std::cout << message << std::endl;
	std::cout << message.size() << std::endl;
	std::vector<int> vect;

	return 0;
}

int testMd5() {
	my_md5("test");
	std::string s1 = "String De Test Pour Le Projet 32";
	std::cout << s1.size() << " : " << s1 << std::endl;
	std::string s2 = little_endian32(s1);
	std::cout << "Apres Little : " << s2 << std::endl;
	return 0;
}

#endif /* SRC_MD5_H_ */
