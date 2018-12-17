/*
 * md5.cpp
 *
 *  Created on: 11 déc. 2018
 *      Author: yannickli
 */

#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>

using namespace std;

string little_endian32(string s) {
	string res = "";

	return res;
}

string little_endian64(string s) {
	string res = "";

	return res;
}

int my_md5(string message) {
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

	message.push_back(1);
	int taille = 448 - (message.size() % 512);
	if (taille < 0)
		taille += 512;
	for (int i = 0; i < taille; i++)
		message.push_back(0);

	vector<int> vect;

	return 0;
}

int _main() {
	my_md5("test");
	return 0;
}
