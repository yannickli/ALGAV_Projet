/*
 * TasMinTab.cpp
 *
 *  Created on: 29 oct. 2018
 *      Author: 3305496
 */

#ifndef SRC_TASMINTAB_CPP_
#define SRC_TASMINTAB_CPP_

#include "TasMinTab.h"

using namespace std;

ostream& operator<<(ostream& os, const TasMinTab& t) {
	for (Clef it : t.tab) {
		os << it << endl;
	}
	return os;
}

#endif /* SRC_TASMINTAB_CPP_ */
