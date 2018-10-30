/*
 * Clef.cpp
 *
 *  Created on: 29 oct. 2018
 *      Author: 3305496
 */

#include "Clef.h"

using namespace std;

ostream& operator<<(ostream& os, const Clef& c) {
	os << c.i1 << "." << c.i2 << "." << c.i3 << "." << c.i4;
	return os;
}
