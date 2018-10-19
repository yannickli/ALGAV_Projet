/*
 * Clef.h
 *
 *  Created on: 15 oct. 2018
 *      Author: 3305496
 */

#ifndef CLEF_H_
#define CLEF_H_

class Clef {
private:
	int i1;
	int i2;
	int i3;
	int i4;
public:
	Clef::Clef(int a, int b, int c, int d) :
			i1(a), i2(b), i3(c), i4(d) {

	}
};

bool compare_Clef(const Clef a, const Clef b) const {
	if (a.i1 != b.i1)
		return a.i1 < b.i1;
	if (a.i2 != b.i2)
		return a.i2 < b.i2;
	if (a.i3 != b.i3)
		return a.i3 < b.i3;
	return a.i4 < b.i4;
}

#endif /* CLEF_H_ */
